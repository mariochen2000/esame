#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SQUADRE 10
#define MAX_NOME 50
#define MAX_PARTITE 100

typedef struct {
    char nome[MAX_NOME];
    char abbreviazione;
    int punti;
} Squadra;

void aggiornaClassifica(Squadra classifica[], int numSquadre, char squadra1[], char squadra2[], int gol1, int gol2) {
    int i;

    for (i = 0; i < numSquadre; i++) {
        if (strcmp(classifica[i].nome, squadra1) == 0) {
            if (gol1 > gol2)
                classifica[i].punti += 3;
            else if (gol1 == gol2)
                classifica[i].punti += 1;
        }
        if (strcmp(classifica[i].nome, squadra2) == 0) {
            if (gol2 > gol1)
                classifica[i].punti += 3;
            else if (gol2 == gol1)
                classifica[i].punti += 1;
        }
    }
}

void stampaClassifica(Squadra classifica[], int numSquadre, char destinazione[]) {
    int i;
    FILE *fileDestinazione;

    fileDestinazione = fopen(destinazione, "w");
    if (fileDestinazione == NULL) {
        printf("Impossibile aprire il file di destinazione.\n");
        return;
    }

    for (i = 0; i < numSquadre; i++) {
        fprintf(fileDestinazione, "%s %d\n", classifica[i].nome, classifica[i].punti);
    }

    fclose(fileDestinazione);
}

void leggiRisultati(char sorgente[], char destinazione[]) {
    FILE *fileSorgente;
    int numSquadre, i;
    char nomeSquadra[MAX_NOME], abbreviazione;
    Squadra classifica[MAX_SQUADRE];

    fileSorgente = fopen(sorgente, "r");
    if (fileSorgente == NULL) {
        printf("Impossibile aprire il file di sorgente.\n");
        return;
    }

    fscanf(fileSorgente, "%*s %d", &numSquadre);

    for (i = 0; i < numSquadre; i++) {
        fscanf(fileSorgente, "%s %c", nomeSquadra, &abbreviazione);
        strcpy(classifica[i].nome, nomeSquadra);
        classifica[i].abbreviazione = abbreviazione;
        classifica[i].punti = 0;
    }

    while (!feof(fileSorgente)) {
        char squadra1[MAX_NOME], squadra2[MAX_NOME];
        int gol1, gol2;

        fscanf(fileSorgente, "%s %s %d %d", squadra1, squadra2, &gol1, &gol2);
        aggiornaClassifica(classifica, numSquadre, squadra1, squadra2, gol1, gol2);
    }

    fclose(fileSorgente);

    stampaClassifica(classifica, numSquadre, destinazione);
}

int main() {
    char sorgente[] = "sorgente.txt";
    char destinazione[] = "destinazione.txt";

    leggiRisultati(sorgente, destinazione);

    return 0;
}
