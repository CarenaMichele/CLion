#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define file "../expr.txt"
void esegui(FILE *fin,FILE *fout);
int main() {
   FILE *fin, *fout;
   if((fin=fopen(file,"r"))==NULL){
       printf("error opening file\n");
       return 1;
   }
   fout=fopen("../save.txt","w");
   esegui(fin,fout);
   return 0;
}

void esegui(FILE *fin, FILE *fout) {
    char stringa[25];
    int parentesiAperte = 0, riga = 0,i=0, k = 0;
    bool errorNumber = false, errorOperand = false;
    while (!feof(fin)) {
        k=0;
        if (!feof(fin)) {
            fgets(stringa, 25, fin);
            for (i = 0; stringa[i]; i++) {
                stringa[i] = stringa[i + k];
                if ((stringa[i] == ' ' && isdigit(stringa[i + 1]) && !isdigit(stringa[i - 1])) ||
                    (stringa[i] == ' ' && !isdigit(stringa[i + 1]) && isdigit(stringa[i - 1])) ||
                    (stringa[i] == ' ' && !isdigit(stringa[i + 1]) && !isdigit(stringa[i - 1]))) {
                    k++;
                    i--;
                }

            }
            fputs(stringa, fout);
        }
    }
    fclose(fin);
    fclose(fout);
    fout=fopen("../save.txt","r");
    char c0, c1;
    fscanf(fout, "%c",&c0);
    while((!feof(fout))) { // && (!errorOperand || !errorNumber)
        if ((!feof(fout))) {
            fscanf(fout, "%c", &c1);
            printf("%c", c1);
            //riga++;
            //parentesiAperte=0;
            //errorOperand=false;
            //errorNumber=false;
            if (c0 == '(') {
                parentesiAperte++;
                if ((c1 != '(') && (!isdigit(c1))) {
                    errorOperand = true;
                } else {
                    errorOperand = false;
                    c0 = c1;
                }
            } else if (c0 == ')') {
                parentesiAperte--;
                if ((c1 != '+' || c1 != '-' || c1 != '*' || c1 != '/') && (c1 != ')') &&
                    (c1 != feof(fout))) { // && (stringaFin[i+1]!=')') && (stringaFin[i+1]!='\n')
                    errorNumber = true;
                } else {
                    errorNumber = false;
                    c0 = c1;
                }
            } else if (c0 > '0' && c0 < '9') {
                if ((c1 != '+' || c1 != '-' || c1 != '*' || c1 != '/') && (c1 != ')') && (c1 !=
                                                                                          feof(fout))) { // && (stringaFin[i+1]!=')') && (stringaFin[i+1]!='\n')//i+1!=strlen(stringaFin)
                    errorNumber = true;
                } else {
                    errorNumber = false;
                    c0 = c1;
                }
            } else if (c0 == '+' || c0 == '-' || c0 == '*' || c0 == '/') {
                if ((c1 != '(') && (!isdigit(c1))) {
                    errorOperand = true;
                } else {
                    errorOperand = false;
                    c0 = c1;
                }
            }
        }
    }
}
/*if(parentesiAperte!=0){
                printf("errore nella lettura di un operando (espressione %d)\n", riga);
                parentesiAperte=0;
            }
            else if(errorNumber){
                printf("errore nella lettura di un numero (espressione %d)\n", riga);
                errorNumber=false;
            }
            else if(errorOperand){
                printf("errore nella lettura di un operando (espressione %d)\n", riga);
                errorOperand=false;
            }*/


/*while(!feof(fout)){
       if(!feof(fout)){
           fgets(stringaFin, 25, fout);
           riga++;
           parentesiAperte=0;
           errorOperand=false;
           errorNumber=false;
           for (i = 0; i < strlen(stringaFin); i++) {
               if (stringaFin[i] == '(') {

                   parentesiAperte++;
                   if ((stringaFin[i + 1] != '(') && (!isdigit(stringaFin[i + 1]))) {
                       errorOperand = true;
                       break;
                   }
               }
               else if(stringaFin[i] == ')'){
                   parentesiAperte--;
                   if((stringaFin[i+1]!='+' || stringaFin[i+1]!='-' || stringaFin[i+1]!='*' || stringaFin[i+1]!='/')){ // && (stringaFin[i+1]!=')') && (stringaFin[i+1]!='\n')
                       errorNumber=true;
                       break;
                   }
               }
               else if(stringaFin[i]>'0' && stringaFin[i]<'9'){
                   if((stringaFin[i+1]!='+' || stringaFin[i+1]!='-' || stringaFin[i+1]!='*' || stringaFin[i+1]!='/')){ // && (stringaFin[i+1]!=')') && (stringaFin[i+1]!='\n')//i+1!=strlen(stringaFin)
                       errorNumber=true;
                       break;
                   }
               }
               else if (stringaFin[i] == '+' || stringaFin[i] == '-' || stringaFin[i] == '*' || stringaFin[i] == '/') {
                   if ((stringaFin[i + 1] != '(') && (!isdigit(stringaFin[i + 1]))) {
                       errorOperand = true;
                       break;
                   }
               }
           }
           if(parentesiAperte!=0){
               printf("errore nella lettura di un operando (espressione %d)\n", riga);
           }
           else if(errorNumber){
               printf("errore nella lettura di un numero (espressione %d)\n", riga);
           }
           else if(errorOperand){
               printf("errore nella lettura di un operando (espressione %d)\n", riga);
           }
       }
   }*/