#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifdef MATRICES
#include "matrices/pila.h"
#include "matrices/cola.h"
#elif LISTA_ENLAZADA
#include "listaEnlazada/pila.h"
#include "listaEnlazada/cola.h"
#endif


#define DIM 82


int   palindromo (const char *);
void  convertir_mayusculas (char *);

int main (void)
{
	char cadena[DIM];
	int  espalindromo;

	printf("Introduzca una cadena (max. %d caracteres): ", DIM-2);
	fgets(cadena, DIM - 2, stdin);

	//Eliminamos el carácter retorno de carro leído por fgets
	int l = strlen(cadena);
	cadena[l - 1] = '\0';

	convertir_mayusculas (cadena);
	espalindromo = palindromo (cadena);

	printf("La cadena %s \n", cadena);
	if (espalindromo)
		printf("es un palindromo.\n");
	else
		printf("NO es un palindromo.\n");

	return 0;

}


void convertir_mayusculas (char *cad)
{
	int j = 0;

	while (cad[j] != '\0') {
		cad[j] = toupper(cad[j]);
		j++;
	}
}


int palindromo (const char *expresion)
{
	Pila p;
	Cola c;

	int j=0;
	int m=0;
	int i=0;

	pilaCreaVacia(&p);
	colaCreaVacia(&c);
	while (expresion[j] != '\0') {

			if (expresion[j] != ' '){

					if (pilaInserta(&p, expresion[j]) == -1 && pilaInserta(&p, expresion[j]) == -2){
						printf("ERROR\n");
						exit(0);
					}

					if (colaInserta(&c, expresion[j]) == -1 && colaInserta(&c, expresion[j]) == -2){
						printf("ERROR\n");
						exit(0);

					}
					m++;
			}
			j++;
	}


	for (i=0; i<m; i++ ){

			if (pilaSuprime(&p) != colaSuprime(&c))
				return 0;
	}

	return 1;






}
