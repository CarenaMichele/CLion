#include <stdio.h>
#include <string.h>
#define MAX 20
void riempiFile(FILE *fin, int *nR , int *nC);
int min(int nR, int nC);
void sottomatrici(int matrice[20][20], int dim, int row, int col);
int main() {
    FILE *fin;
    int dim, nR,nC, minimo, matrice[20][20],row,col;
    char nomeFile[MAX],pathCode[30]="../",filePrec[30];
    printf("nome file con all'interno la matrice? (max %d)", MAX);
    scanf("%s", nomeFile);
    //printf(filePrec);
    strcat(pathCode, nomeFile);
    strcat(pathCode,".txt");
    //printf(pathCode);
    //strcpy(filePrec, pathCode);
    //printf(filePrec);
    if((fin=fopen(pathCode,"w"))==NULL){
        printf("error opening file\n");
        return 1;
    }

    riempiFile(fin,&nR,&nC);
    minimo= min(nR,nC);
    fclose(fin);
    fin=fopen(pathCode,"r");
    fscanf(fin, "%d %d", &row, &col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            fscanf(fin,"%d",&matrice[i][j]);
        }
    }
    do{
        printf("inserisci la dimensione delle sottomatrici:");
        scanf("%d",&dim);
        if(dim>=1 && dim<=minimo){
            sottomatrici(matrice,dim,row,col);
        }
    }while(dim>=1 && dim<=minimo);
    fclose(fin);
    /*ret = remove(pathCode);
    if(ret == 0) {
        printf("File deleted successfully");
    } else {
        printf("Error: unable to delete the file");
    }*/
    return 0;
}

void riempiFile(FILE *fin, int *nR, int *nC){
    int values[]={3,4, 1, 2, 3 ,4, 5, 6, 7, 8, 9, 0, 1, 1};
    int size = sizeof values / sizeof values[0];
    for(int i=0;i<size;i++){
        if(i==0){
            *nR=values[i];
        }
        if(i==1){
            *nC=values[i];
        }
        if(i==2 || i==6 || i==10){
            fprintf(fin,"\n");
        }
        fprintf(fin,"%d ",values[i]);
    }
}

int min(int nR, int nC){
    if(nR<nC){
        return nR;
    }
    else{
        return nC;
    }
}
void sottomatrici(int matrice[20][20], int dim, int row, int col){
    int i=0,j=0,c=0,r=0,somma=0,max=0,contI=0,contJ=0;
    while(dim+r<=row){
        somma=0;
        for(i=r;i<dim+r;i++){
            for(j=c;j<dim+c;j++){
                printf("%d ", matrice[i][j]);
                somma+=matrice[i][j];
            }
            printf("\n");
        }
        if(somma>max){
            max=somma;
            contI=r;
            contJ=c;
        }
        if(dim+c==col){
            printf("\n");
            r++;
            c=0;
        }
        else{
            printf("\n\n");
            c++;
        }
    }
    printf("la sottomatrice con somma degli elementi massima(%d) e' ==> \n", max);
    for(i=contI;i<dim+contI;i++){
        for(j=contJ;j<dim+contJ;j++){
            printf("%d ",matrice[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
};
