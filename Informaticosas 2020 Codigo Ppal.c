#define _CRT_SECURE_NO_WARNINGS	

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_USUARIOS 50  //constantes globales: las podemos cambiar si queremos cambiar el numero de obras o usuarios.
#define MAX_OBRAS 10


struct usuario_estructura { //datos de cada usuario
	char nombre[30];
	char apellido1[50];
	char apellido2[50];
	char nom_usuario[25];
	char contrasena[25];
	int num_entradas; // numero de entradas total que ha comprado el usuario

};
struct teatro { //datos de cada obra
	int asientos; //numero de asientos disponibles 
	char obra[50]; // nombre de la obra
};

void logo() {
	printf("WWWWWWWWWWWN0koc;'..        ..';lkXWWWWWWWWWWWWWWWWWWWWWWWWW"
		"\nWWWWWWWX0d:'.                    .lXWWWWWWWWWWWWWWWWWWWWWWWW"
		"\nWWWWXkl'.                         .xWWWWWWWWWWWWWWWWWWWWWWWW"
		"\nWWKd,                              ;KWWWWWWWWWWWWWWWWWWWWWWW"
		"\nXx'                                .dWWWWWWWWWWWWWWWWWWWWWWW"
		"\nl.                                  :XWWWWWWWWWWWWWWWWWWWWWW"
		"\n                                    .kWWWWWWWWWWWWWWWWWWWWWW"
		"\n.                    'dOOkxdl'.     .dWWWWWWWWWWWWWWWWWWWWWW"
		"\no.           .:d;     ,dKXNNKkddxxkkkKWWWWWWWWWWWWWWWWWWWWWW"
		"\nXc         .l0NXc       .:OX0kdolc:::cloxOKNWWWWWWWWWWWWWWWW"
		"\nWK;       ,kXNKo.       .xXx'            ..,cdOXWWWWWWWWWWWW"
		"\nWW0;      .','.        .xXx.                  .'cxKNWWWWWWWW"
		"\nWWW0:                .,xXx.                       .:xKWWWWWW"
		"\nWWWWKc            .cx0XNk.                           .l0NWWW"
		"\nWWWWWXd.        .oK0x0WO'                              .l0WW"
		"\nWWWWWWNO:      .kXd';0K:      .'lxkkd;                   .xN"
		"\nWWWWWWWWXx'    .,, .xNd.        .:okKKl.                  .o"
		"\nWWWWWWWWWWXd,      :X0,             .,,.                   ."
		"\nWWWWWWWWWWWWXkc.  .dNd.                    ;dkko'           "
		"\nWWWWWWWWWWWWWWWKxllKX:      ,oo;            ,oKNK:         :"
		"\nWWWWWWWWWWWWWWWWWWWW0'      lNWXk:.           .;do.      .oX"
		"\nWWWWWWWWWWWWWWWWWWWWO.      oNWWWN0o,.                  'xNW"
		"\nWWWWWWWWWWWWWWWWWWWWO.      cXWWWWWWNKkoc;'.          .c0WWW"
		"\nWWWWWWWWWWWWWWWWWWWWK,      .kNWWWWWWWWWWNKd'        'xNWWWW"
		"\nWWWWWWWWWWWWWWWWWWWWNl       .:oKWWWWWNKkl,        .oKWWWWWW"
		"\nWWWWWWWWWWWWWWWWWWWWWO'         .;cllc;.         .oKWWWWWWWW"
		"\nWWWWWWWWWWWWWWWWWWWWWNd.                      .,dKWWWWWWWWWW"
		"\nWWWWWWWWWWWWWWWWWWWWWWNo.                  .'lOXWWWWWWWWWWWW"
		"\nWWWWWWWWWWWWWWWWWWWWWWWNx'             .':oOXWWWWWWWWWWWWWWW"
		"\nWWWWWWWWWWWWWWWWWWWWWWWWW0;.       ..;okXNWWWWWWWWWWWWWWWWWW\n\n\n\n\n");
}

int menuinicio(int codigo) { //le pasamos el codigo de usuario
	int opcion;

	if (codigo == -1) {	//menu que saldra para usuarios no registrados
		printf("1-Registrarse\n");
		printf("2-Inicio de Sesión.\n");
		printf("3-Ver Cartelera\n");
		printf("4-Salir del Programa\n");

		scanf("%d", &opcion);
	}
	else { //menu que saldrá a los usuaris que ya se han registardo
		printf("1-Ver Perfil\n");
		printf("2-Comprar entradas\n");
		printf("3 - Salir\n");
		scanf("%d", &opcion);
		opcion += 4; // Para hacerlo bonito y no quitar el 1 y el 2, pero que no se confunda con el 1 y el 2 de el otro.

	}

	return opcion;
}

