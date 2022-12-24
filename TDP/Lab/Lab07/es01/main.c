#include <stdio.h>


#define  MAX_R 50
#define MAX_C 50

typedef struct  {
    int x,y,base, altezza, area;
}area_s;

void leggiMatrice(int mat[MAX_R][MAX_C], int maxR, int *nrp, int *ncp);
void stampaMappa(int mappa[MAX_R][MAX_C],int nr,int nc);
void trovaAree(int mappa[MAX_R][MAX_C],int nr, int nc,area_s elencoAree[MAX_R*MAX_C]);
void stampaAreeMax(area_s altezzaMax, area_s baseMax, area_s areaMax);
void trovaMax(area_s elencoAree[MAX_R*MAX_C], int countAree);

int main() {

    int mappa[MAX_R][MAX_C],nr,nc;
    area_s elencoAree[MAX_R*MAX_C];

    leggiMatrice(mappa,MAX_R,&nr,&nc);
    stampaMappa(mappa,nr,nc);
    trovaAree(mappa,nr,nc,elencoAree);
}

void leggiMatrice(int mat[MAX_R][MAX_C], int maxR, int *nrp, int *ncp){
    FILE *fin;
    if((fin = fopen("../mappa.txt","r"))==NULL){
        printf("Error opening file...");
    }
    else {
        fscanf(fin, "%d %d", nrp, ncp);
        for (int i = 0; i < *nrp; ++i) {
            for (int j = 0; j < *ncp; ++j) {
                fscanf(fin, "%d", &mat[i][j]);
            }
        }
        fclose(fin);
    }
}


void trovaAree(int mappa[MAX_R][MAX_C],int nr, int nc, area_s elencoAree[MAX_R*MAX_C]){
    int countAree=0,x,y,m,termina;

    for (int i=0; i<nr; i++) {
        for (int j=0; j<nc; j++) {
            if (mappa[i][j]==1) {
                termina =0;
                for (y=i; y<nr && !termina; y++) {
                    m=j;
                    for (x=j; x<nc; x++) {
                        if ((mappa[y][x]==0 && mappa[y+1][m]==0 )|| (y== nr-1 && x == nc-1)) {
                            termina=1;
                            mappa[y][x]=0;
                            break;
                        }
                        if (mappa[y][x]==1) {
                            if (y==i) {
                                elencoAree[countAree].base++;
                            }
                            mappa[y][x]=0;
                        }
                    }
                    elencoAree[countAree].altezza++;
                }
                elencoAree[countAree].x=i;
                elencoAree[countAree].y=j;
                elencoAree[countAree].area=(elencoAree[countAree].base)*(elencoAree[countAree].altezza);
                countAree++;
            }
        }
    }
    trovaMax(elencoAree, countAree);
}
void stampaMappa(int mappa[MAX_R][MAX_C],int nr,int nc){
    for(int i=0; i<nr; i++){
        for(int j=0; j < nc; j++){
            printf("%d ",mappa[i][j]);
        }
        printf("\n");
    }
}

void trovaMax(area_s elencoAree[MAX_C*MAX_R],int countAree){
    int iMaxBase, iMaxAlt, iMaxArea,h=0,b=0,a=0;

    for(int i=0; i< countAree; i++){
        if(elencoAree[i].altezza>h){
            h=elencoAree[i].altezza;
            iMaxAlt = i;
        }
        if(elencoAree[i].base > b){
            b = elencoAree[i].base;
            iMaxBase =i;
        }
        if(elencoAree[i].area > a){
            a = elencoAree[i].area;
            iMaxArea =i;
        }
    }
    stampaAreeMax(elencoAree[iMaxAlt], elencoAree[iMaxBase],elencoAree[iMaxArea]);
}
void stampaAreeMax(area_s altezzaMax, area_s baseMax, area_s areaMax){
    printf("Max Base: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n",baseMax.x,baseMax.y,baseMax.base,baseMax.altezza,baseMax.area);
    printf("Max Area: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n",areaMax.x,areaMax.y,areaMax.base, areaMax.altezza,areaMax.area);
    printf("Max Altezza: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d",altezzaMax.x,altezzaMax.y,altezzaMax.base, altezzaMax.altezza,altezzaMax.area);

}


