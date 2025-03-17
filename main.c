#include <stdio.h>
#include <stdlib.h>

#define FILENAME "input.dat"
#define N_ESAMI (6)
#define MAXLEN (64)

typedef struct{
    char nome[MAXLEN];
    char cognome[MAXLEN];
    int esami[N_ESAMI];
}Studente;

Studente getMaxMedia();
Studente getNumEsamiSostenuti();
Studente getVotoPiuAlto();

int main(){

    float maxMedia = 0;
    int esamiSostenuti = 0;
    int votoPiuAlto = 0;

    Studente sMediaAlta;
    Studente sEsamiSostenuti;
    Studente votoPiuAlto;


}