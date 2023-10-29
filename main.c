#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

// TODO agregar al readme esto
/*
compile and run file:
gcc main.c; .\a.exe
*/
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
    return encontrarUltimoNodo(nodo->siguiente);
  }
}

struct Nodo* encontrarPenultimoNodo(struct Nodo* nodo)
{
  if (nodo->siguiente == NULL) {
    return NULL;
  }
  if (nodo->siguiente->siguiente == NULL) {
    return nodo;
  }
  else {
    return encontrarPenultimoNodo(nodo->siguiente);
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

struct Nodo* push(struct Nodo* nodoPadre, int valorNuevo)
{
  struct Nodo* nuevoNodo = crearNuevoNodo(valorNuevo);
  nuevoNodo->siguiente = nodoPadre;
  return nuevoNodo;
}

struct Nodo* pop(struct Nodo* nodoPadre)
{
  struct Nodo* nuevoPadre = nodoPadre->siguiente;
  free(nodoPadre);
  return nuevoPadre;
}

struct Nodo* deleteLastNodo(struct Nodo* nodoPadre)
{
  struct Nodo* ultimoNodo = encontrarUltimoNodo(nodoPadre);
  struct Nodo* penultimoNodo = encontrarPenultimoNodo(nodoPadre);
  if (penultimoNodo == NULL)
  {
    free(nodoPadre);
    return NULL;
  }
  else {
    penultimoNodo->siguiente = NULL;
    free(ultimoNodo);
    return nodoPadre;
  }
}

void deleteAllList(struct Nodo* nodo)
{
  if (nodo != NULL)
  {
    struct Nodo* siguiente = nodo->siguiente;
    free(nodo);
    deleteAllList(siguiente);
  }
}

/*
 este método tiene una complejidad de n^2
 porque los métodos que usé dentro arrancan desde el principio de la lista
 (n)(n-1)(n-2)(...) = n^2
*/
struct Nodo* reverse1(struct Nodo* nodoPadre)
{
  // acá estoy usando más memoria de la que necesito??
  struct Nodo* reversedNodo;

  reversedNodo = crearNuevoNodo(encontrarUltimoNodo(nodoPadre)->Valor);
  deleteLastNodo(nodoPadre);

  append(reversedNodo, encontrarUltimoNodo(nodoPadre)->Valor);
  deleteLastNodo(nodoPadre);

  append(reversedNodo, encontrarUltimoNodo(nodoPadre)->Valor);
  deleteLastNodo(nodoPadre);

  return reversedNodo;
}


// reverse([], []) = []
// reverse([1, 2, 3], []) 
//   = reverse([1, 2], [3]) 
//   = reverse([1], [3, 2])  
//   = reverse([], [3, 2, 1])  
//   = [3, 2, 1]

struct Nodo* reverse(struct Nodo* nodoPadre, struct Nodo* reversedNodo)
{
  // si es el primer caso
  if (nodoPadre == NULL) {
    return reversedNodo;
  }
  if (reversedNodo->siguiente == NULL) {
    reversedNodo = crearNuevoNodo(encontrarUltimoNodo(nodoPadre)->Valor);
    deleteLastNodo(nodoPadre);
  }
  append(reversedNodo, encontrarUltimoNodo(nodoPadre)->Valor);
  deleteLastNodo(nodoPadre);

  // return reverse(nodoPadre, reversedNodo);
  append(reversedNodo, encontrarUltimoNodo(nodoPadre)->Valor);
  deleteLastNodo(nodoPadre);

  return reversedNodo;
}

int main()
{
  struct Persona persona1;
  persona1.Edad = 20;
  strcpy(persona1.Nombre, "Juan");
  // printf("La edad de %s es %d", persona1.Nombre, persona1.Edad);
  struct Persona* personaPuntero;
  // personaPuntero = &persona1;

  struct Nodo* nodo1;
  struct Nodo* nodo2;
  struct Nodo* nodo3;

  nodo1 = malloc(sizeof(struct Nodo));
  nodo2 = malloc(sizeof(struct Nodo));
  nodo3 = malloc(sizeof(struct Nodo));

  // Creación de nodo sin los métodos
  nodo1->Valor = 1;
  nodo1->siguiente = nodo2;
  nodo2->Valor = 2;
  nodo2->siguiente = nodo3;
  nodo3->Valor = 3;
  nodo3->siguiente = NULL;

  // imprimir(&nodo1);
  // struct Nodo* nodoConPush = push(&nodo1, 0);
  // imprimir(nodoConPush);
  // struct Nodo* nodoConPop = pop(nodoConPush);
  // imprimir(nodoConPop);

  // Creación e impresión de los nodos con los métodos
  // imprimir(append(append(crearNuevoNodo(1), 2), 3));

  imprimir(nodo1);
  struct Nodo* reversedList;
  //reversedList = malloc(sizeof(struct Nodo));

  imprimir(reverse(NULL, reversedList));
}