/*#include <stdio.h>

#define MAX_VAL 50
#define MAX_REG 25
typedef struct{
    int sx1;
    int sx2;
    int b;
    int h;
    float area;
}regione;
typedef struct{
    int sx1;
    int sx2;
}posizione;
void leggiFile(FILE  *fp,int matrice[MAX_VAL][MAX_VAL],int nr, int nc);
void individuaRegioni(regione reg[MAX_REG], posizione pos[MAX_REG], int matrice[MAX_VAL][MAX_VAL],int nr,int nc);
int main() {
    int matrice[MAX_VAL][MAX_VAL],nr,nc;
    FILE *fp;
    regione reg[MAX_REG];
    posizione pos[MAX_REG];
    if((fp=fopen("../mappa.txt","r"))==NULL){
        printf("error opening file");
        return 1;
    }
    fscanf(fp, "%d %d", &nr, &nc);
    leggiFile(fp,matrice,nr,nc);
    fclose(fp);
    individuaRegioni(reg,pos,matrice,nr,nc);
    return 0;
}

void leggiFile(FILE *fp,int matrice[MAX_VAL][MAX_VAL],int nr, int nc){
    for(int i=0;i<nr;i++){
        for(int j=0;j<nc;j++){
            fscanf(fp, "%d",&matrice[i][j]);
        }
    }
}

void individuaRegioni(regione reg[MAX_REG],posizione pos[MAX_REG],int matrice[MAX_VAL][MAX_VAL],int nr,int nc){
    int k=0,f=0;
    int valPrec=-1,valprecf=-1,flag=0;
    for(int i=0;i<nr;i++){
        for(int j=0;j<nc;j++){
            if(matrice[i][j]==1){
                pos[k].sx1=i;
                pos[k].sx2=j;
                k++;
            }
        }
    }
    for(int i=0;i<k;i++){
        reg[i].sx1=pos[i].sx1;
        reg[i].sx2=pos[i].sx2;
        reg[i].b=1;
        reg[i].h=1;
        reg[i].area=1;
    }
    for(int i=0;i<k;i++){
        for(int j=i+1;j<k;j++){
            if(pos[i].sx1==pos[j].sx1 && pos[j].sx2-pos[i].sx2==1){
                reg[f].b+=1;
            }
            else if(pos[i].sx2==pos[j].sx2 && pos[j].sx1-pos[i].sx1==1){
                reg[f].h+=1;
            }
        }
        reg[f].area=(float)reg[f].b*(float)reg[f].h;
        f++;
    }
    int maxB=0,maxH=0,maxA=0,indiceH=0,indiceB=0,indiceA=0;
    for(int i=0;i<f;i++){
        if(reg[i].h>=maxH){
            maxH=reg[i].h;
            indiceH=i;
        }
        if(reg[i].b>=maxB){
            maxB=reg[i].b;
            indiceB=i;
        }
        if(reg[i].area>=(float)maxA){
            maxA=(int)reg[i].area;
            indiceA=i;
        }
        printf("estr.sup <%d,%d>, b=%d, h=%d, Area=%f\n", reg[i].sx1, reg[i].sx2, reg[i].b, reg[i].h, reg[i].area);
    }
    printf("\n");
    printf("Max Base: estr. sup. SX = <%d,%d> b= %d, h= %d, Area= %f\n", reg[indiceB].sx1,reg[indiceB].sx2,reg[indiceB].b, reg[indiceB].h, reg[indiceB].area);
    printf("Max Area: estr. sup. SX = <%d,%d> b= %d, h= %d, Area= %f\n", reg[indiceA].sx1,reg[indiceA].sx2,reg[indiceA].b, reg[indiceA].h, reg[indiceA].area);
    printf("Max Altezza: estr. sup. SX = <%d,%d> b= %d, h= %d, Area= %f", reg[indiceH].sx1,reg[indiceH].sx2,reg[indiceH].b, reg[indiceH].h, reg[indiceH].area);
}
*/

