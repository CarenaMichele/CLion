#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 1000
#define MAX_S 30

typedef struct{
    char codice_tratta[MAX_S];
    char partenza[MAX_S];
    char destinazione[MAX_S];
    char data[MAX_S];
    char ora_partenza[MAX_S];
    char ora_arrivo[MAX_S];
    int ritardo;
}corse;

typedef enum{
    r_date, r_partenza, r_capolinea, r_ritardo, r_ritardo_tot, r_fine
}comando_e;

void leggiFile(FILE *fin,corse corsa[MAXLEN], int lun);
void menuParola(corse corsa[MAXLEN], int dim);
comando_e leggiComando();
void elencoCorsaIntDate(corse corsa[MAXLEN], int dim, char dataP[MAX_S], char dataA[MAX_S]);
void elencoCorsaPartenza(corse corsa[MAXLEN], int dim,char partenza[MAX_S]);
void elencoCorsaDestinazione(corse corsa[MAXLEN], int dim,char destinazione[MAX_S]);
void elencoCorsaRitardoTraDate(corse corsa[MAXLEN],int dim,char dataP[MAX_S],char dataA[MAX_S]);
void elencoCorsaCodTratta(corse corsa[MAXLEN],int dim,char codTratta[MAX_S]);
void stampaTratte(corse corsa);

int main() {
    corse corsa[MAXLEN];
    int lun=0;
    FILE *fin;
    if((fin=fopen("../log.txt","r"))==NULL){
        printf("error opening file\n");
        return 1;
    }
    fscanf(fin, "%d", &lun);
    leggiFile(fin,corsa, lun);
    menuParola(corsa, lun);
    return 0;
}

void leggiFile(FILE *fin, corse corsa[], int lun){
    for(int i=0; i<lun;i++){
        fscanf(fin, "%s %s %s %s %s %s %d", corsa[i].codice_tratta,corsa[i].partenza, corsa[i].destinazione, corsa[i].data, corsa[i].ora_partenza, corsa[i].ora_arrivo, &corsa[i].ritardo);
    }
}

void menuParola(corse corsa[], int dim){
    comando_e comando;
    char dataP[MAX_S], dataA[MAX_S], partenza[MAX_S],destinazione[MAX_S],codTratta[MAX_S];
    int continua=1;
    while(continua){
        printf("CMD 'date': elenco di tutte le corse partite in un certo intervallo di date\n"
               "CMD 'partenza': elenco di tutte le corse partite da una certa fermata\n"
               "CMD 'capolinea': elenco di tutte le corse aventi una data destinazione\n"
               "CMD 'ritardo': elenco di tutte le corse che hanno raggiunto la destinazione in ritardo, in un certo intervallo di date\n"
               "CMD 'ritardo_tot': elenco del ritardo complessivo accumulato dalle corse identificate da un certo codice di tratta\n"
               "CMD 'fine: per terminare\n\n");
        comando = leggiComando();
        switch(comando){
            case r_date:
                printf("inserisci intervallo di date (YYYY/mm/gg):");
                scanf("%s %s", dataP, dataA);
                elencoCorsaIntDate(corsa,dim,dataP,dataA);
                break;
            case r_partenza:
                printf("inserisci luogo di partenza:");
                scanf("%s",partenza);
                elencoCorsaPartenza(corsa,dim,partenza);
                break;
            case r_capolinea:
                printf("inserisci luogo di destinazione:");
                scanf("%s",destinazione);
                elencoCorsaDestinazione(corsa,dim,destinazione);
                break;
            case r_ritardo:
                printf("inserisci intervallo di date (YYYY/mm/gg):");
                scanf("%s %s", dataP, dataA);
                elencoCorsaRitardoTraDate(corsa,dim,dataP,dataA);
                break;
            case r_ritardo_tot:
                printf("inserisci codice di tratta:");
                scanf("%s",codTratta);
                elencoCorsaCodTratta(corsa,dim,codTratta);
                break;
            case r_fine:
                continua=0;
                break;
        }
        printf("\n");
    }
}

comando_e leggiComando(){
    comando_e r;
    char cmd[20];
        char tabella[r_fine][MAX_S]={
            "date", "partenza", "capolinea", "ritardo","ritardo_tot", "fine"
    };
    printf("comando (date/partenza/capolinea/ritardo/ritardo_tot/fine):");
    scanf("%s", cmd);
    r=r_date;
    while(r<r_fine && strcmp(cmd,tabella[r])!=0)
        r++;
    return(r);
}

void elencoCorsaIntDate(corse corsa[], int dim, char dataP[], char dataA[]){
    for(int i=0;i<dim;i++){
        if(strcmp(corsa[i].data,dataP)>=0 && strcmp(corsa[i].data,dataA)<=0){
            stampaTratte(corsa[i]);
        }
    }
}

void elencoCorsaPartenza(corse corsa[], int dim,char partenza[]){
    for(int i=0;i<dim;i++){
        if(strcmp(corsa[i].partenza,partenza)==0){
            stampaTratte(corsa[i]);
        }
    }
}

void elencoCorsaDestinazione(corse corsa[], int dim,char destinazione[]){
    for(int i=0;i<dim;i++){
        if(strcmp(corsa[i].destinazione,destinazione)==0){
            stampaTratte(corsa[i]);
        }
    }
}

void elencoCorsaRitardoTraDate(corse corsa[MAXLEN],int dim,char dataP[MAX_S],char dataA[MAX_S]){
    for(int i=0;i<dim;i++){
        if(strcmp(corsa[i].data,dataP)>=0 && strcmp(corsa[i].data,dataA)<=0 && corsa[i].ritardo!=0){
            stampaTratte(corsa[i]);
        }
    }
}

void elencoCorsaCodTratta(corse corsa[MAXLEN],int dim,char codTratta[MAX_S]){
    int ritTot=0;
    for(int i=0;i<dim;i++){
        if(strcmp(corsa[i].codice_tratta,codTratta)==0){
            ritTot+=corsa[i].ritardo;
        }
    }
    printf("%s %d",codTratta,ritTot);
    printf("\n");
}

void stampaTratte(corse corsa){
    printf("%s %s %s %s %s %s %d", corsa.codice_tratta, corsa.partenza, corsa.destinazione, corsa.data, corsa.ora_partenza, corsa.ora_arrivo, corsa.ritardo);
    printf("\n");
}