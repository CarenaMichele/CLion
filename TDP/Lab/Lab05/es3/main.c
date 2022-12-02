#include <stdio.h>
#include <string.h>
#define MAX 30
void leggiMatrice(FILE *fin, int matrice[MAX][MAX], int nr, int nc);
void visualizzaMatrice(int matrice[MAX][MAX], int nr, int nc);
void ruotaMatrice(int matrice[MAX][MAX], char selettore[MAX], int indice, char direzione[MAX], int posizione, int nr, int nc);
int main() {
    FILE *fin;
    int nr=0, nc=0, matrice[MAX][MAX],i=0,j=0;
    if((fin=fopen("../mat.txt","r"))==NULL){
        printf("error opening file\n");
        return 1;
    }
    fscanf(fin, "%d %d", &nr, &nc);
    leggiMatrice(fin, matrice, nr,nc);
    visualizzaMatrice(matrice,nr,nc);
    char selettore[MAX], direzione[MAX];
    int indice=0, posizione=0;
    do{
        printf("inserisci selettore, indice, direzione e posizione =>");
        scanf("%s %d %s %d", selettore, &indice, direzione, &posizione);
        ruotaMatrice(matrice, selettore, indice, direzione, posizione, nr, nc);
        visualizzaMatrice(matrice,nr,nc);
    }while(strcmp(selettore, "fine")!=0);
    return 0;
}

void visualizzaMatrice(int matrice[MAX][MAX], int nr, int nc){
    for(int i=1;i<=nr;i++){
        for(int j=1;j<=nc;j++){
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");
    }
}

void leggiMatrice(FILE *fin, int matrice[MAX][MAX], int nr, int nc){
    for(int i=1;i<=nr;i++){
        for(int j=1;j<=nc;j++){
            fscanf(fin, "%d", &matrice[i][j]);
        }
    }
}

void ruotaMatrice(int matrice[MAX][MAX], char selettore[MAX], int indice, char direzione[MAX], int posizione, int nr, int nc){
    if(strcmp(selettore, "riga")==0){
        for(int i=1;i<=nr;i++){
            for(int j=1;j<=nc;j++){
                if(i==indice){
                    if(strcmp(direzione,"destra")==0){
                        for(int k=0;k<posizione;k++){
                            int temp =matrice[indice][nc];
                            for (int f = nc-1; f >=1; f--) {
                                matrice[indice][f+1]=matrice[indice][f];
                            }
                            matrice[indice][1]=temp;
                        }
                        break;
                    }
                    else if(strcmp(direzione,"sinistra")==0){
                        for(int k=0;k<posizione;k++){
                            int temp =matrice[indice][1];
                            for (int f = 2; f <=nc; f++) {
                                matrice[indice][f-1]=matrice[indice][f];
                            }
                            matrice[indice][nc]=temp;
                        }
                        break;
                    }
                }
            }
        }
    }
    else if(strcmp(selettore, "colonna")==0){
        for(int i=1;i<=nc;i++) {
            for (int j = 1; j <= nr; j++) {
                if(i==indice){
                    if(strcmp(direzione,"su")==0){
                        for(int k=0;k<posizione;k++){
                            int temp =matrice[1][indice];
                            for (int f = 2; f <=nr; f++) {
                                matrice[f-1][indice]=matrice[f][indice];
                            }
                            matrice[nr][indice]=temp;
                        }
                        break;
                    }
                    else if(strcmp(direzione,"giu")==0){
                        for(int k=0;k<posizione;k++){
                            int temp =matrice[nr][indice];
                            for (int f = nr-1; f >=1; f--) {
                                matrice[f+1][indice]=matrice[f][indice];
                            }
                            matrice[1][indice]=temp;
                        }
                        break;
                    }
                }
            }
        }
    }
}

