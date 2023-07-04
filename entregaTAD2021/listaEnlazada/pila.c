

















#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"



int pilaCreaVacia(Pila *p)
{
  if (p==NULL )
    return -1;

*p=NULL;
return 0;
}

int pilaVacia(Pila *p)
{
  if(p==NULL)
    return -1;

  if(*p==NULL)
    return 1;

  else
    return 0;

}

int pilaInserta(Pila *p,tipoElemento elemento)
{
  tipoCelda *nuevo;

  if (p == NULL)
      return -1;

  nuevo =(tipoCelda *) malloc(sizeof(tipoCelda));
  if (nuevo == NULL)
    return -2;

  nuevo->elemento = elemento;
  nuevo->sig = *p;
  *p = nuevo;
  return 0;


}

tipoElemento pilaSuprime(Pila *p)
{
  tipoElemento elemento;
  tipoCelda *aBorrar;

  if(pilaVacia(p)==1 && pilaVacia(p) == -1)
    return -1;

  aBorrar = *p;
  elemento = aBorrar->elemento;
  *p = (*p)->sig;
  free(aBorrar);

  return elemento;
}
