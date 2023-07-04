#include "pila.h"



int pilaCreaVacia(Pila *p)
{
	p->tope =-1;
	return 0;
}


// En vacía no sería necesario el paso por referencia
// pero por una cuestión de eficiencia
int pilaVacia(Pila *p)
{
	if (p->tope == -1)
		return 1;
	else
		return 0;
}

int pilaInserta(Pila *p,tipoElemento elemento)
{
	if (p->tope == MAX)
		return -1;
	else{
		p->tope = p->tope+1;
		p->elementos[p->tope] = elemento;
	}
	return 0;
}

tipoElemento pilaSuprime(Pila *p)
{
	int valor;

	if (pilaVacia(p))
		return -1;

	else{
		valor = p->elementos[p->tope];
		p->tope = p->tope-1;
		return valor;

	}



}
