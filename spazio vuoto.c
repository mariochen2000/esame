#include <stdio.h>
#include <string.h>
int spazio(char stringa[]){
	int spaziVuoti=0;
	 int lunghezza = strlen(stringa);
	    // Conta il numero di spazi vuoti nella stringa
    for (int i = 0; i < lunghezza; i++) {
        if (stringa[i] == ' ') {
            spaziVuoti++;
        }
    }

    // Sostituisce gli spazi vuoti con "-"
    for (int i = 0; i < lunghezza; i++) {
        if (stringa[i] == ' ') {
            stringa[i] = '-';
        }
    }

    // Sostituisce i doppi spazi vuoti con "."
    for (int i = 0; i < lunghezza - 1; i++) {
        if (stringa[i] == '-' && stringa[i + 1] == '-') {
            stringa[i] = '.';
            // Sposta gli elementi successivi per eliminare il secondo spazio vuoto
            for (int j = i + 1; j < lunghezza; j++) {
                stringa[j] = stringa[j + 1];
            }
            lunghezza--; // Riduce la lunghezza della stringa di 1
        }
    }
    return spaziVuoti;
}


int main() {
    char stringa[100];
    printf("Inserisci una stringa: ");
    /*scanf("%[^\n]",stringa); // Permette di leggere una stringa con spazi vuoti*/
    gets(stringa);
int spaziVuoti;
    spaziVuoti=spazio(stringa);
    printf("Stringa modificata: %s\n", stringa);
    printf("Numero di spazi vuoti: %d\n", spaziVuoti);

    return 0;
}
