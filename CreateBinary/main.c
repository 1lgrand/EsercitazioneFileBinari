// In questo file si avrà la possibilità di creare il file binario
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

int find_file(){
    FILE *fp = fopen(FILENAME,"rb");

    if (fp == NULL)
    {
        printf("File iniesistente...\nGenerazione del file in corso...");
        fp = fopen(FILENAME,"w");
    }
    
    fclose(fp);
    return 0;
}

int fill_file(){

    FILE *fp = fopen(FILENAME,"ab");
    Studente s;
    int i = 0;
    char aggiungi = 'y';

    while (aggiungi == 'y')
    {
        fflush(stdin);
        printf("\nInserisci il NOME dello studente: ");
        gets(s.nome);
        printf("\nInserisci il COGNOME dello studente: ");
        gets(s.cognome);

        printf("\n\nInserimento dei voti, inserire 0 se non e' stato sostenuto\n\n");

        i = 0;
        while (i<N_ESAMI)
        {
            printf("Inserisci il voto dell'esame: ");
            scanf("%d",&s.esami[i]);
            i++;
        }


        fwrite(&s,sizeof(Studente),1,fp);
        fflush(stdin);

        printf("\n\n Continuare? (y)(n)");
        scanf("%c",&aggiungi);

    }
    fclose(fp);

    return 0;

}

int read_file(){

    FILE *fp = fopen(FILENAME,"rb");

    Studente s;
    int i;
    while (fread(&s,sizeof(Studente),1,fp) == 1)
    {
        printf("\n\nNome: %s",s.nome);
        printf("\nCognome: %s",s.cognome);
        printf("\n");
        for(i=0;i<N_ESAMI;i++){
            printf("%d-",s.esami[i]);
        }
    }
    
    fclose(fp);
    return 0;
}

int main(){

    find_file();

    fill_file();

    read_file();

    printf("\n\n");
    return 0;
}
