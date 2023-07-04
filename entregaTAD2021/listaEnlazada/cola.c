#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"



int colaCreaVacia(Cola *c)
{
  if(c==NULL)
    return -1;

c->frente=NULL;
c->fondo=NULL;
return 0;
}

int colaVacia(Cola *c)
{
  if (c==NULL)
    return -1;

  if (c->frente == NULL)
    return 1;

  else return 0;
}

int colaInserta(Cola *c,tipoElemento elemento)
{
  tipoCelda *nuevo;

  if(c==NULL)
    return -1;

  nuevo =  malloc(sizeof(tipoCelda));

  if (nuevo == NULL)
    return -2;

  nuevo->elemento = elemento;


  if(c->fondo == NULL){
    nuevo->sig = NULL;
    c->fondo = c->frente = nuevo;
}

else{
  nuevo->sig = NULL;
  //c->fondo->sig = nuevo;
  c->fondo = nuevo;
}

  return 0;
}

tipoElemento colaSuprime(Cola *c)
{
  tipoElemento elemento;
tipoCelda *aBorrar;



    if (colaVacia(c) == 1 && colaVacia(c) == -1)
      return -1;

  aBorrar = c->frente;
  elemento = aBorrar->elemento;

  if(c->frente == c->fondo)
    c->fondo = c->frente = NULL;

else
  c->frente = c->frente->sig;

  free(aBorrar);

  return elemento;
}
