#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED

#include "headers.h"
#include "lista.h"
#include "myString.h"

#define NO_ENCONTRADO -3
#define TAM_PALABRA 50

#define RESERVAR_MEMORIA_TINFO(A,B,C,D,X,Y) ( \
        ((A) = (tInfo*)malloc(B)) == NULL ? 0 : \
        ((C) = malloc(D)) == NULL ? (free(A),0) : \
        ((X) = (char *)malloc(Y)) == NULL ? (free((C)), free((A)), 0) : 1 )

typedef struct {
    tLista *tabla;
    int capacidad;
} tDiccionario;

typedef struct {
    char *clave;
    void *valor;
} tInfo;

unsigned int obtenerHash(const char *clave, int cap);

void crearDiccionario(tDiccionario *pd, int cap);
int ponerEnDiccionario(tDiccionario *pd, char *clave, void *elem, size_t tamElem);
void* obtenerDiccionario(tDiccionario *pd, char *clave);
int sacarDeDiccionario(tDiccionario *pd, const char *clave);
void recorrerDiccionario(tDiccionario *pd, void (*accion)(void *elem, void *params), void *params);

void vaciarDiccionario(tDiccionario *pd);
void liberarInfo(void *info);
void destruirDiccionario(tDiccionario *pd);


#endif // DICCIONARIO_H_INCLUDED
