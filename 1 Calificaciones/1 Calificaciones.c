#include <stdio.h>
float cal_alu_ind[36];
float calmax(float cal_alu_ind1[]){
	int x;
	float cal_su=0;
	for(x=2;x<=36;x++){
		if(cal_alu_ind[x-1]<cal_alu_ind[x]){
			cal_su = cal_alu_ind1[x];
		}
	}
	return cal_su;
}
void recalif(){
	int x;
	char nom_alu[30];
	for(x=1;x<=36;x++){
		fflush(stdin);
		printf("Ingresa el nombre del alumno");
		scanf("%s",&nom_alu[36]);
		printf("Ingresa la calificación del alumno %i: ",x);
		scanf("%i",&cal_alu_ind);
	}
}
main(){
	float cal_su;
	recalif();
	printf("La calificación maxima es: %f",calmax());
}
