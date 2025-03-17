#include <stdio.h>
#include <stdlib.h>

#define FILENAME "input.dat"
#define OUTPUTFILE "output.txt"
#define N_ESAMI (6)
#define MAXLEN (64)

typedef struct{
    char nome[MAXLEN];
    char cognome[MAXLEN];
    int esami[N_ESAMI];
}Studente;

Studente getMaxMedia(float *maxMedia);
Studente getNumEsamiSostenuti();
Studente getVotoPiuAlto();

int main(){

    float maxMedia = 0;
    int esamiSostenuti = 0;
    int votoPiuAlto = 0;

    Studente sMediaAlta;
    Studente sEsamiSostenuti;
    Studente sVotoPiuAlto;

    FILE *fpOutput = fopen(OUTPUTFILE,"w");

    sMediaAlta = getMaxMedia(&maxMedia);
    printf("\n");
    sEsamiSostenuti = getNumEsamiSostenuti(&esamiSostenuti);

    printf("\nLo studente con la media piu alta e': %s con %.2f",sMediaAlta.cognome,maxMedia);
    printf("\n");
    fflush(stdout);
    printf("\nLo studente con piu esami e': %s con %d", sEsamiSostenuti.cognome ,esamiSostenuti);


    printf("\n\n");
    return 0;
}

Studente getMaxMedia(float *maxMedia){
    int i = 0;
    float somma = 0;
    float media = 0;
    Studente s;
    Studente maxMediaStudente;
    FILE *fp = fopen(FILENAME,"rb");

    while (fread(&s,sizeof(Studente),1,fp) == 1)
    {
        for(i=0,somma=0;i<N_ESAMI;i++){         
            somma += s.esami[i];
        }

        media = somma/N_ESAMI;

        if (media > *maxMedia)
        {
            *maxMedia = media;
            maxMediaStudente = s;
        }
        
        printf("\nMedia di: %s -- [ %.2f ] ",s.cognome,media);
        
    }
    

    fclose(fp);
    return maxMediaStudente;

}

Studente getNumEsamiSostenuti(int *esamiSostenuti){
    int i = 0;
    int nEsami = 0;
    Studente s;
    Studente sEsamiSostenuti;
    FILE *fp = fopen(FILENAME,"rb");

    while (fread(&s,sizeof(Studente),1,fp) == 1)
    {
        for(i=0,nEsami=0;i<N_ESAMI;i++){ 

            if (s.esami[i] != 0)
            {
                nEsami++;
            }
        }

        if (*esamiSostenuti < nEsami)
        {
            *esamiSostenuti = nEsami;
        }
        
        printf("\n Numero di esami di: %s -- [ %d ] ",s.cognome,nEsami);

    }

    fclose(fp);
    return sEsamiSostenuti;
}

