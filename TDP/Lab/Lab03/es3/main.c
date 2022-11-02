#include <stdio.h>
#define input "../numeri.txt"
#include <stdbool.h>
void esegui(FILE *fin);
int findMax(int max, int c0, int c1, int c2);
int findMin(int min, int c0, int c1, int c2);
int main() {
    FILE *fin;
    if((fin=fopen(input,"r"))==NULL){
        printf("error opening file!");
        return 1;
    }
    esegui(fin);
    return 0;
}

void esegui(FILE *fin){
    int c0,c1,c2;
    int scarto=0;
    bool scarti=false;
    int max=0,min=0;
    while(!feof(fin)){
        if(!feof(fin)){
        if(!scarti){
            fscanf(fin,"%d%d",&c0,&c1);
        }
        fscanf(fin,"%d",&c2);
        max=findMax(max,c0,c1,c2);
        min=findMin(min,c0,c1,c2);
        if(c1!=0){
            if((c2 != c0+c1) && (c2 != c0-c1) && (c2 != c0*c1) && (c2 != c0/c1)){
                scarto++;
                scarti=true;
            }
            else{
                scarti=false;
            }
        }
        else{
            if((c2 != c0+c1)&& (c2 != c0-c1) && (c2 != c0*c1)){
                scarto++;
                scarti=true;
            }
            else{
                scarti=false;
            }
        }
        }
    }
    printf("numero massimo: %d\nnumero minimo: %d\nnumeri scartati: %d", max, min, scarto);
}

int findMax(int max, int c0, int c1, int c2){
    if(c0>c1 && c0 > c2){
        if(c0>max){
            max=c0;
        }
    }
    else if(c1>c0 && c1>c2){
        if(c1>max){
            max=c1;
        }
    }
    else{
        if(c2>max){
            max=c2;
        }
    }
    return max;
}
int findMin(int min, int c0, int c1, int c2){
    if(c0<c1 && c0<c2){
        if(c0<min){
            min=c0;
        }
    }
    else if(c1<c0 && c1<c2){
        if(c1<min){
            min=c1;
        }
    }
    else{
        if(c2<min){
            min=c2;
        }
    }
    return min;
}