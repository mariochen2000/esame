#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_NEONATI 100

typedef struct {
    char nome[MAX_NAME_LENGTH];
    char cognome[MAX_NAME_LENGTH];
    char sesso;
    char data_di_nascita[11]; // Per includere anche il carattere di terminazione della stringa ('\0')
} Neonato;

// Funzione per gestire il registro di nascita
int gestioneRegistroNascita(char filename[]) {
    FILE* file = fopen(filename, "r");
    FILE* out;
    if (file == NULL) {
        printf("Errore nell'apertura del file.\n");
        return -1;
    }

    char nomi[100][100];
	int numnondub=0; 
    int numeronomi = 0;
    int k;
    int i;

    Neonato neonati[MAX_NEONATI]; 
    int numeroNeonati = 0;
    char buff[100];
    fscanf(file,"%s",buff);
    fscanf(file,"%d",&numeronomi);
    for(i=0;i<4;i++){
    	fscanf(file,"%s",buff);
	}
	for(i=0;i<numeronomi;i++){
		fscanf(file,"%s",neonati[i].nome);
		fscanf(file,"%s",neonati[i].cognome);
		fscanf(file, " %c", &neonati[i].sesso);
		fscanf(file,"%s",neonati[i].data_di_nascita);
		if(neonati[i].sesso=='F'&&strstr(neonati[i].data_di_nascita,"2022")!=NULL){
			int dublicato=0;
			for(k=0;k<i&&dublicato==0;k++){
				if(strcmp(neonati[k].nome,neonati[i].nome)==0){
					dublicato=1;
				}
				
			}
			if(dublicato==0){
			strcpy(nomi[numnondub], neonati[i].nome);
			numnondub++;
		}
		
		}
	}
	fclose(file);
    out = fopen("xxxx.txt", "w");
    if (file == NULL) {
        printf("Errore nell'apertura del file.\n");
        return -1;
    }

    fprintf(file, "Nomi");
    for (int i = 0; i < numnondub; i++) {
        fprintf(file, " %s", nomi[i]);
    }
    fprintf(file, "\n");

    fclose(out);

    return numnondub;
}

int main() {
   char filename[] = "registro_nascita.txt";
    int numeroNeonati = gestioneRegistroNascita(filename);

    if (numeroNeonati >= 0) {
        printf("Numero totale di neonati nel registro: %d\n", numeroNeonati);
    }

    return 0;
}
