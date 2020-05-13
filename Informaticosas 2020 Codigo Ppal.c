 #define	_CRT_SECURE_NO_WARNINGS	
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>

struct Usuario_estructura {
	char nombre[30];
	char apellido1[50];
	char apellido2[50];
	char usuarios_completo[20];
	char sexo;
	char nombre_usuario[25];
	char contrasena[25];
	

	

};

void registro(struct Usuario_estructura usuarios_completo[], int i);


void main() {
	struct Usuario_estructura usuarios_completo[100];

	char iniciar_sesion_usuario[25], iniciar_sesion_contrasena[25];
	
	int fichero_usuarios = 4;	//Espectador i-ésimo (registro)
	int j;		//Espectador j-ésimo (inicio sesion)
	int intentos = 0;	//Numero de intentos al iniciar sesión
 

	system("cls");
	
	while (1) {
		
	int eleccion;
		
		printf("----------TEATRO LA ULTIMA----------\n\n");
		printf("1 - Registrarse\n");
		printf("2 - Iniciar sesion\n");
		printf("3 - Entradas\n");
		printf("4 - Salir del programa.\n");
		scanf("%d", &eleccion);
		switch (eleccion) {
			//Para registrarse
		case 1:
			registro(usuarios_completo, fichero_usuarios);
			fichero_usuarios++;
			break;
			//Para iniciar sesion
		case 2:
			
			while (intentos < 5) {
				system("cls");
				intentos++;
					
		
				printf("Introducir usuario:\n");
				getchar();
				scanf("%s", iniciar_sesion_usuario);
				printf("Introducir contrasena:\n");
				getchar();
				scanf("%s", iniciar_sesion_contrasena);
				printf("\n");
				
				for (j = 0; j < fichero_usuarios; j++) {
					if (strcmp(iniciar_sesion_usuario, usuarios_completo[j].nombre_usuario) == 0 && strcmp(iniciar_sesion_contrasena, usuarios_completo[j].contrasena) == 0) {
						intentos = 5;
						
						break;
						
					} //if
					
					
				}//for
				    
					printf("Usuario incorrecto, intentelo otra vez. (%i intentos restantes)", 5-intentos);
					Sleep(2000);
			} //while
				
			//animacion iniciando sesion
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
			printf("Sesion Iniciada con exito!!");
			
			int opcion_inicio;
			
			if (j < 3) {
				do {
					system("cls");
					printf("Bienvenido %s %s %s .\n____________________\n\n", usuarios_completo[j].nombre, usuarios_completo[j].apellido1, usuarios_completo[j].apellido2);
					
				printf("Seleccione una opción:\n\n1 - Ver Usuarios Registrados\n\n2 - Modificar información reserva\n\n3 - Cerrar Sesión\n");
					getchar();
					scanf("%d", &opcion_inicio);
					switch (opcion_inicio) {
					case 1:
						system("cls");
						// ver_usuarios(usuarios_completo, fichero_usuarios);
						system("pause");
						break;
					case 2:
						// modificar_info(usuarios_completo, fichero_usuarios); 
						break;
					}//switch
					system("cls");
				} while (opcion_inicio != 3);
			}
			else {
				system("cls");
			
			}//else 
			
		case 4:
			printf("Saliendo del programa...\n");
		break;
		
			
			
		}//switch
		
	}//while
} //main


void registro(struct Usuario_estructura usuarios_completo[], int i) {
	int  aux_contrasena = 0, aux_usuario, k; // variables auxiliares para registro
	char contrasena_2a_vez[20]; // nada[2] = "-";
	system("cls");
	printf("------------------REGISTRO------------------\n");
	printf("Introducir nombre:\n");
	getchar();
	scanf("%s",usuarios_completo[i].nombre);
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
			printf("Introduzca de nuevo el sexo Masculino 'M' o Femenino 'F':\n");
		}
	} while (usuarios_completo[i].sexo != 'M' && usuarios_completo[i].sexo != 'F');

	//Usuario
	printf("Introducir nombre del usuario:\n");
	aux_usuario = 0;
	do {
		if (aux_usuario == 1) {
			printf("El usuario ya es existente, por favor introduzcalo de nuevo\n");
		}
		getchar();
		scanf("%s", usuarios_completo[i].nombre_usuario);
		for (k = 0; k < i; k++) {
			if (strcmp(usuarios_completo[k].nombre_usuario, usuarios_completo[i].nombre_usuario) == 0) {
				aux_usuario = 1;
				break;
			}
			else {
				aux_usuario = 0;
			}
		}
	} while (aux_usuario == 1);

	//Contraseña
	do {
		if (aux_contrasena == 1) {
			printf("Las contraseñas introducidas son distintas, por favor comience el proceso de nuevo\n");
		}
		printf("Introducir contrasena:\n");
		do {
			getchar();
			scanf("%s", usuarios_completo[i].contrasena);
			
		} while (strlen(usuarios_completo[i].contrasena) < 4);
		printf("Introducir contrasena por segunda vez: (comprobacion)\n");
		getchar();
		scanf("%s", contrasena_2a_vez);
		if (strcmp(usuarios_completo[i].contrasena, contrasena_2a_vez) != 0) {
			aux_contrasena = 1;
		}
		else {
			aux_contrasena = 0;
		}
	} while (aux_contrasena == 1);
	
	system("cls");
	printf("¡SE HA REGISTRADO CON EXITO!\n");
	printf("------------------------------\n");
}



