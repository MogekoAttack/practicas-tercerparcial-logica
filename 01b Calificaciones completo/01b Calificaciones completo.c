#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <unistd.h>
int total_de_alumnos = 5,caracteres_totales = 1,contador_arriba_promedio = 0,contador_abajo_promedio = 0;
int alumnos_contados = 0,verificacion_menu=0,buscador;
float promedio_total,calificacion_alta = 0,calificacion_baja = 10,calificaciones[1];
char nombres[1][63];
//Funciones del programa
int calificacion_valida(float ver_cal){
	int val = 0;
	if(ver_cal>=0 && ver_cal<=10){
		val = 1;
	}
	return val;
}

void registrar_todos_alumnos(){
	int x1,correcto=0;
	for (x1=1;x1<=5;x1++){
		do{
			printf("Ingrese la calificación %i",x1);
			scanf("%f",&calificaciones[x1]);
			correcto = calificacion_valida(calificaciones[x1]);
			if(correcto==0){
				printf("\nIngrese una calificación válida");
				system("cls");
			}else{
				alumnos_contados++;
			}
		}while(correcto==0);
	}
}

void borrar_alumnos(){
	printf("Borrando a todos los alumnos, porfavor espere");
	alumnos_contados = 0;
	sleep(1);
}

void calificacion_alta_f(){
	int contador;
	for (contador=1;contador<=5;contador++){
		if(calificacion_alta<calificaciones[contador]){
			calificacion_alta = calificaciones[contador];
		}
	}
}

void calificacion_baja_f(){
	int contador;
	for (contador=1;contador<=5;contador++){
		if(calificacion_baja>calificaciones[contador]){
			calificacion_baja = calificaciones[contador];
		}
	}
}

void promedio_calificacion(){
	int contador;
	float pro_du=0;
	for(contador=1;contador<=5;contador++){
		pro_du = pro_du + calificaciones[contador];
	}
	promedio_total = pro_du/contador;
}

void contador_arriba_promedio_f(){
	int contador;
	for(contador=1;contador<=5;contador++){
		if(calificaciones[contador]>promedio_total){
			contador_arriba_promedio++;
		}
	}
}

void contador_abajo_promedio_f(){
	int contador;
	for(contador=1;contador<=5;contador++){
		if(calificaciones[contador]<promedio_total){
			contador_arriba_promedio++;
		}
	}
}

void reporte_completo(){
	calificacion_alta_f();
	calificacion_baja_f();
	promedio_calificacion();
	contador_arriba_promedio_f();
	contador_abajo_promedio_f();
	printf("Calificación mas alta es: %f\n",calificacion_alta);
	printf("Calificación mas baja es: %f \n",calificacion_baja);
	printf("El promedio es: %f \n",promedio_total);
	printf("Calificaciones arriba del promedio: %i \n",contador_arriba_promedio);
	printf("Calificaciones abajo del prmedio: %i \n",contador_abajo_promedio);
	printf("El resto de calificaciones: \n");
	int contador;
	for(contador=1;contador<=5;contador++){
		printf("El alumno %i tiene como calificación %f \n",contador,calificaciones[contador]);
	}
	system("pause");
}

//funcion principal
main(){
	//system("chcp 65001");
	setlocale(LC_ALL,"");
	int opcion;
	do{
		if(verificacion_menu==0){
			printf("No hay alumnos registrados en el sistema, ingrese 1 para entrar en el menú");
			scanf("%i",&verificacion_menu);
		}else if(verificacion_menu==1){
			system("cls");
			fflush(stdin);
			fflush(stdout);
			printf("Seleccione alguna opción\n");
			printf("1.- Ver el reporte completo de las calificaciones\n");
			printf("2.- Registrar a todos los alumnos\n");
			printf("3.- Borrar a todos los alumnos\n");
			printf("4.- Salir\n");
			scanf("%i",&opcion);
			system("cls");
			switch(opcion){
				case 1:
					if(alumnos_contados==0){
						printf("No hay alumnos\n");
						system("pause");
					}else{
						reporte_completo();
					}
				break;
				case 2:
					if(alumnos_contados!=0){
						printf("Algunos alumnos ya tiene calificación, favor de borrarlas para poder acceder a esta función\n");
						system("pause");
					}else{
						registrar_todos_alumnos();
					}
				break;
				case 3:
					borrar_alumnos();
				break;
				case 4:
					system("exit");
				break;
				default:
					printf("Ingrese algo correcto");
				break;
			}
		}
	}while(opcion!=4);
}
