#define _CRT_SECURE_NO_WARNINGS	

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <stdlib.h>


struct usuario_estructura {
	char nombre[30];
	char apellido1[50];
	char apellido2[50];
	//char usuarios_completo[20];
	char nom_usuario[25];
	char contrasena[25];
	int num_entradas;

};
struct teatro {
	int asientos; 
	char obra[50];	
};

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

void registro(struct usuario_estructura usuarios_completo[]/*, int i*/);
void ver_usuarios(struct usuario_estructura usuarios_completo[], int numero_usuarios);
int abrir(struct usuario_estructura usuarios_completo[], struct teatro obra [], int i);
void guardar(struct usuario_estructura usuarios_completo[], struct teatro obra[], int i);
void recordar(struct usuario_estructura usuarios_completo[], int i, FILE *pf);
void recordar_teatro(struct teatro obra[], int i, FILE *df);
//float reserva_entrada(struct usuario_estructura usuarios_completo[], struct teatro funcion[], int j);

void MostrarCartelera();


void main() {

	//system("CHCP 1252"); 
	struct usuario_estructura usuarios[50];
	struct teatro obra[20];
	char iniciar_usuario[25], iniciar_contrasena[25], switch2, switch3;
	int fin, n;
	int opcion;
	int  caso, aux, vol, eleccion;
	//int num_usuarios=0;	//Numero de usuarios totales.
	int j;		//cliente j-ésimo (en el inicio sesion)
	int intentos = 0;	//Numero de intentos al iniciar sesión
	int k, x, z;		//Variables bucles;
	int destino, coso, cambio;

	bool cont = true;

	numero_usuarios = abrir(usuarios_completo, obra, numero_usuarios);
	system("cls");

	while (cont) {
		fin = 0;
		n = 0;

		while (fin == 0) {
			inicio(i);

			switch (menuinicio()) {
				
			case 1: //REGISTRO
				registro(usuarios);
				
				break;
				
			case 2: //INICIO DE SESION
				intentos = 0;
				while (intentos < 5) {
					system("cls");
					intentos++;
					if (intentos == 4) {
						printf("Número de intentos agotados. Saliendo del programa...\n");
						guardar(usuarios_completo, obra, numero_usuarios);

					}
					printf("Número de intentos restantes: %d.\n", 4 - intentos);
					printf("Introducir usuario:\n");
					getchar();
					scanf("%s", iniciar_usuario);
					printf("Introducir contrasena:\n");
					getchar();
					scanf("%s", iniciar_contrasena);
					for (j = 0; j < numero_usuarios; j++) {
						if (strcmp(iniciar_usuario, usuarios_completo[j].nombre_usuario) == 0 && strcmp(iniciar_contrasena, usuarios_completo[j].contrasena) == 0) {
							intentos = 5;
							break;
						} //if
					} //for
				} //while
				system("cls");
				printf("Iniciando sesion\n");
				Sleep(500);
				system("cls");
				printf("Iniciando sesion .\n");
				Sleep(500);
				system("cls");
				printf("Iniciando sesion . .\n");
				Sleep(500);
				system("cls");
				printf("Iniciando sesion . . .\n");
				Sleep(500);

				do {
					system("cls");


					printf("Bienvenido %s %s.\n", usuarios_completo[j].nombre, usuarios_completo[j].apellido1);
					printf("¿Qué operacion desea realizar?\n");
					//printf("P - Ver perfil.\nC - Cancelar obras teatrales reservadas.\nE - Comprar entradas.\nS - Cerrar sesión.\n");
					printf("1 - Ver perfil\n");
					printf("2 - Comprar entradas\n");
					printf("3 - Obras Compradas\n");
					printf("4 - Puntos de Afiliado\n");
					getchar();
					scanf("%c", &opcion);

					switch (opcion) {
					case 1:
						system("cls");
						printf("Bienvenido a su perfil.\n");
						printf("NOMBRE: %s\n", usuarios_completo[j].nombre);
						printf("APELLIDOS: %s %s\n", usuarios_completo[j].apellido1, usuarios_completo[j].apellido2);
						


						if (usuarios_completo[j].asiento != 0)
							printf("BUTACA:%d\n", usuarios_completo[j].asiento);
						else
							printf("USTES NO TIENE BUTACAS RESERVADAS\n");
						printf("¿Desea volver al menu principal?\nA-Volver al Menú principal\n");
						getchar();
						scanf("%c", &switch2);
						if (switch2 == 'M') {
							printf("¿Que desea modificar?\nN-NOMBRE\nA-APELLIDOS\nS-SEXO\n");
							getchar();
							scanf("%c", &switch3);
							switch (switch3) {
							case 'N':
								printf("Introducir nuevo nombre: ");
								scanf("%s", usuarios_completo[j].nombre);

								break;
							case 'A':
								printf("Introducir primer apellido: ");
								getchar();
								scanf("%s", usuarios_completo[j].apellido1);
								printf("Introducir segundo apellido: ");
								getchar();
								scanf("%s", usuarios_completo[j].apellido2);

								break;

							case 'S':
								do {
									printf("Introduzca sexo Masculino(M), Feminimo(F)\n");
									getchar();
									scanf("%c", &usuarios_completo[j].sexo);
								} while (usuarios_completo[j].sexo != 'M' && usuarios_completo[j].sexo != 'F');

								break;
							} //switch2
						}
						else {
							break;
						}
						break;
					case 'E':
						if (usuarios_completo[j].precio != 0) {
							system("cls");
							printf("Ya tiene una obra reservada, si desea cancelar presione 'C' en el menú principal.\n");
							system("pause");
						}
						else {
							//	usuarios_completo[j].precio = reserva_entrada(usuarios_completo, obra, j);
						}
						break;
					

					} //switch1	
				} while (switch4 != 'S');


				system("cls");
            case 3: //VER CARTELERA
				MostrarCartelera();
			case 4: //SALIR DEL PROGRAMA
				printf("Saliendo del programa...\n");
				fin = 1;
				cont = false;
				guardar(usuarios_completo, obra, numero_usuarios);
				break;
			}//switch del menu principal
			
		}//while del fin	
		system("pause");
	}//while del booleano

}//salida del main

