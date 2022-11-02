#include <stdio.h>
#define NR 4
#define NC 5

int main() {
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
