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
Studente getStudenteRicercato();

int main(){

    float maxMedia = 0;
    int esamiSostenuti = 0;
    int votoPiuAlto = 0;

    Studente sMediaAlta;
    Studente sEsamiSostenuti;
    Studente sVotoPiuAlto;
    Studente sRicerca;

    FILE *fpOutput = fopen(OUTPUTFILE,"w");

    if (checkInputFile() == 0)
    {
        sMediaAlta = getMaxMedia(&maxMedia);
        printf("\n");
        sEsamiSostenuti = getNumEsamiSostenuti(&esamiSostenuti);
        printf("\n");
        sRicerca = getStudenteRicercato();

        printf("\nLo studente con la media piu alta e': %s con %.2f",sMediaAlta.cognome,maxMedia);
        printf("\n");
        fflush(stdin);
        printf("\nLo studente con piu esami e': %s con %d", sEsamiSostenuti.cognome ,esamiSostenuti);
    }else{
        printf("\nFile di input assente! ");
    }
    

    printf("\n\n");
    return 0;
}

int checkInputFile(){
    FILE *fp = fopen(FILENAME,"rb");
    int exist = 1;

    if (fp != NULL){
        exist = 0;
    }

    return exist;
        
    
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



Studente getStudenteRicercato(){
    int i = 0;
    Studente s;
    Studente r;
    FILE *fp = fopen(FILENAME,"rb");

    printf("\n Inserisci il cognome del studente da cercare: ");
    scanf("%s",r.cognome);

    while (fread(&s,sizeof(Studente),1,fp) == 1)
    { 
        if(r.cognome == s.cognome){
            printf("\n Nome: %s Cognome: %s",s.nome,s.cognome);
            return s;
        }
    }
    

    fclose(fp);
    return r;
}

