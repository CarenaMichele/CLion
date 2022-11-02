#include <stdio.h>
#include <ctype.h>
#include <math.h>
void eseVettori();
void insVettori(int vet[]);
void studioIntersezione(int vet1[], int vet2[]);
void suddivisioneClassi();
void suddivisione(int vet[],int conta[], int num);
void intToBit();
int main() {
    int es;
    printf("che esercizio vuoi eseguire?==>");
    scanf("%d", &es);
    switch(es){
        case 1:
            eseVettori();
            break;
        case 2:
            suddivisioneClassi();
            break;
        case 3:
            intToBit();
            break;
        default:
            printf("questo esercizio non e' presente!");
            break;
    }

}

void eseVettori(){
    int vet1[10], vet2[10], v1[10], v2[10],vetInt[10];
    insVettori(vet1);
    insVettori(vet2);
    for(int i = 0; i < 10; i++){ //stampa
        printf("vettore[%d] = %d \n",i, vet1[i]);
    }
    printf("\n\n\n");
    for(int i = 0; i < 10; i++){ //stampa
        printf("vettore[%d] = %d \n",i, vet2[i]);
    }
    studioIntersezione(vet1,vet2);
}

void insVettori(int vet[]){
    for (int i=0;i<10;i++){
        printf("inserisci il %d valore==>", (i+1));
        scanf("%d",&vet[i]);
    }
}

void studioIntersezione(int vet1[], int vet2[]){
    int vetInt[10];
    typedef int number;
    number k=0;
    for(int i=0;i<10;i++) {
        for (int j = 0; j < 10; j++) {
            if (vet1[i] == vet2[j]) {
                printf("questo numero %d e' presente in tutti e 2 i vettori\n");
                vetInt[k] = vet1[i];
                k++;
            }
        }
    }
    printf("\n\n");
    for(int i=0;i<k;i++){
        printf("valore intersezione %d\n", vetInt[i]);
    }
}

void suddivisioneClassi(){
    int num;
    printf("quanti valori vuoi inserire?==> ");
    scanf("%d",&num);
    int vet[num];
    int conta[11];
    for(int i=0;i<num;i++){
        printf("inserisci valori compresi tra %d e %d==>", 0, 100);
        scanf("%d", &vet[i]);
    }
    for(int i=0;i<num;i++){
        printf("%d\t\t", vet[i]);
    }
    printf("\n\n");
    for(int i=0;i<11;i++){
        conta[i]=0;
    }
    suddivisione(vet,conta,num);
}

void suddivisione(int vet[],int conta[], int num){
    int val;
    for(int i=0; i<num;i++){
        val= vet[i]/10;
        conta[val]=conta[val]+1;
    }

    for(int i=0; i<11;i++){
        printf ("%d dati in decina %d \n",conta[i], i+1);
    }
}

void intToBit(){
    int val;
    int dim=50;
    int vet[dim];
    int i=0;
    printf("inserisci un valore compreso tra %d e %d==> ", 0, (pow(2,32))-1);
    scanf("%d", &val);
    while(val!=0){
        if(val%2==0){
            vet[i]=0;
            val=val/2;
            i++;
        }
        else{
            vet[i]=1;
            val=val/2;
            i++;
        }
    }
    for(int j=i;j-- >0; ){
        printf("%d",vet[j]);
    }
}