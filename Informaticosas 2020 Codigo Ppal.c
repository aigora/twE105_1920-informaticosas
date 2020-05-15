 #define_CRT_SECURE_NO_WARNINGS	
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>



struct usuario_estructura {
	char nombre[30];
	char apellido1[50];
	char apellido2[50];
	char usuarios_completo[20];
	char sexo;
	char nombre_usuario[25];
	char contrasena[25];
	int precio;
	int asiento;
	

};



struct teatro {
	int plazas; 
	char obra[20];
	
};

void registro(struct usuario_estructura usuarios_completo[], int i);


void ver_usuarios(struct usuario_estructura usuarios_completo[], int numero_usuarios);

int abrir(struct usuario_estructura usuarios_completo[], struct teatro obra [], int i);
void guardar(struct usuario_estructura usuarios_completo[], struct teatro obra[], int i);
void recordar(struct usuario_estructura usuarios_completo[], int i, FILE *pf);
void recordar_teatro(struct teatro obra[], int i, FILE *df);
//float reserva_entrada(struct usuario_estructura usuarios_completo[], struct teatro funcion[], int j);


void main() {
	struct usuario_estructura usuarios_completo[100];
	struct teatro obra[20];
	char iniciar_usuario[25], iniciar_contrasena[25], switch1, switch2, switch3, switch4;
	int  caso, aux, vol, eleccion;
	int numero_usuarios = 4;	//usuario i-ésimo (en el registro)
	int j;		//cliente j-ésimo (en el inicio sesion)
	int intentos = 0;	//Numero de intentos al iniciar sesión
	int k, x, z;		//Variables bucles;
	int destino, coso, cambio;
 
	numero_usuarios = abrir(usuarios_completo, obra, numero_usuarios);
	system("cls");
	
	while (1) {
		
	
		
		printf("----------TEATRO LA ULTIMA----------\n\n");
		printf("1 - Registro\n");
		printf("2 - Inicio sesion\n");
		printf("3 - Salir del programa.\n");
		scanf("%d", &switch1);
		switch (switch1) {
			//Para registrarse
		case 1:
			registro(usuarios_completo, numero_usuarios);
			numero_usuarios++;
			break;
			//Para iniciar sesion
		case 2:
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
					

					printf("Bienvenido %s %s %s.\n", usuarios_completo[j].nombre, usuarios_completo[j].apellido1, usuarios_completo[j].apellido2);
					printf("¿Qué operacion desea realizar?\n");
					printf("P - Ver perfil.\nC - Cancelar obras teatrales reservadas.\nE - Comprar entradas.\nS - Cerrar sesión.\n");
					getchar();
					scanf("%c", &switch4);
					switch (switch4) {
					case 'P':
						system("cls");
						printf("Bienvenido a su perfil.\n");
						printf("NOMBRE: %s\n", usuarios_completo[j].nombre);
						printf("APELLIDOS: %s %s\n", usuarios_completo[j].apellido1, usuarios_completo[j].apellido2);
						
						printf("SEXO: %c\n", usuarios_completo[j].sexo);
						
						printf("DINERO GASTADO: %.2f€\n", usuarios_completo[j].precio);
						
						
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
					case 'C':
						if (usuarios_completo[j].precio == 0) {
							printf("No hay ningúna obra teatral reservada\n");
							system("pause");
							break;
						}
						else if (usuarios_completo[j].precio != 0) {
						
								
								printf("Su obra no se ha podido cancelar\n");
								system("pause");
								break;
							}
						
						break;

					} //switch1	
				} while (switch4 != 'S');
				
				
				system("cls");
				
			case 3:
			printf("Saliendo del programa...\n");
			
			guardar(usuarios_completo, obra, numero_usuarios);
			exit (-1);
			break;
			}//switch
			
		
		}//while	
		

	}//main
		


