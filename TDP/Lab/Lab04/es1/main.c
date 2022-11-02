#include <stdio.h>
#define MAX 30
void stampa(int i, int i2, int vet[]);
void sottoSequenze(int V[], int N);
int main() {
    int N, vet[N], j=0;
    printf("quanto deve essere lungo il vettore? (<=%d) ==> ", MAX);
    scanf("%d",&N);
    if(N>30){
        printf("errore! La lunghezza inserita non è valida!");
        return 1;
    }
    else{
        while(j<N){
            printf("Inserisci valore %d del vettore ==>", j+1);
            scanf("%d",&vet[j]);
            j++;
        }
    }
    sottoSequenze(vet, N);
}
void sottoSequenze(int vet[], int N){
    int max=0, lung=0,f=0,cont=0;
    for(int i=0;i<N;i++){
        if(vet[i]!=0){
            lung++;
        }
        else{
            if(max<lung){
                max=lung;
            }
            lung=0;
        }
    }
    while(f<=N){
        for(int k=f;k<=f+max-1;k++){
            if(vet[k]!=0){
                cont++;
                if(cont==max){
                    stampa(f,f+max-1,vet);
                }
            }
        }
        cont=0;
        f++;
    }
}
void stampa(int i, int i2, int vet[]){
    for(int j=i;j<=i2;j++){
        if(j==i){
            printf("[");
        }
        printf("%d", vet[j]);
        if(j==i2){
            printf("]");
        }
    }
    printf("\n");
}