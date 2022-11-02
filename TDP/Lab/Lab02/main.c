#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define NR 4
#define NC 5
void esercizio1();
void esercizio2();
void esercizio2Modificato();
int esercizio3();
int comprimi(FILE *fin, FILE *fout);
int decomprimi(FILE *fin, FILE *fout);
int esercizio4();
int codifica(FILE *fin, FILE *fout);
int decodifica(FILE *fin, FILE *fout);
int main() {
    int es;
    printf("quale esercizio vuoi eseguire? ==>");
    scanf("%d", &es);
    switch (es) {
        case 1:
            esercizio1();
            break;
        case 2:
            esercizio2();
            break;
        case 3:
            esercizio2Modificato();
            break;
        case 4:
            esercizio3();
            break;
        case 5:
            esercizio4();
            break;
        default:
            printf("questo esercizio non è presente!");
    }
}

void esercizio1(){
    int num1, num2;
    int val=0, ris;
    printf("inserisci un numero==>");
    scanf("%d", &num1);
    printf("inserisci un numero==>");
    scanf("%d", &num2);
    if(num1>num2){
        while(val==0){
            ris=num1%num2;
            if(ris!=0){
                num1=num2;
                num2=ris;
            }
            if (ris==0){
                val=1;
            }

        }
        printf("MCD == %d", num2);
    }
    else if(num2>num1){
        while(val==0){
            ris=num2%num1;
            if(ris!=0){
                num2=num1;
                num1=ris;
            }
            if (ris==0){
                val=1;
            }

        }
        printf("MCD == %d", num1);
    }
    else if (num1==num2){
        printf("Valori uguali! Inserisci nuovamente");
    }
}

void esercizio2(){
    int num;
    int fibonacci[num];
    printf("inserisci un numero==> ");
    fibonacci[0]=0;
    fibonacci[1]=1;
    scanf("%d", &num);
    for(int i=2; i<num;i++){
        fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
    }
    for(int i=0; i<num;i++){
        printf("%d \t", fibonacci[i]);
    }
}

void esercizio2Modificato(){
    int num;
    int fibonacci[num];
    printf("inserisci un numero==> ");
    fibonacci[0]=1;
    fibonacci[1]=2;
    scanf("%d", &num);
    for(int i=2; i<num;i++){
        fibonacci[i]=fibonacci[i-1]*fibonacci[i-2];
    }
    for(int i=0; i<num;i++){
        printf("%u \t", fibonacci[i]);
    }
}

int esercizio3(){
    FILE *fin, *fout;
    char ope;
    printf("Inserire l'operazione da eseguire ('C' per comprimere, 'D' per decomprimere):");
    scanf(" %c",&ope);
    if(ope== 'C'){
        if((fin=fopen("../Sorgente.txt", "r"))==NULL){
            printf("error opening file");
            return 1;
        }
        if((fout=fopen("../Ricodificato.txt", "w"))==NULL){
            printf("error opening file");
            return 2;
        }
        printf("sono stati compressi %d caratteri", comprimi(fin, fout));
    }
    else if(ope=='D'){
        if ((fin = fopen("../Ricodificato.txt", "r")) == NULL) {
            printf("Error opening file\n");
            return 1;
        }
        if ((fout = fopen("../Decodificato.txt", "w")) == NULL) {
            printf("Error opening file\n");
            return 2;
        }
        printf("sono stati decompressi %d caratteri", decomprimi(fin, fout));
    }
}


int comprimi(FILE *fin, FILE *fout) {
    char c0,c1,c2;
    int cont=0, nchar=0;
    fscanf(fin,"%c%c", &c0, &c1);
    while(!feof(fin)){
        if(!feof(fin)){
            if(c0==c1){
                cont++;
                if(cont==9){
                    fprintf(fout,"%c$%d",c0,cont);
                    nchar+=3;
                    cont=0;
                    fscanf(fin, "%c", &c1);
                    c0=c1;
                }
                c2=c1;
                fscanf(fin, "%c", &c1);
            }
            else{
                if(cont==1){
                    fprintf(fout,"%c%c",c0,c2);
                    nchar+=2;
                }
                else if(cont>=2 && cont<9){
                    fprintf(fout,"%c$%d",c0,cont);
                    nchar+=3;
                }
                else{
                    fprintf(fout,"%c",c0);
                    nchar++;
                }
                cont=0;
                c0=c1;
                fscanf(fin,"%c", &c1);
            }
        }
    }
    if(cont>1){
        fprintf(fout,"%c$%d",c0,cont);
        nchar+=3;
    }
    return nchar;
}

