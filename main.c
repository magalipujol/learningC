#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

struct Persona {   // Structure declaration
  int Edad;           // Member (int variable)
  char Nombre[20];       // Member (char variable)
};

struct Nodo {
  int Valor;
  struct Nodo* siguiente;
};

void imprimir(struct Nodo* nodo)
{
  printf("%d", nodo->Valor);
  if (nodo->siguiente != NULL)
  {
    imprimir(nodo->siguiente);
  }
  else
  {
    printf("\n");
  }
}

struct Nodo* encontrarUltimoNodo(struct Nodo* nodo)
{
  if (nodo->siguiente == NULL) {
    return nodo;
  }
  else {
    encontrarUltimoNodo(nodo->siguiente);
  }
}

struct Nodo* crearNuevoNodo(int valor)
{
  struct Nodo* nuevoNodo;
  nuevoNodo = malloc(sizeof(struct Nodo));
  nuevoNodo->Valor = valor;
  nuevoNodo->siguiente = NULL;
  return nuevoNodo;
}

struct Nodo* append(struct Nodo* nodoPadre, int valor)
{
  struct Nodo* nuevoNodo = crearNuevoNodo(valor);

  encontrarUltimoNodo(nodoPadre)->siguiente = nuevoNodo;
  return nodoPadre;
}

int main()
{
  struct Persona persona1;
  persona1.Edad = 20;
  strcpy(persona1.Nombre, "Juan");
  // printf("La edad de %s es %d", persona1.Nombre, persona1.Edad);
  struct Persona* personaPuntero;
  // personaPuntero = &persona1;

  struct Nodo nodo1;
  struct Nodo* nodo2;
  struct Nodo* nodo3;

  nodo2 = malloc(sizeof(struct Nodo));
  nodo3 = malloc(sizeof(struct Nodo));

  nodo1.Valor = 1;
  nodo1.siguiente = nodo2;
  nodo2->Valor = 2;
  nodo2->siguiente = nodo3;
  nodo3->Valor = 3;
  nodo3->siguiente = NULL;

  imprimir(&nodo1);

  imprimir(append(append(crearNuevoNodo(1), 2), 3));

  // printf("La edad de %s es %d", personaPuntero->Nombre, personaPuntero->Edad);
}
