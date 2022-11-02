#include <stdio.h>

int main() {

    struct squadra{
        char nomeS[20];
        char coloreMaglia[20];
        int punteggio;
        struct allenatore{
            int titoliVinti;
            char nomeA[30];
            char cognomeA[30];
        } coach;
    } team;


}
