#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SEQ 20
#define MAX_CHAR 5
#define MAX_NP 100
#define MAX_CHAR2 25
void leggiFileSeq(FILE *f1, char seq[MAX_SEQ][MAX_CHAR],int dim);
int leggiFileTesto(FILE *f2, char seq[MAX_NP][MAX_CHAR2]);
void elaborazioneTesto(int dim,int dim2, char seq[MAX_SEQ][MAX_CHAR], char testo[MAX_NP][MAX_CHAR2]);
void cercaParola(char *seq1, char *seq2,int pos);
int main() {
    FILE *f1, *f2;
    char seq[MAX_SEQ][MAX_CHAR];
    char testo[MAX_NP][MAX_CHAR2];
    if((f1=fopen("../sequenze.txt","r"))==NULL){
        printf("error opening file");
        return 1;
    }
    if((f2= fopen("../testo.txt","r"))==NULL){
            printf("error opening file");
            return 2;
    }
    int dim=0;
    fscanf(f1, "%d", &dim);
    leggiFileSeq(f1,seq,dim);
    int dim2= leggiFileTesto(f2,testo);
    fclose(f1);
    fclose(f2);
    elaborazioneTesto(dim,dim2,seq,testo);
    return 0;
}

void leggiFileSeq(FILE *f1, char seq[MAX_SEQ][MAX_CHAR],int dim){
    for(int i=0;i<dim;i++){
        fscanf(f1, "%s", seq[i]);
    }
}

int leggiFileTesto(FILE *f2, char seq[MAX_NP][MAX_CHAR2]){
    int i=0,j=0;
    char val;
    /*while(!feof(f2)){
        if(!feof(f2)) {
            fscanf(f2,"%s",seq[i]);
            i++;
        }
    }*/
    while(!feof(f2)){
        fscanf(f2,"%c",&val);
        if(!feof(f2)){
            if(isspace(val) || val==','){
                seq[i][j]='\0';
                printf("%s\n",seq[i]);
                i++;
                j=0;
            }
            else if(isalnum(val)){
                seq[i][j]=val;
                j++;
            }
        }
    }
    /*for(int k=0;k<i;k++){
        printf("%s",seq[k]);
        printf("\n");
    }*/
    return i+1;

}

void elaborazioneTesto(int dim,int dim2, char seq[MAX_SEQ][MAX_CHAR], char testo[MAX_NP][MAX_CHAR2]){
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim2;j++){
            cercaParola(seq[i],testo[j],j+1);
        }
    }
}

void cercaParola(char *seq1, char *seq2,int pos){
    int i=0,j=0,conta=0;
    while(seq1[i] != '\0'  && seq2[j] != '\0'){
        if(tolower(seq1[i])==tolower(seq2[j])){
            i++;j++;
            conta++;
        }
        else if(tolower(seq1[i])!=tolower(seq2[j]) && seq2[j]!='\0'){
            conta=0;
            j++;
        }
        else if(tolower(seq1[i])!=tolower(seq2[j]) && seq2[j]=='\0') {
            conta=0;
            i++;j=0;
        }
    }
    if(conta==strlen(seq1)){
        printf("la sequenza %s e' contenuta in %s (parola in posizione %d nel testo)",seq1,seq2,pos);
        printf("\n");
    }

}