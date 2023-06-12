#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Punto;

float lunghezzaSpezzata(char *nomeFile, int *lineaChiusa) {
    FILE *file = fopen(nomeFile, "r");
    if (file == NULL) {
        printf("Errore nell'apertura del file.\n");
        return 0;
    }
    
    Punto punti[100];
    int numPunti=0;
    
    // Legge i punti dal file e li memorizza in un array
    while (fscanf(file, "%f %f", &punti[numPunti].x, &punti[numPunti].y) == 2) {
        numPunti++;
    }
    
    // Calcola la lunghezza della spezzata
    float lunghezza = 0;
    for (int i = 1; i < numPunti; i++) {
        float dx = punti[i].x - punti[i-1].x;
        float dy = punti[i].y - punti[i-1].y;
        lunghezza += sqrt(dx*dx + dy*dy);
    }
    
    // Verifica se la linea è chiusa
    if (punti[0].x == punti[numPunti-1].x && punti[0].y == punti[numPunti-1].y) {
        *lineaChiusa = 1;
    } else {
        *lineaChiusa = 0;
    }
    
    fclose(file);
    return lunghezza;
}

int main() {
    int lineaChiusa;
    float lunghezza = lunghezzaSpezzata("punti.txt", &lineaChiusa);
    printf("Lunghezza spezzata: %f\n", lunghezza);
    if (lineaChiusa) {
        printf("La linea è chiusa.\n");
    } else {
        printf("La linea non è chiusa.\n");
    }
    return 0;
}
//Nel main viene chiamato il sottoprogramma lunghezzaSpezzata, che riceve come parametro il nome del file contenente i punti e un puntatore alla variabile lineaChiusa, che viene usata per indicare se la linea è chiusa o meno. Il sottoprogramma legge i punti dal file, li memorizza in un array, calcola la lunghezza della spezzata e verifica se la linea è chiusa. Infine restituisce la lunghezza della spezzata e il valore di lineaChiusa.





