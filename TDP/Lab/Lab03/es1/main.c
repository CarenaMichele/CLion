#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define filein "input.txt"
#define fileout "testo.txt"
/*enum segni_punteggiatura {
    virgola = ',', punto = '.',  puntoVirgola = ';', duePunti = ':', puntoEscl = '!', puntoInt = '?', apostrofo = '\''
};*/
void esegui(FILE *fin, FILE *fout);
int main() {
    FILE *fin, *fout;
    char pathCode[30]= "../", pathDecode[30]="../";
    strcat(pathCode,filein);
    strcat(pathDecode,fileout);
    if((fin=fopen(pathCode,"r"))==NULL){
        printf("error opening file");
        return 1;
    }
    if((fout=fopen(pathDecode,"w"))==NULL){
        printf("error opening file");
        return 2;
    }
    esegui(fin,fout);
    return 0;
}

void esegui(FILE *fin, FILE *fout){
    char c0,c1,cPrec=' ';
    int cont=0;
    while(!feof(fin)){
        fscanf(fin,"%c",&c0);
        if(!feof(fin)){
            /*char punteggiatura =
                    c0 == virgola | c0 == punto | c0 == puntoVirgola | c0 == duePunti | c0 == puntoEscl |
                    c0 == puntoInt | c0  == apostrofo;*/
            if(cont<25){
                if(isdigit(c0)){
                    fprintf(fout,"%c",'*');
                    cont++;
                }
                if(isalpha(c0)){
                    fprintf(fout,"%c",c0);
                    cont++;
                }
                if(!isalpha(c0) && !isdigit(c0) && c0!=' ' && c0 != '\n'){
                    if((fscanf(fin,"%c",&c1))!=' '){ // || (fscanf(fin,"%c",&c1))!=EOF
                        fprintf(fout, "%c%c%c",c0,' ', toupper(c1));
                        cont+=3;
                    }
                }
                else if(c0==' '){
                    fprintf(fout,"%c",' ');
                    cont++;
                }
                else if(c0=='\n'){ //|| c0==EOF
                    //fprintf(fout,"%c", cprec);
                    for(int i=0;i<25-cont;i++){
                        fprintf(fout, " ");
                    }
                    fprintf(fout,"| c:%d \n", cont);
                    cont=0;

                }
            }
            else{
                fprintf(fout,"| c:%d \n", cont);
                fprintf(fout,"%c",c0);
                cont=1;
            }
            cPrec=c0;
        }
    }
    for(int i=0;i<25-cont;i++){
        fprintf(fout, " ");
    }
    fprintf(fout,"| c:%d \n", cont);
    cont=0;
}
