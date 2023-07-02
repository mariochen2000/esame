#include <stdio.h>
#include <string.h>

struct sq {
    char nome[15];
    int ptn;
};

int strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int getMaxPtn(struct sq v[], int size) {
    int maxPtn = v[0].ptn;
    for (int i = 1; i < size; i++) {
        if (v[i].ptn > maxPtn) {
            maxPtn = v[i].ptn;
        }
    }
    return maxPtn;
}

void sortStructArray(struct sq v[], int size) {
    struct sq temp;
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (strcmp(v[i].nome, v[j].nome) < 0) {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

int main() {
    struct sq v[] = {
        {"John", 10},
        {"Alice", 15},
        {"Bob", 12},
        {"Emma", 8}
    };
    int size = sizeof(v) / sizeof(v[0]);
    
    sortStructArray(v, size);
    
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("Nome: %s, Ptn: %d\n", v[i].nome, v[i].ptn);
    }
    
    int maxPtn = getMaxPtn(v, size);
    printf("Max Ptn: %d\n", maxPtn);
    
    return 0;
}