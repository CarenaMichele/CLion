#include <stdio.h>
int codifica(int test);
void visualizzaDimensione(float af, double ad);
void stampaCodifica(void *p, int size, int bigEndian);
int main() {
    float af;
    double ad, numDec;
    int bigEndian=0,test=1;
    printf("grandezza valore %p ==> %d byte\n",test, sizeof(test));
    bigEndian=codifica(test);
    printf("%d\n", bigEndian);
    visualizzaDimensione(af,ad);
    printf("inserisci numero decimale ==> ");
    scanf("%lf", &numDec);
    af=(float)numDec;
    ad=numDec;
    //printf("%.4f %.4lf\n",af,ad);
    stampaCodifica((void *)&af, sizeof(af), bigEndian);
    //stampaCodifica((void *)&ad, sizeof(ad), bigEndian);

}

int codifica(int test){
    char *pchar= (char *)&test;
    printf("%d\n", *(pchar));
    if(*(pchar)==0){
        printf("il calcolatore utilizza la codifica BigEndian\n");
        return 1;
    }
    else{
        printf("il calcolatore utilizza la codifica LittleEndian\n");
        return 0;
    }
}

void visualizzaDimensione(float af, double ad){
    printf("dimensione valore float ==>%d(BYTE), float ==>%d(BIT)\n",sizeof(af),8*sizeof(af));
    printf("dimensione valore double ==>%d(BYTE), float ==>%d(BIT)\n",sizeof(ad),8*sizeof(ad));
}

void stampaCodifica(void *p, int size, int bigEndian){
    float *px;int i=0;
    px=p;
    printf("%f\n",*px);
    unsigned char *vect[size];
    for(i=0;i<size;i++){
        vect[i]=(unsigned char *)(px+i);
    }
    for(int j=0;j<i;j++){
        printf("%d\n", *vect[i]);
    }

    /*;
    printf("%c", vect[0]);*/
}