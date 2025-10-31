#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "headers.h"

#define LISTA_VACIA -2

#define RESERVAR_MEMORIA_NODO(X,Y,Z,W) ( \
        ((X) = (tNodo*)malloc(Y)) == NULL ? 0 : \
        ((Z) = malloc(W)) == NULL ? (free((X)), 0) : 1 )

typedef struct sNodo {
    void *info;
    size_t tamInfo;
    struct sNodo *sig;
} tNodo;

typedef tNodo *tLista;

void crearLista(tLista *pl);
void vaciarLista(tLista *pl);
int insertarUltimoLista(tLista *pl, void *elem, size_t tamElem);
void recorrerLista(tLista *pl, void (*accion)(void *elem, void *params), void *params);

#endif // LISTA_H_INCLUDED
