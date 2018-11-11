#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int dias[5][7] = {0},dia,producto,dia2,producto2;
int main(){
	/*
	for(int i=0;i<5;i++){
		for(int j=0;j<7;j++)
		{
			scanf("%i", &dias[i][j]);
		}
	}
	*/
	printf("Ingresa el ID del producto\n");
	scanf("%i", &producto);
	printf("Ingresa el numero de Dia");
	scanf("%i", &dia);
	if(producto<6){
		if(dia<8){
			printf("Ingresa la nueva venta\n");
			scanf("%i", &dias[producto][dia]);
			printf("La venta equivale a: %i \n", dias[producto][dia]);
		}	
	}else{
		printf("Ni madres we\n");
	}
		for(int i=0;i<5;i++){
		for(int j=0;j<7;j++)
			{
				printf("%i ", dias[i][j]);
			}
		printf("\n");
	}
	getch();d
	return 0;
}
