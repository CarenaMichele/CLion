#include <stdio.h>
#include <math.h>
#include <string.h>
void eq2Grado();
void areaTriangoloRett();
void serieArmonica();
void intToBin(int n);
void conversioneTraBasi();
void converti(int n, int b);
#define	MAXRIGA	30
void crittografiaSemplice();
void menuSceltaCarattere();
void menuSceltaParola();
char fA(char riga);
char fL(char riga);
char fT(char riga);
void disegnoRett(int b,int h);
void visualizzaParabola();
void formattazione();
void monotona();
int main() {
    int es;
    int num;
    int b,h;
    char ingresso[30];
    char uscita[30];
    int lmax=30;
    printf("scegli l'es che vuoi risolvere==>");
    es=getchar();
    switch(es){
        case '1':
            eq2Grado();
            break;
        case '2':
            areaTriangoloRett();
            break;
        case '3':
            serieArmonica();
            break;
        case '4':
            printf("inserisci un numero intero==>");
            scanf("%d",&num);
            intToBin(num);
            break;
        case '5':
            conversioneTraBasi();
            break;
        case '6':
            crittografiaSemplice();
            break;
        case '7':
            menuSceltaCarattere();
            break;
        case '8':
            menuSceltaParola();
            break;
        case '9':
            printf("inserisci la base==>");
            scanf("%d",&b);
            printf("inserisci l'altezza==>");
            scanf("%d",&h);
            disegnoRett(b,h);
            break;
        case 'A':
            visualizzaParabola();
            break;
        case 'B':
            formattazione();
        case 'C':
            monotona();
    }

}

void eq2Grado(){
    float	a,b,c,delta,x0,x1,re,im;
    printf("Coefficienti	(a	b	c):	");
    scanf("%f%f%f",&a,&b,&c);
    if	(a==0	&&	b==0	&&	c==0)
        printf("Equazione indeterminata\n");
    if	(a==0	&&	b==0	&&	c!=0)
        printf("Equazione impossibile\n");
    if	(a==0	&&	b!=	0)	{
        printf("Equazione	di	I	grado\n	»");
        printf("Soluzione:	%f\n",	-c/b);
    }
    if (a!=0) {
        delta = b*b-4*a*c;
        if (delta==0) {
            x0 = (-b)/(2*a);
            x1 = (-b)/(2*a);
            printf("2 sol. reali coincidenti: ");
            printf("%f %f\n",x0,x1);
        }
        if (delta > 0) {
            x0 = (-b-sqrt(delta))/(2*a);
            x1 = (-b+sqrt(delta))/(2*a);
            printf("2 sol. reali distinte: ");
            printf("%f %f\n",x0,x1);
        }
        if (delta < 0){
            re = -b/(2*a);
            im = sqrt(-delta)/(2*a);
            printf("2 sol. compl. coniug.: ");
            printf("x0=%f-i*%f ",re, im);
            printf("x1=%f+i*%f\n", re, im); }
    }
}

void areaTriangoloRett(){
    int a,b,c;
    float area;
    printf("Lati	del	triangolo	(a	b	c):	");
    scanf("%d%d%d",&a,&b,&c);
    if	(a>b	&&	a>c)	{
        printf("L'ipotenusa e' a\n");
        area	=	b*c/2.0;
    }
    else	if	(b>a	&&	b>c)	{
        printf("L'ipotenusa e' b\n");
        area	=	a*c/2.0;
    }
    else	if	(c>a	&&	c>b)	{
        printf("L'ipotenusa e' c\n");
        area	=	a*b/2.0;
    }
    printf("L'area e': %f\n",area);
}

void serieArmonica(){
    int	n,	i;
    float	HN;
    printf("Num.	di	termini	(<=0=FINE):	");
    scanf("%d",&n);
    while(n>0){
        HN	=	0.0;
        for	(i=1;i<=n;i++)
            HN=HN+1.0/((float)i);
        printf("Risultato: %f\n",HN);
        printf("Num.	di	termini	(<=0=FINE):	");
        scanf("%d",&n);
    }
}

void intToBin(int n){
    int	p;
    for	(p=1;2*p<=n;p=p*2);
    while(p>0){
        if(p<=n){
            printf("1");
            n=n-p;
        }
        else
            printf("0");
        p=p/2;
    }
    printf("\n");
}

void conversioneTraBasi(){
    int b0, b1, n, p, cifra, fine=0;
    char c;
    printf("b0 (2..9): ");
    scanf("%d",&b0);
    printf("b1 (2..9): ");
    scanf("%d\n",&b1);
    n = 0;
    while(!fine){
        scanf("%c",&c);
        if	(c==' '||c=='\n'){
            converti(n,b1);
            n=0;
        }
        else{
            cifra=c-'0';
            if(cifra>=0	&&	cifra<b0)
                n=b0*n+cifra;
            else fine=1;
        }
    }
}

void converti(int n, int b){
    int p;
    for (p=1; b*p<=n; p=p*b);
    while (p>0) {
        if (p<=n) {
            printf("%d",n/p);
            n=n%p;
        }
        else
            printf("0");
        p = p/b;
    }
    printf("\n");
}

