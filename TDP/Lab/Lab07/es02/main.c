#include <stdio.h>

#define MAX_LUNG 100
void leggiFile(FILE *fp,int numRighe);
void copiaVet(int vet[MAX_LUNG],int vet_copia[MAX_LUNG],int lungSelezione);
void selectionSort(int A[MAX_LUNG], int N);
void insertionSort(int A[MAX_LUNG], int N);
void shellSort(int A[MAX_LUNG], int N);
int main() {
    FILE *fp;
    int numRighe;
    if((fp=fopen("../sort.txt","r"))==NULL){
        printf("error opening file");
        return 1;
    }
    fscanf(fp, "%d",&numRighe);
    leggiFile(fp,numRighe);
    return 0;
}

void leggiFile(FILE *fp, int numRighe){
    int lungSelezione, vet[MAX_LUNG],vet_copia[MAX_LUNG];
    for(int i=0;i<numRighe;i++){
        fscanf(fp,"%d",&lungSelezione);
        for(int j=0;j<lungSelezione;j++){
            fscanf(fp,"%d", &vet[j]);
        }
        copiaVet(vet,vet_copia,lungSelezione);
        selectionSort(vet_copia,lungSelezione);
        copiaVet(vet,vet_copia,lungSelezione);
        insertionSort(vet_copia,lungSelezione);
        copiaVet(vet,vet_copia,lungSelezione);
        shellSort(vet_copia,lungSelezione);
    }
}

void copiaVet(int vet[MAX_LUNG],int vet_copia[MAX_LUNG],int lungSelezione){
    for(int i=0;i<lungSelezione;i++){
        vet_copia[i]=vet[i];
    }
    printf("\n");
}


void selectionSort(int A[MAX_LUNG], int N) {
    int i, j, l=0, r=N-1, min;
    int temp;
    int numScambi=0,numIterazioniCicloEsterno=0,numIterazioniCicloInterno=0,numTotIterazioni;
    for (i = l; i < r; i++) {
        numIterazioniCicloEsterno++;
        min = i;
        for (j = i+1; j <= r; j++) {
            numIterazioniCicloInterno++;
            if (A[j] < A[min])
                min = j;
        }
        if (min != i) {
            numScambi++;
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
    numTotIterazioni=numIterazioniCicloEsterno+numIterazioniCicloInterno;
    printf("num Scambi, num Iter Esterne, num Iter Interne, num tot Iter  ==> %d %d %d %d", numScambi, numIterazioniCicloEsterno,numIterazioniCicloInterno,numTotIterazioni);
    printf("\n");
}

void insertionSort(int A[MAX_LUNG], int N){
    int i,l=0,r=N-1,x,j;
    int numScambi=0,numIterazioniCicloEsterno=0,numIterazioniCicloInterno=0,numTotIterazioni;
    for(i=l+1;i<=r;i++){
        x=A[i];
        j=i-1;
        numIterazioniCicloEsterno++;
        while(j>=l && x<A[j]){
            numIterazioniCicloInterno++;
            A[j+1]=A[j];
            numScambi++;
            j--;
        }
        //numIterazioniCicloEsterno++;
        A[j+1]=x;
    }
    numTotIterazioni=numIterazioniCicloInterno+numIterazioniCicloEsterno;
    printf("num Scambi, num Iter Esterne, num Iter Interne, num tot Iter  ==> %d %d %d %d", numScambi, numIterazioniCicloEsterno,numIterazioniCicloInterno,numTotIterazioni);
    printf("\n");
}

void shellSort(int A[MAX_LUNG], int N) {
    int i, j, x, l=0, r=N-1, h=1;
    int numScambi=0,numIterazioniCicloEsterno=0,numIterazioniCicloInterno=0,numTotIterazioni;
    while (h < N/3)
        h = 3*h+1;
    while(h >= 1) {
        for (i = l + h; i <= r; i++) {
            j = i;
            x = A[i];
            while(j >= l + h && x < A[j-h]) {
                numIterazioniCicloInterno++;
                A[j] = A[j-h];
                numScambi++;
                j -=h;
            }
            numIterazioniCicloInterno++;
            A[j] = x;
        }
        numIterazioniCicloEsterno++;
        h = h/3;
    }
    numTotIterazioni=numIterazioniCicloInterno+numIterazioniCicloEsterno;
    printf("num Scambi, num Iter Esterne, num Iter Interne, num tot Iter  ==> %d %d %d %d", numScambi, numIterazioniCicloEsterno,numIterazioniCicloInterno,numTotIterazioni);
    printf("\n");
}