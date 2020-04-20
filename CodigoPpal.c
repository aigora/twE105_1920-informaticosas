#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int menuinicio() {
	int opcion;	
	printf("1-Registrarse\n");
	printf("2-Inicio de Sesión.\n");
	printf("3-Ver Cartelera\n");
	printf("4-Salir del Programa\n");
	scanf("%d", &opcion);
	system("cls");

	return opcion;
}

char inicio(int n) {
	if (n == 0)
		printf("Bienvenido a Teatros la ültima, introduzca la opcion que desee: \n");
	else (printf("Quiere hacer algo mas\n"));
}


void main() {
	//system("chcp 1252");
	int fin, i;

	bool cont = true; // El booleano lo utilizamos para salir del programa

	while (cont) {

		fin = 0; //
		i = 0;//reiniciamos las i a 0 cundo el cliente acaba de hacer una cosa y desea hacer mas
		while (fin == 0) {

			inicio(i); // la primera vez i = 0, por lo que saldrá el primer mensaje, mientras que si el cliente desea hacer algo más, i != 0, por lo que saldrá el segundo mensaje.
			switch (menuinicio()){
			case 1: { // Registrarse

			}
					break;
			case 2: { // Iniciar sesión
				fin = 1; //el cliente acaba de hacer todo y el  porgrama vuelve a empezar de 0, se sale del while(fin == 0)
			}
					break;
			case 3: { // Ver cartelera
				
			}
					break;
			case 4: {
				fin = 1;
				cont = false;// booleano
			}
					break;
			default:
				printf("Opcion incorrecta\n");
			}//salimos del switch
		}//while de fin
	}//while del booleano
}//salir del main