#include <stdio.h>
#include <string.h>

void separaCaratteri(const char* input, char* alfa, char* number, int* lunghezzaAlfa, int* lunghezzaNumber) {
    int lunghezzaInput = strlen(input);
    int idxAlfa = 0;
    int idxNumber = 0;

    for (int i = 0; i < lunghezzaInput; i++) {
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) {
            alfa[idxAlfa] = input[i];
            idxAlfa++;
        } else if (input[i] >= '0' && input[i] <= '9') {
            number[idxNumber] = input[i];
            idxNumber++;
        }
    }

    *lunghezzaAlfa = idxAlfa;
    *lunghezzaNumber = idxNumber;
}

int main() {
    char input[100];
    char alfa[100];
    char number[100];
    int lunghezzaAlfa, lunghezzaNumber;
    int i;

    printf("Inserisci una stringa di caratteri (termina con \\r): ");
    scanf("%s", input);
     i=strlen(input);
printf("%d",i);
    separaCaratteri(input, alfa, number, &lunghezzaAlfa, &lunghezzaNumber);

    printf("alfa = \"%s\"\n", alfa);
    printf("number = \"%s\"\n", number);
    printf("lunghezza alfa = %d\n", lunghezzaAlfa);
    printf("lunghezza number = %d\n", lunghezzaNumber);

    return 0;
}