char inicio(int n) { // n es el numero de iteraciones que se hacen 
					 //system("cls");
	if (n == 0) {// al empezar el programa, te sale el mensaje inicial
		logo();
		printf("Bienvenidos al Teatro La Ultima, introduzca la opcion que desee: \n");
	}
	else {
		(printf("Quiere hacer algo mas\n"));
	}
}


void registro(struct usuario_estructura usuarios_completo[], int *n);
void login(struct usuario_estructura usuarios_completo[], int n, int *codigo, struct teatro cartelera[], int num_obras, int *fin, bool *cont);
void showCartelera(struct teatro cartelera[], int i);
void seeProfile(struct usuario_estructura usuarios_completo[], int codigo);
void comprarObra(struct usuario_estructura usuarios_completo[], int codigo, struct teatro cartelera[], int num_obras);
void exitProg(struct usuario_estructura usuarios_completo[], int *fin, bool *cont, struct teatro cartelera[], int num_obras);

void main() {
	system("CHCP 1252");//Código para que se puedan imprimir caracteres especiales, como letras con tildes y ñ 

	system("COLOR F0");//Código para cambiar el color del fondo (1er dígito) y de las letras (2o digito) (0 = Negro, 1 = Azul, 2 = Verde, 3 = Aqua, 4 = Rojo, 5 = Púrpura, 6 = Amarillo, 7 = Blanco, 8 =Gris, 9 = Azul Claro, A = Luz Verde, B = Aqua Luz, C = Rojo, D = Luz Violeta, E = = Amarillo Claro, F = Blanco Brillante) 


	struct usuario_estructura usuarios[MAX_USUARIOS]; // vector de estructuras que guarda los USUARIOS
	struct teatro cartelera[MAX_OBRAS];//vector de estructuras que guarda las OBRAS
	int fin, n; //variables para el fin de programa y numero de iteraciones
	int opcion; // opcion del menu principal
	int cod_usuario = -1; //codigo que tiene cada usuario , lo inicializamos a -1 porque significa que aun no se ha iniciado ninguna sesion, ya que el primer registrado tendra el 0
	int num_usuarios = 0;//Numero de usuarios totales.
	int num_obras = 0; // NUmero de obras. 
	int l = 2; // numero de variables que lee el scanf por linea de fichero lo inicializamos a 2 para que se meta en el while (posible cambio a do-while)

	bool cont = true; //inicializamos el bool a 1

	FILE *f_usuarios, *f_obras;
	f_usuarios = fopen("listaUsuarios.txt", "rb"); //abrimos el fichero con los usuarios
	f_obras = fopen("cartelera.txt", "r"); //abrimos fichero con las obras

										   //COPIAMOS DATOS DEL FICHERO USUARIOS A EL VECTOR DE ESTRUCTURAS
	num_usuarios = fread(usuarios, sizeof(struct usuario_estructura), MAX_USUARIOS, f_usuarios); //devuelve el numero de usuarios que hay hasta el momento, n-1, por lo que el nuevo usuario será el numero n.

																								 //copiamos los datos del fichero CARTELERA a el vector CARTELERA
	while (num_obras < MAX_OBRAS) { //solo copiamos al vector el numero de obras que puede abarcar

		l = fscanf(f_obras, "%d %50[^\n]", &cartelera[num_obras].asientos, cartelera[num_obras].obra); //la funcion fscanf devuuelve el numero de variables que lee por linea de fichero, en nuestro caso tiene los asientos y el nombre la obra.
		if (l == 2) {
			num_obras++; // solo sumamos al numero de obras si l=2, porque si no las lineas del fichero que no están escritas tambien las sumara al numero de obras.
		}
		else break; //en el momento que l !=2, se sale del while y deja de copiar
	}

	fclose(f_usuarios); //cerramos ambos ficheros
	fclose(f_obras);

	while (cont) { //cuando el booleano se cambie a 0 (false) , se cierra el programa
		fin = 0;
		n = 0;

		while (fin == 0) {
			inicio(n);
			n = 1;//como ya ha iniciliazado una vez, se cambia a 1 para que muestre el otro mensaje de inicio
			switch (menuinicio(cod_usuario)) { //le pasamos el codigo de usuario, para que muestre un menu u otro dependiendo si ha iniciado sesion

			case 1: //REGISTRO
				registro(usuarios, &num_usuarios); //le pasamos por referencia el numero de usuarios, porque la funcion le cambiara el valor cuando se regustre un usuario mas
				break;

			case 2: //INICIO DE SESION
				login(usuarios, num_usuarios, &cod_usuario, cartelera, num_obras, &fin, &cont); //el valor del codigo de usuario lo va a modificar la función  por ello, puntero
																								//printf("%d\n", cod_usuario); //comprobacion
				break;

			case 3: //VER CARTELERA
				showCartelera(cartelera, num_obras);
				break;

			case 4: //SALIR DEL PORGRAMA
			case 7: //SALIR DEL PROGRAMA
				exitProg(usuarios, &fin, &cont, num_usuarios, cartelera, num_obras);
				break;

			case 5: // VER PERFIL
				seeProfile(usuarios, cod_usuario);
				break;
			case 6://COMPRAR ENTRADAS
				showCartelera(cartelera, num_obras);
				comprarObra(usuarios, cod_usuario, cartelera, num_obras);
				break;


			default:  printf("Esta opción no es válida. PRUEBE DE NUEVO\n");
			}//switch del menu principal

		}//while del fin	
		system("pause");
	}//while del booleano

}//salida del main

