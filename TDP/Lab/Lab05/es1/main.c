#include <stdio.h>

int main() {
    FILE *fin;
    int numSq,numPartite;
    if((fin=fopen("../mat.txt","r"))==NULL){
        printf("error opening file\n");
    }
    fscanf(fin,"%d%d",&numSq,&numPartite);
    int matrice[numSq][numPartite];
    for(int i=0;i<numSq;i++){
        for(int j=0;j<numPartite;j++){
            fscanf(fin,"%d",&matrice[i][j]);
        }
    }
    int somma[numSq],i,j, max=0,indice;
    for(i=0;i<numPartite;i++){
        for(j=0;j<numSq;j++){
            if(i==0){
                somma[j]=0;
            }
            printf("%d\t",matrice[j][i]);
            somma[j]+=matrice[j][i];
        }
        for(int k=0;k<j;k++){
            if(somma[k]>max){
                indice=k;
                max=somma[k];
            }
        }
        printf("capolista: %d con punteggio %d",indice+1, somma[indice]);
        printf("\n");
    }
    return 0;
}