void registro(struct usuario_estructura usuarios_completo[], int i) {
	int  aux_2 = 0, aux_1, k;
	char contrasena2[25], nada[2] = "-";
	system("cls");
	printf("------------------REGISTRARSE------------------\n");
	printf("Introducir nombre:\n");
	getchar();
	scanf("%s", usuarios_completo[i].nombre);
	printf("Introducir primer apellido:\n");
	getchar();
	scanf("%s", usuarios_completo[i].apellido1);
	printf("Introducir segundo apellido:\n");
	getchar();
	scanf("%s", usuarios_completo[i].apellido2);

	

	//Sexo
	printf("Introducir sexo Masculino 'M' o Femenino 'F':\n");
	do {
		getchar();
		scanf("%c", &usuarios_completo[i].sexo);
		if ((usuarios_completo[i].sexo != 'M' && usuarios_completo[i].sexo != 'F')) {
			printf("Opcion incorrecta\nIntroduzca de nuevo el sexo Masculino 'M' o Femenino 'F':\n");
		}
	} while (usuarios_completo[i].sexo != 'M' && usuarios_completo[i].sexo != 'F');

	//Usuario
	printf("Introducir nombre de usuario (máximo 25 caracteres):\n");
	aux_1 = 0;
	do {
		if (aux_1 == 1) {
			printf("El usuario ya es existente, por favor introduzcalo de nuevo\n");
		}
		getchar();
		scanf("%s", usuarios_completo[i].nombre_usuario);
		for (k = 0; k < i; k++) {
			if (strcmp(usuarios_completo[k].nombre_usuario, usuarios_completo[i].nombre_usuario) == 0) {
				aux_1 = 1;
				break;
			}
			else {
				aux_1 = 0;
			}
		}
	} while (aux_1 == 1);

	//Contraseña
	do {
		if (aux_2 == 1) {
			printf("Las contraseñas introducidas son distintas, por favor comience el proceso de nuevo\n");
		}
		printf("Introducir contraseña (máximo 25 caracteres):\n");
		do {
			getchar();
			scanf("%s", usuarios_completo[i].contrasena);
			if (strlen(usuarios_completo[i].contrasena) < 4) {
				printf("Su contraseña es muy insegura, por favor introduzca más de 3 caracteres\n");
			}
		} while (strlen(usuarios_completo[i].contrasena) < 4);
		printf("Introducir contraseña por segunda vez:\n");
		getchar();
		scanf("%s", contrasena2);
		if (strcmp(usuarios_completo[i].contrasena, contrasena2) != 0) {
			aux_2 = 1;
		}
		else {
			aux_2 = 0;
		}
	} while (aux_2 == 1);
	
	usuarios_completo[i].asiento = 0;
	system("cls");
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
	FILE * pf, *df;
	int k, z, x;
	pf = fopen("datos_ultimate.txt", "w");
	df = fopen("vuelos_ultimate.txt", "w");
	if (df == NULL || pf == NULL) {
		printf("Error al abrir el fichero\n");
		return;
	}   
	fprintf(pf, "%d \n", i);
	for (k = 0; k < i; k++) {
		fprintf(pf, "usuario no: %i %s %s %s %c %s %s %f %d %d %d %d %d %d\n", k, usuarios_completo[k].nombre, usuarios_completo[k].apellido1, usuarios_completo[k].apellido2, usuarios_completo[k].sexo, usuarios_completo[k].nombre_usuario, usuarios_completo[k].contrasena, usuarios_completo[k].precio, usuarios_completo[k].asiento);
			}

	for (z = 0; z < 20; z++) {
	
	
		fprintf(df, "\n");
	}
	fclose(pf);
	fclose(df);
}







void ver_usuarios(struct usuario_estructura usuarios_completo [], int numero_usuarios) {
	int k;
	for (k = 0; k < numero_usuarios; k++) {
		
		printf("%s %s %s <%s> (%c)\n\n", usuarios_completo[k].nombre, usuarios_completo[k].apellido1, usuarios_completo[k].apellido2, usuarios_completo[k].nombre_usuario, usuarios_completo[k].sexo);
	}//for
}
