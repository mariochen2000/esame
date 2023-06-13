#include <stdio.h>

void replaceString(char *text, char *find, char *sub) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (text[i] != '\0') {
        if (text[i] == find[j]) {
            j++;

            if (find[j] == '\0') {
                // Sostituisci la stringa
                for (k = 0; sub[k] != '\0'; k++) {
                    text[i - j + 1 + k] = sub[k];
                }
                j = 0;
            }
        } else {
            j = 0;
        }

        i++;
    }
}

int main() {
    char text[100] = "I love apples. apples are my favorite fruit apples.";
    char find[10] = "apples";
    char sub[10] = "ranges";

    replaceString(text, find, sub);
    printf("String replaced: %s\n", text);

    return 0;
}