int decomprimi(FILE *fin, FILE *fout){
    char c0,c1,c2;
    int cont, nchar=0;
    while(!feof(fin)) {
        fscanf(fin,"%c",&c0);
        if (!feof(fin)) {
            if(c0!='$'){
               fprintf(fout, "%c",c0);
               nchar++;
               c2=c0;
            }
            else{
                fscanf(fin,"%c",&c1);
                cont= c1-'0';
                nchar+=cont;
                for(int i=0;i<cont;i++){
                    fprintf(fout, "%c",c2);
                }
            }
        }
    }
    return nchar;
}

int esercizio4(){
    FILE *fin,*fout1, *fout2;
    char scelta,fileCodifica[20],fileDecodifica[20],pathCode[30]= "../", pathDecode[30]="../";
    printf("scegli se comprimere o decomprimere il file (C:comprimere, D:decomprimere):");
    scanf(" %c", &scelta);
    printf("nome file sorgente:");
    scanf("%s",fileCodifica);
    strcat(pathCode,fileCodifica);
    strcat(pathCode,".txt");

    printf("nome file destinazione:");
    scanf("%s",fileDecodifica);
    strcat(pathDecode,fileDecodifica);
    strcat(pathDecode,".txt");

    if (scelta=='C'){
        if((fin=fopen("../Sorgente2.txt","r"))==NULL){
            printf("Error opening file\n");
            return 1;
        }
        if((fout1=fopen(pathCode,"w"))==NULL){
            printf("Error opening file\n");
            return 2;
        }
        printf("numeri di caratteri scritti nel file==> %d",codifica(fin,fout1));

    }
    else if(scelta == 'D'){
        if((fout2=fopen(pathDecode,"w"))==NULL){
            printf("Error opening file\n");
            return 2;
        }
        printf("numeri di caratteri scritti nel file==> %d",decodifica(fout1,fout2));
    }
    return 0;
}

int codifica(FILE *fin,FILE *fout){
    char c0;
    int k=0,h=0,val2=0,ris=0,val=0,cont=0;
    char box="";
    while(!feof(fin)){
        fscanf(fin, "%c", &c0);
        if(!feof(fin)){
            if(isalpha(c0)){
                if(isalpha(box)){
                    if(isupper(box)){
                        h=box-'A';
                        val2+=h;
                        val=val2+(int) toupper(c0);
                        if (val >(int)'Z') {
                            while(val>(int)'Z'){
                                val =val - ((int) 'Z' - (int) 'A')-1;
                            }
                        }
                        fprintf(fout, "%c", tolower(val));
                        cont++;
                        box=c0;
                    }
                    else{
                        h=box-'a';
                        val2+=h;
                        val=val2+(int)c0;
                        if (val >(int)'z') {
                            while(val>(int)'z'){
                                val =val - ((int) 'z' - (int) 'a')-1;
                            }
                        }
                        fprintf(fout, "%c", val);
                        cont++;
                        box=c0;
                    }
                }
                else{
                    fprintf(fout,"%c", c0);
                    cont++;
                    box=c0;
                }
            }
            else if(isdigit(c0)){
                int num = c0 - '0';
                ris=num+k;
                if (ris >=9) {
                    ris = 0;
                }
                char res=ris+'0';
                fprintf(fout, "%c", res);
                cont++;
                k++;
            }
            else{
                fprintf(fout,"%c", c0);
                cont++;
                box=c0;
                val2=0;
                ris=0;
            }
        }
    }
    return cont;
}

int decodifica(FILE *fin,FILE *fout){

    return 0;
}



/*
 * int numCount = 0;
    char startChar = 'a', rifChar = 'a';

    while (!feof(fin)) {
        char line[100];
        fgets(line, 100, fin);
        if (!feof(fin)) {
            for (int i = 0; i < strlen(line); i++) {

                if (isdigit(line[i])) {
                    int num = line[i] - '0';
                    if (numCount == 10) {
                        numCount = 0;
                    }
                    num += numCount;
                    fputc(num + '0', fout);
                    numCount++;
                } else if (isalpha((line[i]))) {
                    if (isalpha(line[i - 1])) {
                        char c0 = line[i], charFin;
                        int numSpost = c0 - startChar;
                        if ((int) rifChar + numSpost > (int) 'z') {
                            numSpost = numSpost - ((int) 'z' - (int) rifChar)-1;
                            rifChar = 'a';
                        }
                        charFin = (int) rifChar + numSpost;
                        fputc(charFin, fout);
                        rifChar = charFin;
                    } else {
                        fputc(line[i], fout);
                        rifChar = tolower(line[i]);
                    }
                } else{
                    fputc(line[i], fout);

                }
            }
        }
    }
    return 0;
 */