void registro(struct usuario_estructura usuarios_completo[], int *n) {

	int  aux_2 = 0, aux_1, k;
	char contrasena2[25];

	system("cls");


	printf("------------------REGISTRARSE------------------\n");
	printf("Introducir nombre:\n");
	scanf("%s", usuarios_completo[*n].nombre);


	printf("Introducir primer apellido:\n");
	getchar();	scanf("%s", usuarios_completo[*n].apellido1);

	printf("Introducir segundo apellido:\n");
	getchar();	scanf("%s", usuarios_completo[*n].apellido2);

	usuarios_completo[*n].num_entradas = 0; //el numero de entradas  compradas cuando te regitras es 0 siempre

											//Usuario
	printf("Introducir nombre de usuario (máximo 25 caracteres):\n");
	aux_1 = 0;
	do {
		getchar();
		scanf("%s", usuarios_completo[*n].nom_usuario);
		for (k = 0; k < *n; k++) { //comparamos el el nombre de usuario no está ya cogido por otra persona
			if (strcmp(usuarios_completo[*n].nom_usuario, usuarios_completo[k].nom_usuario) == 0) {
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
			scanf("%s", usuarios_completo[*n].contrasena);

			if (strlen(usuarios_completo[*n].contrasena) < 4) {
				printf("Su contraseña es muy insegura, por favor introduzca más de 3 caracteres\n");
			}
		} while (strlen(usuarios_completo[*n].contrasena) < 4);

		printf("Introducir contraseña por segunda vez:\n");
		getchar();
		scanf("%s", contrasena2);
		if (strcmp(usuarios_completo[*n].contrasena, contrasena2) != 0) {
			printf("Las contraseñÃ±as introducidas son distintas, por favor comience el proceso de nuevo\n");
			aux_2 = 1;
		}
		else aux_2 = 0;

	} while (aux_2 == 1);
	(*n)++; //aumentar usuarios //aumentamos el numero de usuario una vez que el registro se ha hecho con exito.

	printf("¡SE HA REGISTRADO CON EXITO!\n");
	printf("------------------------------\n");
	Sleep(500);
	system("cls");

}
void login(struct usuario_estructura usuarios_completo[], int n, int *codigo, struct teatro cartelera[], int num_obras, int *fin, bool *cont) {
	int intentos = 0;
	//int n = 0; // numero de usuarios guardados en el fichero
	int j = 0;
	char logusuario[25], logcontr[25];

	//PODEMOS ABRIR LOS FICHEROS EN CADA FUNCION, PERO ES MAS RAPIDO ANTES DE EMPEZAR EL PROGRAMA

	while (intentos < 5) {
		system("cls");
		intentos++;
		if (intentos == 4) {
			printf("Número de intentos agotados. Saliendo del programa...\n"); //como el programa se acaba si te equivocas de contraseÃ±a, hay que pasar todas las variables a la funcion exitProg, que al estar dentro de otra funcion, hay que pasarle tambien a la funcion login todo las variables
			exitProg(usuarios_completo, n, fin, cont, n, cartelera, num_obras);  //no ponemos & delante de fin ni del booleano porque ya estamos pasando por refencia porque estamos dentro de otra funcion a la que ya le hemos hecho el paso por referenca de tales variables
		}

		printf("Número de intentos restantes: %d.\n", 4 - intentos);
		printf("Introducir usuario:\n");
		getchar();
		scanf("%s", logusuario);
		printf("Introducir contraseña:\n");
		getchar();
		scanf("%s", logcontr);
		for (j = 0; j < n; j++) {
			if (strcmp(logusuario, usuarios_completo[j].nom_usuario) == 0 && strcmp(logcontr, usuarios_completo[j].contrasena) == 0) {
				*codigo = j; //El numero de registrado del usuario que login. Como estamos editando el valor, y queremos que luego en el main mantenga el valor, usamos punteros.
				printf("%d", *codigo); //comprobacion
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
}
void showCartelera(struct teatro cartelera[], int i) {
	int n = 0;
	//system("cls");
	printf("------------------OBRAS------------------\n");
	for (n = 0; n < i; n++) {
		printf("Codigo de la obra: %d \n", n + 1); //el codigo de la obra es su posicion en el vector
		printf("OBRA: %s \n", cartelera[n].obra);
		printf("Numero de asientos disponibles: %d \n", cartelera[n].asientos);
		printf("\n");
	}
	//Esto lo utlizamos para que no salga el menu mientras se muestran las obras por pantalla
	getchar();
	printf("-----------------------------------------");
	getchar();
}
void seeProfile(struct usuario_estructura usuarios_completo[], int codigo) {

	system("cls");
	printf("------PERFIL DE USUARIO------\n");
	printf("Nombre:  %s\n", usuarios_completo[codigo].nombre);
	printf("Apellidos:  %s %s\n", usuarios_completo[codigo].apellido1, usuarios_completo[codigo].apellido2);
	printf("Codigo Usuario:  %d\n ", codigo); // el código que ha modificado la funciónlogin y que ya tien el valor de la posicion del usuario en el vector de estructuras
	printf("Numero de entradas compradas:  %d\n", usuarios_completo[codigo].num_entradas);

	getchar();
	printf("------------------------------");
	getchar();

	system("cls");
}
void comprarObra(struct usuario_estructura usuarios_completo[], int codigo, struct teatro cartelera[], int num_obras) {
	int cod_obra = 0;
	int entradas = 0;

	printf("-------COMPRA DE ENTRADAS------- \n");

	printf("Introduzca el CÓDIGO de la obra que quiere comprar:\n");
	scanf("%d", &cod_obra);

	while (cod_obra > num_obras) {
		printf("Ese código no correspone a ninguna obra.\n");
		printf("Vuelve a introducir el código: \n");
		scanf("%d", &cod_obra);
	}
	printf("Usted ha elegido la obra: %s \n", cartelera[cod_obra - 1].obra); // restamos 1 porque estan almacenadas desde el 0 pero para que en el menú quedé bonito, le hemos sumado 1.

	printf("¿Cuantas entradas desea comprar? \n");
	scanf("%d", &entradas);
	while (entradas >= cartelera[cod_obra - 1].asientos) {
		printf("No hay ese número de asientos disponibles.\n");
		printf("Vuelve a introducir el número de entradas que desea comprar: \n");
		scanf("%d", &entradas);
	}

	printf("Usted ha comprado %d entradas para la obra: %s \n", entradas, cartelera[cod_obra - 1].obra);
	printf("-------------------------------- \n");
	Sleep(500); //para que antes de que borre consola, espere unos segundos para poder ver el mensaje anterior
	usuarios_completo[codigo].num_entradas += entradas; // sumamos las entradas compradas a el total de entradas compradas por el usuario
	cartelera[cod_obra - 1].asientos -= entradas; // restamos las entradas compradas por el usuario al numero total de entradas disponibles 

	system("cls");
}
void exitProg(struct usuario_estructura usuarios_completo[], int *fin, bool *cont, int num_usuarios, struct teatro cartelera[], int num_obras) {
	int aux = 0;

	printf("Saliendo del programa...\n");

	FILE *f_usuarios, *f_cartelera; //volvemos a abrir los ficheros
	f_usuarios = fopen("listaUsuarios.txt", "wb");
	f_cartelera = fopen("cartelera.txt", "w");

	//COPIAMOS TODOS LOS CAMBIOS Y LO QUE NO HA SIDO CAMBIADO OTRA VEZ A LOS FICHEROS
	fwrite(usuarios_completo, sizeof(struct usuario_estructura), num_usuarios, f_usuarios); //reescribimos en el fichero todos los usuarios antiguos mas el nuevo
	for (aux = 0; aux < num_obras; aux++) {//copiamos linea a linea al fichero que guarda las obras, hasta que llega al numero total de obras
		fprintf(f_cartelera, "%d %s\n", cartelera[aux].asientos, cartelera[aux].obra);
	}

	fclose(f_usuarios); //ceramos los ficheros
	fclose(f_cartelera);
	*fin = 1; // cambiamos lo valores de fin y el booleano para que el programa se cierre (como queremos utilizar el nuevo valor en el main, usamos punteros)
	*cont = false;
}

