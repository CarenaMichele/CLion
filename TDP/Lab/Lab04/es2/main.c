#include <stdio.h>
#define MAX 30
void ruota(int vet[], int N, int P, int dir);
void stampa(int vet[], int N);
int main() {
    int N,i=0,P=0,dir=0, end=0;
    do{
        printf("quanti valori vuoi inserire nel vettore? (val max= %d)", MAX);
        scanf("%d", &N);
    }while(N<1 || N>MAX);
    int vet[N];
    do{
        printf("inserisci l'elemento %d ==>", i);
        scanf("%d",&vet[i]);
        i++;
    }while(i<N);

    do{
        printf("quante rotazioni e quale direzione? (-1: dx, 1:sx)");
        scanf("%d %d", &P, &dir);
        if (P == 0) {
            end = -1;
        }
        if (P <N && (dir == 1 || dir == -1)) {
            ruota(vet, N, P, dir);
            stampa(vet, N);
            printf("\n");
        } else
            printf("Input non valido.\n");
    }while(!end);
    return 0;
}

void ruota(int vet[], int N, int P, int dir){
    if(dir==-1){
        for(int j=0;j<P;j++){
            int temp =vet[N-1];
            for (int i = N-2; i >=0; i--) {
                vet[i+1]=vet[i];
            }
            vet[0]=temp;
        }
    }
    else{
        for(int j=0;j<P;j++){
            int temp =vet[0];
            for (int i = 1; i <=N; i++) {
                vet[i-1]=vet[i];
            }
            vet[N-1]=temp;
        }
    }
}
void stampa(int vet[],int N){
    for(int i=0;i<N;i++){
        printf("%d\t",vet[i]);
    }
}