void registro(struct usuario_estructura usuarios_completo[]) {

	int  aux_2 = 0, aux_1, k;
	char contrasena2[25];
	int n = 0; //numero de usuarios

	system("cls");

	FILE *lista;
	lista = fopen("listaUsuarios.txt", "rb");

	n = fread(&usuarios_completo, sizeof(struct usuario_estructura), 50, lista); //devuelve el numero de usuarios que hay hasta el momento, n-1, por lo que el nuevo usuario será el numero n.
	printf("%d", n);
	fclose(lista);

	printf("------------------REGISTRARSE------------------\n");
	printf("Introducir nombre:\n");
	//gets(usuarios_completo[n].nombre);
	getchar();	scanf("%s", usuarios_completo[n].nombre);

	printf("Introducir primer apellido:\n");
	//gets(usuarios_completo[n].apellido1);
	getchar();	scanf("%s", usuarios_completo[n].apellido1);

	printf("Introducir segundo apellido:\n");
	//gets(usuarios_completo[n].apellido2);
	getchar();	scanf("%s", usuarios_completo[n].apellido2);


	//Usuario
	printf("Introducir nombre de usuario (máximo 25 caracteres):\n");
	aux_1 = 0;
	do {
		getchar();
		scanf("%s", usuarios_completo[n].nom_usuario);
		for (k = 0; k < n - 1; k++) {
			if (strcmp(usuarios_completo[n].nom_usuario, usuarios_completo[k].nom_usuario) == 0) {
				printf("El usuario ya es existente, por favor introduzca uno nuevo\n");
				aux_1 = 1;
				break;
			}
			else aux_1 = 0;
		}
	} while (aux_1 == 1);

	//Contraseña
	do {
		printf("Introducir contraseña (máximo 25 caracteres):\n");
		do {
			getchar();
			scanf("%s", usuarios_completo[n].contrasena);

			if (strlen(usuarios_completo[n].contrasena) < 4) {
				printf("Su contraseña es muy insegura, por favor introduzca más de 3 caracteres\n");
			}
		} while (strlen(usuarios_completo[n].contrasena) < 4);

		printf("Introducir contraseña por segunda vez:\n");
		getchar();
		scanf("%s", contrasena2);
		if (strcmp(usuarios_completo[n].contrasena, contrasena2) != 0) {
			printf("Las contraseñas introducidas son distintas, por favor comience el proceso de nuevo\n");
			aux_2 = 1;
		}
		else aux_2 = 0;

	} while (aux_2 == 1);

	system("cls");
	lista = fopen("listaUsuarios.txt", "wb");
	fwrite(&usuarios_completo, sizeof(struct usuario_estructura), n + 1, lista); //rescribimos en el fichero todos los usuarios antiguos mas el nuevo
	fclose(lista);
	printf("¡SE HA REGISTRADO CON EXITO!\n");
	printf("------------------------------\n");


}

