  
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
struct Fecha {
	int dia;
	int mes;
	int a�o;
};

struct Usuario {
	char nombre[30];
	char apellido1[50];
	char apellido2[50];
	struct Fecha nacimiento;
	char nom_usuario[25];
	char contrase�a[25];
	char obras[20];//Dest
	float precio;
	int asiento;
	struct tm tu;
}

void registro(struct Usuario usuarios[], int i);


int menuinicio() {
	int opcion;	
	printf("1-Registrarse\n");
	printf("2-Inicio de Sesi�n.\n");
	printf("3-Ver Cartelera\n");
	printf("4-Salir del Programa\n");
	scanf("%d", &opcion);
	system("cls");

	return opcion;
}

char inicio(int n) {
	if (n == 0)
		printf("Bienvenido a Teatros la �ltima, introduzca la opcion que desee: \n");
	else (printf("Quiere hacer algo mas\n"));
}


void main() {
	system("chcp 1252");
	system("cls");
	struct Usuario usuarios[100];
	char iniciar_usuario[25], iniciar_contrasena[25], op, op2, op3, op4, viaje, cancel, nada[25] = "-", contramod[25], sitiamen[25];
	int fin, i;
	int j; //para n�mero de usuarios 
	int num_usuarios = 4;
	int aux;
	int l = 0;	//Numero de intentos al iniciar sesi�n
	int k, x, z;		//Variables para bucles;
	int destino, coso, cambio;

	bool cont = true; // El booleano lo utilizamos para salir del programa

	while (cont) {

		fin = 0; //
		i = 0;//reiniciamos las i a 0 cundo el cliente acaba de hacer una cosa y desea hacer mas
		while (fin == 0) {

			inicio(i); // la primera vez i = 0, por lo que saldr� el primer mensaje, mientras que si el cliente desea hacer algo m�s, i != 0, por lo que saldr� el segundo mensaje.
			switch (menuinicio()){
			case 1: {
			registro(usuarios, num_usuarios);
			num_usuarios++;
			break;
			 // Registrarse

			}
					break;
			case 2: {l = 0;
			while (l < 5) {
				system("cls");
				l++;
				if (l == 4) {
					printf("N�mero de intentos agotados. Saliendo del programa...\n");
					guardar(usuarios, vuelo, num_usuarios);
					return 0;
				}
				printf("N�mero de intentos restantes: %d.\n", 4 - l);
				printf("Introducir usuario:\n");
				getchar();
				scanf("%s", iniciar_usuario);
				printf("Introducir contrase�a:\n");
				getchar();
				scanf("%s", iniciar_contrasena);
				for (j = 0; j < num_usuarios; j++) {
					if (strcmp(iniciar_usuario, usuarios[j].nom_usuario) == 0 && strcmp(iniciar_contrasena, usuarios[j].contrase�a) == 0) {
						l = 5;
						break;
					} //if
				} //for
			} //while
			system("cls");
			printf("Iniciando sesi�n\n");
			Sleep(500);
			system("cls");
			printf("Iniciando sesi�n .\n");
			Sleep(500);
			system("cls");
			printf("Iniciando sesi�n . .\n");
			Sleep(500);
			system("cls");
			printf("Iniciando sesi�n . . .\n");
			Sleep(500);
			if (j < 3) {
				do {
					system("cls");
					printf("Bienvenido %s %s %s (Administrador).\n____________________________________________________\n\n", usuarios[j].nombre, usuarios[j].apellido1, usuarios[j].apellido2);
					system("color 0E");
					printf("Seleccione una opci�n:\n\n1 - Ver Usuarios Registrados\n\n2 - Modificar informaci�n usuario\n\n3 - Informaci�n sobre las obras\n\n4 - Cerrar Sesi�n\n");
					getchar();
					scanf("%d", &coso);
				// Men�	switch (coso) {
				 // Iniciar sesi�n
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
void registro(struct Usuario usuarios[], int i) {
	int  aux_2 = 0, aux_1, k;
	char contrasena2[25], nada[2] = "-";
	system("cls");
	printf("------------------REGISTRO------------------\n");
	printf("Introducir nombre:\n");
	getchar();
	scanf("%s", usuarios[i].nombre);
	printf("Introducir primer apellido:\n");
	getchar();
	scanf("%s", usuarios[i].apellido1);
	printf("Introducir segundo apellido:\n");
	getchar();
	scanf("%s", usuarios[i].apellido2);

	//Fecha de nacimiento
	printf("Introducir fecha de nacimiento:\n");
	printf("Introducir d�a:\n");
	do {
		getchar();
		scanf("%d", &usuarios[i].nacimiento.dia);
		if (usuarios[i].nacimiento.dia < 1 || usuarios[i].nacimiento.dia > 31) {
			printf("Introduzca de nuevo el d�a, por favor\n");
		}
	} while (usuarios[i].nacimiento.dia < 1 || usuarios[i].nacimiento.dia > 31);
	printf("Introducir mes:\n");
	do {
		do {
			if ((usuarios[i].nacimiento.dia == 31 && (usuarios[i].nacimiento.mes == 2 || usuarios[i].nacimiento.mes == 4 || usuarios[i].nacimiento.mes == 6 || usuarios[i].nacimiento.mes == 9 || usuarios[i].nacimiento.mes == 11)) || (usuarios[i].nacimiento.dia > 29 && usuarios[i].nacimiento.mes == 2)) {
				printf("Introduzca de nuevo el mes, por favor\n");
			}
			getchar();
			scanf("%d", &usuarios[i].nacimiento.mes);
		} while ((usuarios[i].nacimiento.dia == 31 && (usuarios[i].nacimiento.mes == 2 || usuarios[i].nacimiento.mes == 4 || usuarios[i].nacimiento.mes == 6 || usuarios[i].nacimiento.mes == 9 || usuarios[i].nacimiento.mes == 11)) || (usuarios[i].nacimiento.dia > 29 && usuarios[i].nacimiento.mes == 2));
		if (usuarios[i].nacimiento.mes < 1 || usuarios[i].nacimiento.mes > 12) {
			printf("Introduzca de nuevo el mes, por favor\n");
		}
	} while (usuarios[i].nacimiento.mes < 1 || usuarios[i].nacimiento.mes > 12);
	printf("Introducir a�o:\n");
	do {
		getchar();
		scanf("%d", &usuarios[i].nacimiento.a�o);
		if (usuarios[i].nacimiento.a�o < 1900 || usuarios[i].nacimiento.a�o > 2000) {
			printf("Introduzca de nuevo el a�o, por favor\n");
		}
	} while (usuarios[i].nacimiento.a�o < 1900 || usuarios[i].nacimiento.a�o > 2000);


	//Usuario
	printf("Introducir nombre de usuario (m�ximo 25 caracteres):\n");
	aux_1 = 0;
	do {
		if (aux_1 == 1) {
			printf("El usuario ya es existente, por favor introduzcalo de nuevo\n");
		}
		getchar();
		scanf("%s", usuarios[i].nom_usuario);
		for (k = 0; k < i; k++) {
			if (strcmp(usuarios[k].nom_usuario, usuarios[i].nom_usuario) == 0) {
				aux_1 = 1;
				break;
			}
			else {
				aux_1 = 0;
			}
		}
	} while (aux_1 == 1);

	//Contrase�a
	do {
		if (aux_2 == 1) {
			printf("Las contrase�as introducidas son distintas, int�ntelo de nuevo.\n");
		}
		printf("Introducir contrase�a (m�ximo 25 caracteres):\n");
		do {
			getchar();
			scanf("%s", usuarios[i].contrase�a);
			if (strlen(usuarios[i].contrase�a) < 4) {
				printf("Su contrase�a no es segura, por favor introduzca una de m�s de 3 caracteres\n");
			}
		} while (strlen(usuarios[i].contrase�a) < 4);
		printf("Introducir contrase�a por segunda vez:\n");
		getchar();
		scanf("%s", contrasena2);
		if (strcmp(usuarios[i].contrase�a, contrasena2) != 0) {
			aux_2 = 1;
		}
		else {
			aux_2 = 0;
		}
	} while (aux_2 == 1);
	strcpy(usuarios[i].dest, nada);
	usuarios[i].precio = 0;
	usuarios[i].asiento = 0;
	system("cls");
	printf("�SE HA REGISTRADO CON EXITO!\n");
	printf("------------------------------\n");
}

