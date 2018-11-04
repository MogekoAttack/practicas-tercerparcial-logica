#include <stdio.h>
#include <wchar.h>
#include <locale.h>
int total_de_alumnos = 1,caracteres_totales = 1,contador_arriba_promedio = 0,contador_abajo_promedio = 0;
int alumnos_contados = 0,verificacion_menu=0;
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
	system("cls");
	int x,correcto=0;
	for (x=1;x<=2;x++){
		while(correcto==0){
			printf("Ingrese la calificaci�n %i",x);
			scanf("%f",&calificaciones[x]);
			correcto = calificacion_valida(calificaciones[x]);
			if(correcto!=1){
				printf("\n\nInserte una calificaci�n v�lida\n");
				system("cls");
			}else{
				alumnos_contados++;
			}
		}
	}
}
//funcion principal
main(){
	//system("chcp 65001");
	setlocale(LC_ALL,"");
	int opcion;
	do{
		if(verificacion_menu==0){
			printf("No hay alumnos registrados en el sistema, ingrese 1 para entrar en el men�");
			scanf("%i",&verificacion_menu);
		}else if(verificacion_menu==1){
			system("cls");
			fflush(stdin);
			fflush(stdout);
			printf("Seleccione alguna opci�n\n");
			printf("1.- Ver el reporte completo de las calificaciones\n");
			printf("2.- Registrar a todos los alumnos\n");
			printf("3.- Registrar a un solo alumno\n");
			printf("4.- Modificar a un alumno\n");
			printf("5.- Borrar a todos los alumnos\n");
			printf("6.- Salir\n");
			scanf("%i",&opcion);
			switch(opcion){
				case 1:
					
				break;
				case 2:
					if(alumnos_contados!=0){
						printf("Algunos alumnos ya tiene calificaci�n, favor de borrarlas para poder acceder a esta funci�n\n");
						system("pause");
					}else{
						registrar_todos_alumnos();
					}
				break;
				case 3:
				break;
				case 4:
				break;
				case 5:
				break;
				case 6:
					system("exit");
				break;
				default:
					printf("Ingrese algo correcto");
				break;
			}
		}
	}while(opcion!=6);
}