int abrir(struct usuario_estructura usuarios_completo[], struct teatro obra[], int i) {
	FILE * pf, *df;
	int k;
	pf = fopen("datos_ultimate.txt", "r");
	fscanf(pf, "%d", &i);
	for (k = 0; k < i; k++) {
		recordar(usuarios_completo, k, pf);
	}
	df = fopen("vuelos_ultimate.txt", "r");
	for (k = 0; k < 20; k++) {
		recordar_teatro(obra, k, df);
	}
	fclose(pf);
	fclose(df);
	return i;
}
void recordar(struct usuario_estructura usuarios_completo[], int i, FILE *pf) {
	int k;
	if (pf == NULL) {
		printf("Error al abrir el fichero\n");
		return;
	}
	fscanf(pf, "usuario no: %i %s %s %s %c %s %s %f %d %d %d %d %d %d\n", k, usuarios_completo[k].nombre, usuarios_completo[k].apellido1, usuarios_completo[k].apellido2, usuarios_completo[k].sexo, usuarios_completo[k].nombre_usuario, usuarios_completo[k].contrasena, usuarios_completo[k].precio, usuarios_completo[k].asiento);
}
void recordar_teatro(struct teatro obra[], int i, FILE *df) {
	int z, k, x;
	if (df == NULL) {
		printf("Error al abrir el fichero\n");
		return;
	}
	
	
}
void guardar(struct usuario_estructura usuarios_completo[], struct teatro obra[], int i) {
	FILE *usuarios;
	int k;
	pf = fopen("datos_ultimate.txt", "w");
	if (pf == NULL) {
		printf("Error al abrir el fichero\n");
		return;
	}   
	fprintf(pf, "%d \n", i);
	for (k = 0; k < i; k++) {
		fprintf(pf, "usuario no: %i %s %s %s %s %s  %d %d %d %d\n", k, usuarios_completo[k].nombre, usuarios_completo[k].apellido1, usuarios_completo[k].apellido2,usuarios_completo[k].nombre_usuario, usuarios_completo[k].contrasena, usuarios_completo[k].asiento);
			}
	fclose(pf);
}

void ver_usuarios(struct usuario_estructura usuarios_completo [], int numero_usuarios) {
	int k;
	for (k = 0; k < numero_usuarios; k++) {
		
		printf("%s %s %s <%s> (%c)\n\n", usuarios_completo[k].nombre, usuarios_completo[k].apellido1, usuarios_completo[k].apellido2, usuarios_completo[k].nombre_usuario, usuarios_completo[k].sexo);
	}//for
}

void MostrarCartelera() {
	FILE *obras;
	obras = fopen("cartelera.txt", "rb");



}

void EditarCartelera() {
	struct teatro obras[3];
	int i;
	FILE *obras;
	obras = fopen("cartelera.txt", "wb");

	for (i = 0; i < 3; i++) {
		fflush(stdin);
		printf("Nombre de la Obra: \n");
		gets(obras[i].obra);

		printf("Numero de asientos: \n");
		scanf("%d", &obras[i].plazas);
	}
}
