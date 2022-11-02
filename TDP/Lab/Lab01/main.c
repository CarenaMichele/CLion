#include <stdio.h>
#include <ctype.h>

#define P 3.14
void esercizio1();
int esercizio2();
int esercizio3();
void esercizio4();
void esercizio5();
float svolgimento(char ope,float op1,float op2);
void esercizio6();
void fswitch();
int main() {
    int es;
    printf("scegli l'esercizio che vuoi compilare==>");
    es = getchar();
    fflush(stdin);
    fswitch(es);
    //putchar(es);
    return 0;

}
void esercizio1(){
    int x, y;
    float z;
    printf("Insert an integer number:");
    scanf("%d", &x);
    y = 3;
    z = (float)(x)/y;
    printf("%d/%d=%.3f\n", x, y, z);
}
int esercizio2(){
    FILE *fp_read, *fp_write;
    char file_char, choice;
    if ((fp_read = fopen("../Guide.txt", "r")) == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    if ((fp_write = fopen("../Output.txt", "w")) == NULL) {
        printf("Error opening file\n");
        return 2;
    }
    printf("Print on console (C) or on file (F):");
    choice = getchar();
    while (!feof(fp_read)) {
        file_char = fgetc(fp_read);
        if (!feof(fp_read)){
            switch (choice) {
                case 'C':
                    printf("\nChar printed on the console: %c",
                           file_char);
                    break;
                case 'F':
                    fputc(file_char, fp_write);
                    printf("\nChar saved on file: %c",file_char);
                    //putchar(file_char);
                    break;
                default:
                    printf("Wrong choice\n");
                    return 3;
            }
        }
    }
    fclose(fp_read);
    fclose(fp_write);
}

int esercizio3(){
    FILE *fp_read, *fp_write_odd, *fp_write_even;
    char file_string[100], name[20];
    int counter = 0;
    if ((fp_read = fopen("../Bronte.txt", "r")) == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    if ((fp_write_odd = fopen("../Output_odd.txt", "w")) == NULL) {
        printf("Error opening file\n");
        return 2;
    }
    if ((fp_write_even = fopen("../Output_even.txt", "w")) == NULL) {
        printf("Error opening file\n");
        return 3;
    }
    printf("What's your name?");
    gets(name);
    while (!feof(fp_read)) {
        counter++;
        if (counter%2==0) {
            fscanf(fp_read, "%s", file_string);
            if (!feof(fp_read)) {
                printf("%s\nI am reading:\n%s\n\n", name, file_string);
                fprintf(fp_write_even, "%s", file_string);
            }
        }
        else {
            fgets(file_string, 100, fp_read);
            if (!feof(fp_read)) {
                puts(name);
                puts("I am reading:");
                puts(file_string);
                fputs(file_string, fp_write_odd);
            }
        }
    }
    fclose(fp_read);
    fclose(fp_write_even);
    fclose(fp_write_odd);


    /*fscanf() lavora a "campi", ovvero stringhe separate fra loro da spazio o newline, e interpreta la configurazione specificata in format
- fgets() è più semplice e legge una riga di testo fino al newline

Una buona descrizione delle funzioni la possiamo trovare qui:
- fscanf() http://www.cplusplus.com/reference/cstdio/fscanf/
- fgets() http://www.cplusplus.com/reference/cstdio/fgets/
     */
}

void esercizio4(){
    char letter1, letter2;
    float areaQuadrato, areaCerchio;
    float diagonale=0.00,lato=0.00;
    float diametro=0.00, raggio=0.00;
    printf("vuoi calcolare l'area del quadrato (Q) o del cerchio (C) ?");
    letter1=toupper(getchar());
    fflush(stdin);
    if (letter1=='Q'){
        printf("vuoi calcolare l'area del quadrato con la diagonale (D) o il lato(L) ?");
        letter2=toupper(getchar());
        fflush(stdin);
        if (letter2=='D'){
            printf("inserisci il valore della diagonale==> ");
            scanf("%f",&diagonale);
            areaQuadrato=diagonale*(diagonale/2);
            printf("l'area del quadrato tramite diagonale e' %.3f",areaQuadrato);
        }
        else if (letter2=='L'){
            printf("inserisci il valore del lato==> ");
            scanf("%f",&lato);
            areaQuadrato=lato*lato;
            printf("l'area del quadrato tramite lato e' %.3f",areaQuadrato);
        }
        //printf("ciao %.2f", P);
    }
    else if (letter1=='C'){
        printf("vuoi calcolare l'area del cerchio con il diametro (D) o il raggio(R) ?");
        letter2=toupper(getchar());
        fflush(stdin);
        if (letter2=='D'){
            printf("inserisci il valore del diametro==> ");
            scanf("%f",&diametro);
            areaCerchio=P*diametro*(diametro/4);
            printf("l'area del cerchio tramite diametro e' %.3f",areaCerchio);
        }
        else if (letter2=='R'){
            printf("inserisci il valore del raggio==> ");
            scanf("%f",&raggio);
            areaCerchio=P*raggio*raggio;
            printf("l'area del cerchio tramite raggio e' %.3f",areaCerchio);
        }
    }

}

void esercizio5(){
    float op1, op2;
    printf("quale operazione vuoi eseguire? (+, -, *, /)");
    char ope = getchar();
    printf("inserisci il primo valore==>");
    scanf("%f",&op1);
    printf("inserisci il secondo valore==>");
    scanf("%f",&op2);
    float risultato = svolgimento(ope,op1,op2);
    printf("%c %f", ope, risultato);
}


void esercizio6(){
    FILE *fp_reader;
    FILE *fp_writer;
    char operazione;
    float n1, n2, risultato;
    fp_reader = fopen("../Operations.txt","r");
    fp_writer = fopen("../Results.txt","w");

    while (!feof(fp_reader)){
        fscanf(fp_reader, "%c %f %f", &operazione, &n1, &n2);
        risultato= svolgimento(operazione, n1, n2);
        fprintf(fp_writer,"%c %.2f\n",operazione, risultato);
    }
    fclose (fp_reader);
    fclose(fp_writer);
}

float svolgimento(char ope,float op1,float op2){
    float ris=0.0;
    switch (ope){
        case '+':
            ris=op1+op2;
            break;
        case '-':
            ris=op1-op2;
            break;
        case '*':
            ris=op1*op2;
            break;
        case '/':
            ris=op1/op2;
            break;
        default:
            printf("errore: comando non trovato");
    }
    return ris;
}

void fswitch(es){
    switch(es){
        case '1':
            esercizio1();
            break;
        case '2':
            esercizio2();
            break;
        case '3':
            esercizio3();
            break;
        case '4':
            esercizio4();
            break;
        case '5':
            esercizio5();
            break;
        case '6':
            esercizio6();
            break;
        default:
            printf("Non e' presente questo tipo di esercizio!");
    }
}