void crittografiaSemplice(){
    char ch,nomefile[MAXRIGA+1];
    FILE *fpin, *fpout;
    fpin=fopen("../ingresso.txt","r");
    //printf("nome file in uscita:");
    //scanf("%s", nomefile);
    fpout= fopen("../uscita.txt","w");
    while(fscanf(fpin,"%c",&ch)==1){
        if	(ch>='0'&&ch<='9')
            ch='0'+('9'	-ch);
        else if	(ch>='a' &&	ch<='z')
            ch= 'A'+('z'-ch);
        else if	(ch>='A' &&	ch<='Z')
            ch='a'+('Z'-ch);
        fprintf(fpout,"%c",ch);
    }
    fclose(fpin);
    fclose(fpout);
}

void menuSceltaCarattere(){
    const int	MAXL=51;
    char riga[MAXL],sel;
    int i,continua=1;
    while(continua){
        printf("comando	(A/L/T,	U=uscita):	");
        scanf("	%c",&sel); //lo spazio davanti al %c salta tutti gli eventuali spazi vuoti prima del carattere selettore
        gets(riga);
        switch(toupper(sel)){
            case 'A': fA(riga);	break;
            case 'L': fL(riga);	break;
            case 'T': fT(riga);	break;
            case 'U': continua=0; break;
            default:printf("comando errato\n");
        }
    }
}

char fA(char riga){}
char fL(char riga){}
char fT(char riga){}

void menuSceltaParola(){
    const int MAXL=51;
    char comando[MAXL],	riga[MAXL];
    int i,continua=1;
    while(continua){
        printf("comando (cerca/modifica ");
        printf("stampa/uscita):");
        scanf("%s",comando);/*comando*/ //%s non ha bisogno degli spazi vuoti davanti perchè in automatico toglie già gli eventuali spazi
        for	(i=0;i<strlen(comando);i++)
            comando[i]=toupper(comando[i]);
        gets(riga);	/*resto della riga*/
        if(strcmp(comando,"CERCA")==0){
            //cerca(riga);
        }
        else if(strcmp(comando,"MOD")==0){
            //sostituisci(riga);
        }
        else if(strcmp(comando,"STA")==0){
            //stampa(riga);
        }else if(strcmp(comando,"FINE")==0)	{
            continua=0;
        }else{
            printf("comando errato\n");
        }
    }
}

void disegnoRett(int b,int h){
    int i,j;
    for (i=0;i<h;i++){
        for (j=0;j<b;j++){
            if(i!=0 && i!=h-1 && j!=0 && j!=b-1){
                printf(" ");
            }
            else
                printf("*");
        }
        printf("\n");
    }
}

void visualizzaParabola(){
    float a,b,c,x,passo,x0,xn,y,ymin,ymax;
    int i, j, n;
    FILE *fpout	=fopen("out.txt","w");
    printf("Coefficienti(a b c):");
    scanf("%f%f%f",&a,&b,&c);
    printf("Numero di intervalli:");
    scanf("%d",&n);
    printf("Intervallo per ascisse:");
    scanf("%f%f",&x0,&xn);
    printf("Intervallo per ordinate:");
    scanf("%f%f",&ymin,&ymax);
    passo=(xn-x0)/n;
    for	(i=0;i<=n;i++){
        x= x0 + i*passo;
        y= a*x*x + b*x + c;
        if	(y>=ymin &&	y<=ymax) {
            for	(j=round(y-ymin); j>0;	j--) //per stampare gli spazi
                fprintf(fpout," ");
            fprintf(fpout,"*");
        }
        fprintf(fpout,"\n");
    }
    fclose(fpout);
}

void formattazione(){
    const int STRLEN=21;
    FILE *fin=fopen("../ingresso.txt", "r");
    FILE *fout=fopen("../fine.txt", "w");
    char parola[STRLEN];
    int l;
    l=0; //conteggio di quanti caratteri abbiamo stampato sulla riga corrente
    while(fscanf(fin,"%s",parola)==1)	{
        if(l+1+strlen(parola)>30){ //se sfora i bordi, vai a capo se no aggiungo ancora in quella riga. 30 è messo a caso, potrebbe essere qualsiasi valore, serve per determianre la lunghezza delle righe
            fprintf(fout,"\n%s",parola);
            l=strlen(parola);
        }
        else{
            fprintf(fout,"%s%s",l==0?	"":" ",parola);
            l+=l==0?0:1+strlen(parola);
        }
    }
    fclose(fin);
    fclose(fout);

}

void monotona(){
    int Monotona=1;	//	verdetto inizializzato	a	1
    int i;
    int	xi,	xj;
    int N;
    printf("inserisci valore N==>");
    scanf("%d",&N);
    printf("x0=");
    scanf("%d",&xi);
    for	(i=1;i<N;i++){
        printf("x%d=	",	i);
        scanf("%d",	&xj);
        if(xi>xj)		//	test	sul verdetto tra	due	dati adiacenti
            Monotona=0;		//	eventuale modifica	del	verdetto
        xi=xj;
    }
}