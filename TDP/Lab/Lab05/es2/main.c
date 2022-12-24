#include <stdio.h>
#include <string.h>
#define MAXLEN 50
typedef struct dizionario{
    char ricodifica[10];
    char originale[10];
}dizionario;
void leggiDizionario(FILE *fin, struct dizionario dizionario[MAXLEN], int dim);
void ricodifica(FILE *fin, FILE *fout, struct dizionario[MAXLEN], int dim);
int main() {
    struct dizionario dizionario[MAXLEN];
    FILE *fin1,*fin2,*fout;
    int numRicodifiche;
    if((fin1=fopen("../dizionario.txt","r"))==NULL){
        printf("error opening file\n");
        return 1;
    }
    if((fin2=fopen("../sorgente.txt","r"))==NULL){
        printf("error opening file\n");
        return 2;
    }
    if((fout=fopen("../ricodificato.txt","w"))==NULL){
        printf("error opening file\n");
        return 3;
    }
    fscanf(fin1, "%d", &numRicodifiche);
    leggiDizionario(fin1, dizionario,numRicodifiche);
    fclose(fin1);
    ricodifica(fin2,fout,dizionario,numRicodifiche);
    return 0;
}
void leggiDizionario(FILE *fin, struct dizionario dizionario[MAXLEN],int dim){
    for(int i=0;i<dim;i++){
        fscanf(fin, "%s %s", dizionario[i].ricodifica, dizionario[i].originale);
    }
}
void ricodifica(FILE *fin, FILE *fout, struct dizionario dizionario[MAXLEN],int dim){
    char val[20],valMod[20],carEliminati[20],fine;
    while(!feof(fin)) {
        fscanf(fin, "%s", &val);
        fscanf(fin,"%c",&fine);
        if (!feof(fin)) {
            int ok = 0,i,j;
            for (i = 0; i < dim && ok!=1; i++) {
                if (strcmp(val, dizionario[i].originale) == 0) {
                    fprintf(fout, " %s ", dizionario[i].ricodifica);
                    ok = 1;
                }
                else{
                    int k=0,cont=0,g=0;
                    char caratteriEl[20], carPrec[20];
                    for(j=0;j< strlen(val) && ok!=1;j++){
                        if(val[j]==dizionario[i].originale[k]){
                            k++;
                            cont++;
                        }
                        else{
                            if(cont<strlen(dizionario[i].originale)){
                                k=0;
                                cont=0;
                                g=0;
                                for(int s=0;s<j+1;s++){
                                    caratteriEl[g]=val[s];
                                    g++;
                                }
                            }
                        }
                        if(cont == strlen(dizionario[i].originale)){
                            caratteriEl[g]='\0';
                            fprintf(fout, " %s%s", caratteriEl,dizionario[i].ricodifica);
                            ok=1;
                        }
                        if(ok==1 && j< strlen(val)-1){
                            for(int c=j+1;c< strlen(val);c++){
                                fprintf(fout, "%c", val[c]);
                            }
                        }
                    }
                }
            }
            if(ok==0){
                fprintf(fout, " %s ", val);
            }
        }
        if(fine=='\n'){
            fprintf(fout,"\n");
        }
    }
}
