#include "cola.h"

int colaCreaVacia(Cola *c)
{
	c->tamagno = -1;
	c->frente = 0;
	c->fondo = MAX;

	return 0;
}

// En vacía no sería necesario el paso por referencia
// pero por una cuestión de eficiencia
int colaVacia(Cola *c)
{
	if (c->tamagno == -1)
		return 1;
	else
		return 0;
}

int incrementaIndice(int *x)
{
	if (*x == MAX)
		*x = 0;
	else
		*x = *x+1;

}
int colaInserta(Cola *c, tipoElemento elemento)
{
	if (c->tamagno == MAX)
		return -1;
	else{
		incrementaIndice(&c->fondo);
		c->elementos[c->fondo] = elemento;
		c->tamagno = c->tamagno +1;
	}
}

tipoElemento colaSuprime(Cola *c)
{
	int valor;

	if (colaVacia(c))
		return -1;
	else {
		valor = c->elementos[c->frente];
		incrementaIndice(&c->frente);
		c->tamagno = c->tamagno -1;
		return valor;
	}

}
