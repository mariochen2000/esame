#include <stdio.h>

#define MAX_TITOLI 100

// Struttura per rappresentare un titolo
typedef struct {
    int codice;
    float prezzoMedio2016;
    float prezzoUltimaChiusura;
} Titolo;

// Funzione per calcolare la percentuale di titoli con valore più basso dell'ultimo prezzo medio
float percentualePerdite(Titolo titoli[], int numTitoli) {
    int contPerdite = 0;

    for (int i = 0; i < numTitoli; i++) {
        if (titoli[i].prezzoUltimaChiusura < titoli[i].prezzoMedio2016) {
            contPerdite++;
        }
    }

    return (float)contPerdite / numTitoli * 100;
}

// Funzione per ottenere i titoli con valore inferiore al 30% del prezzo medio del 2016
void titoliInFortePerdita(Titolo titoli[], int numTitoli, int risultato[], int* numRisultati) {
    *numRisultati = 0;

    for (int i = 0; i < numTitoli; i++) {
        if (titoli[i].prezzoUltimaChiusura < titoli[i].prezzoMedio2016 * 0.3) {
            risultato[*numRisultati] = titoli[i].codice;
            (*numRisultati)++;
        }
    }
}

int main() {
    int numTitoli;

    printf("Inserisci il numero di titoli (max %d): ", MAX_TITOLI);
    scanf("%d", &numTitoli);

    if (numTitoli < 1 || numTitoli > MAX_TITOLI) {
        printf("Numero di titoli non valido.\n");
        return 0;
    }

    Titolo titoli[MAX_TITOLI];

    printf("Inserisci i dati per ogni titolo:\n");
    for (int i = 0; i < numTitoli; i++) {
        printf("Titolo %d:\n", i + 1);
        printf("Codice identificativo: ");
        scanf("%d", &titoli[i].codice);
        printf("Prezzo medio del 2016: ");
        scanf("%f", &titoli[i].prezzoMedio2016);
        printf("Prezzo ultima chiusura: ");
        scanf("%f", &titoli[i].prezzoUltimaChiusura);
    }

    float percentuale = percentualePerdite(titoli, numTitoli);
    printf("Percentuale dei titoli con valore più basso del valore medio del 2016: %.2f%%\n", percentuale);

    int titoliFortePerdita[MAX_TITOLI];
    int numRisultati;

    titoliInFortePerdita(titoli, numTitoli, titoliFortePerdita, &numRisultati);

    printf("Titoli con valore inferiore al 30%% del valore medio del 2016:\n");
    for (int i = 0; i < numRisultati; i++) {
        printf("- Codice identificativo: %d\n", titoliFortePerdita[i]);
    }

    return 0;
}
