#include <stdio.h>

void stequal(char *st1, char *st2, int *p) {
    while (*st1 != '\0' && *st2 != '\0') {
        if (*st1 != *st2) {
            *p = 1;
            return;
        }
        st1++;
        st2++;
    }
    if (*st1 == *st2)
        *p = 0;
    else
        *p = 1;
}

int countOccurrences(char *text, char *wind) {
    int count = 0;
    int len_text = 0;
    int len_wind = 0;
    int r;
    int k;
    while (*text != '\0') {
        len_text++;
        text++;
    }
    while (*wind != '\0') {
        len_wind++;
        wind++;
    }
    text -= len_text;
    wind -= len_wind;
    for (int i = 0; i <= len_text - len_wind; i++) {
        char *temp = text + i;
        int isMatch = 0;
        r=0;
        for (int j = 0; j < len_wind; j++) {
            if (*(temp + j) != *(wind + j)) {
                isMatch = 1;
                break;
            }
        }
        if (isMatch == 0){
		
          
            count++;
			}
       }
		
		return count;
    }

int main() {
    char text[] = "the quick brown fox jumps over the lazy dog";
    char wind[] = "the";
    int cont=0;
 cont=countOccurrences(text, wind);
    printf("Numero di occorrenze di '%s' in '%s': %d", wind, text,cont);
    return 0;
}