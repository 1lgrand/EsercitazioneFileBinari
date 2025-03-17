# Esercitazione 2
Implementare un programma che dato un file in input riesca a ottenere i 3 seguenti dati:

1. Studente con la media dei voti più alta.
2. Studente con il maggior numero di esami sostenuti.
3. Studente con il voto più alto.

Che saranno visualizzati in output in un file di testo

## Struttura dei dati
I dati verranno memorizzati in un file binario che memorizzerà il seguente record

```
#define N_ESAMI (6)
#define MAXLEN (64)

typedef struct{
    char nome[MAXLEN];
    char cognome[MAXLEN];
    int esami[N_ESAMI];
}Studente;

```


 
