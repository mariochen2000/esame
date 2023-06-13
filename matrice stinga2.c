#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10
#define MAX_LENGTH 100

int confrontaMatriceStringa(char matrice[][MAX_SIZE], int dimensione, char stringa[]) {
    int lunghezzaStringa = strlen(stringa);
    int conteggio = 0;
    
    // Confronto sulle righe
    for (int i = 0; i < dimensione; i++) {
        for (int j = 0; j <= dimensione - lunghezzaStringa; j++) {
            int flag = 1;
            
            for (int k = 0; k < lunghezzaStringa && flag == 1; k++) {
                if (matrice[i][j + k] != stringa[k]) {
                    flag = 0;
                }
            }
            
            if (flag == 1) {
                conteggio++;
            }
        }
    }
    
    // Confronto sulle colonne
    for (int j = 0; j < dimensione; j++) {
        for (int i = 0; i <= dimensione - lunghezzaStringa; i++) {
            int flag = 1;
            
            for (int k = 0; k < lunghezzaStringa && flag == 1; k++) {
                if (matrice[i + k][j] != stringa[k]) {
                    flag = 0;
                }
            }
            
            if (flag == 1) {
                conteggio++;
            }
        }
    }
    if(lunghezzaStringa!=1){
    	return conteggio;
	}
    else
    return conteggio/2;
}

int main() {
    int dimensione;
    char matrice[MAX_SIZE][MAX_SIZE];
    char stringa[MAX_LENGTH];
    
    printf("Inserisci la dimensione della matrice quadrata: ");
    scanf("%d", &dimensione);
    
    printf("Inserisci gli elementi della matrice:\n");
    for (int i = 0; i < dimensione; i++) {
        for (int j = 0; j < dimensione; j++) {
            scanf(" %c", &matrice[i][j]);
        }
    }
    
    printf("Inserisci la stringa da confrontare: ");
    scanf("%s", stringa);
    
    int conteggio = confrontaMatriceStringa(matrice, dimensione, stringa);
    
    if (conteggio > 0) {
        printf("La stringa è presente %d volte \n", conteggio);
    } else {
        printf("La stringa non è presente sia nelle righe che nelle colonne della matrice.\n");
    }
    
    return 0;
}
