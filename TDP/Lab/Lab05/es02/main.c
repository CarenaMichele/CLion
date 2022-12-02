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
    /*for(int i=0;i<numRicodifiche;i++){
        printf("%s %s \n", dizionario[i].ricodifica, dizionario[i].originale);
    }*/
    return 0;
}

void leggiDizionario(FILE *fin, struct dizionario dizionario[MAXLEN],int dim){
    for(int i=0;i<dim;i++){
        fscanf(fin, "%s %s", dizionario[i].ricodifica, dizionario[i].originale);
    }
}

void ricodifica(FILE *fin, FILE *fout, struct dizionario dizionario[MAXLEN],int dim){
    char val[20],valMod[20];
    while(!feof(fin)){
        fscanf(fin, "%s", &val);
        if(!feof(fin)){
            int k=1,m=0,find=0,ok=1,i=0;
            valMod[m]=' ';
            //for(int i=0;i<dim;i++){
            //printf("%d",(int) strlen(val)-1);
            int lung=(int)strlen(val);
            /*if((int)strlen(val)==1){
                lung= ((int)strlen(val))+1;
            }
            else{
                lung=(int)strlen(val);
            }*/
            while(ok!=0){
                if(find==0){
                    for(i=0;i<dim;i++) {
                        if (strcmp(val, dizionario[i].originale) == 0) {
                            fprintf(fout, " %s ", dizionario[i].ricodifica);
                            ok = 0;
                        }
                        if(ok!=0 && i==dim-1){//&& strlen(val)>1
                            valMod[m]='\0';
                            m=0;
                            for(int j=k;j<lung;j++){
                                if(j!=lung){
                                    valMod[m]=val[j];
                                    m++;
                                }
                                else{
                                    valMod[m]=val[j];
                                }
                            }
                            //printf("%s\n",valMod);
                            if(k== lung){
                                ok=0;
                                fprintf(fout," %s ",val);
                            }
                            else{
                                k++;
                            }
                        }
                        /*else if(strlen(val)==1){
                            ok=0;
                            fprintf(fout," %s ",val);
                            break;
                        }*/
                    }
                    find=1;
                }
                else{
                    printf("%s\n",valMod);
                    for(i=0;i<dim;i++){
                        if(strcmp(valMod,dizionario[i].originale)==0){
                            fprintf(fout, " %s ", dizionario[i].ricodifica);
                            ok=0;
                            break;
                        }
                        else if(i==dim-1){
                            find=0;
                        }
                    }
                }
            }
        }
    }
}