#include<stdio.h>
void aggiorna(char filenome[],int numstudenti){
FILE* fin;
FILE* fout;
 char voto[10];
 int matricola;
 int i;
 fin =fopen(filenome,"r");
 if(fin==NULL){
 	printf("error apertura file");
 	return;
 }
 fout=fopen("coppia.txt","w");
 if(fout==NULL){
 	printf("error apertura file");
 	return;
}
fprintf(fout,"%s\n","matricola voto");
for(i=0;i<numstudenti;i++){
	fscanf(fin,"%d",&matricola);
	fprintf(fout,"%d ",matricola);
	fscanf(fin,"%s",voto);
	fprintf(fout,"%s\n",voto);
	
}
fclose(fin);
fclose(fout);
}
void gestifile(char nomefile[],float *mediastudenti,int *rimandati){
 FILE* fin;
 FILE* fout;
 char temp[20];
 int matricola;
 int numstudenti;
 float voto;
 int sufficenti=0;
 float sommavoti=0;
 int i;
 fin =fopen(nomefile,"r");
 if(fin==NULL){
 	printf("error apertura file");
 	return;
 }
 fout=fopen("matricolavoti.txt","w");
 if(fout==NULL){
 	printf("error apertura file");
 	return;
 }
 	fscanf(fin,"%s",temp);
 	fscanf(fin,"%d",&numstudenti);
 	for(i=0;i<7;i++){
 		fscanf(fin,"%s",temp);
	 }
	 for(i=0;i<numstudenti;i++){
	 	fscanf(fin,"%d",&matricola);
	 	fprintf(fout,"%d ",matricola);
	 	fscanf(fin,"%s",temp);
	 	fscanf(fin,"%s",temp);
	 	fscanf(fin,"%f",&voto);
	 	if(voto<18){
	 		fprintf(fout,"%s\n","INS");
	 		(*rimandati)++;
		 }
		if(voto>30){
			fprintf(fout,"%s\n","30l");
			sommavoti=sommavoti+voto;
			sufficenti++;
		}
		if(voto>18&&voto<30){
			sufficenti++;
			fprintf(fout,"%f\n",voto);
			sommavoti=sommavoti+voto;
		}
	 }
	 fclose(fin);
	 fclose(fout);
	 if(sufficenti>0){
	 	*mediastudenti=sommavoti/sufficenti;
	 }
	 else{
	 
	 *mediastudenti=0;
}
aggiorna("matricolavoti.txt",numstudenti);
}

int main(){
 	float mediastudenti;
	int rimandati;
gestifile("votistudenti.txt",&mediastudenti,&rimandati);
 return 0;
}
