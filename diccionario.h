#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED

#include "lista.h"
#include "myString.h"

#define NO_ENCONTRADO -3

typedef struct {
    tLista *tabla;
    int capacidad;
} tDiccionario;

void crearDiccionario(tDiccionario *pd, int cap);
int ponerEnDiccionario(tDiccionario *pd, char *clave, void *elem, size_t tamElem);
void* obtenerDiccionario(tDiccionario *pd, char *clave);
int sacarDeDiccionario(tDiccionario *pd, const char *clave);
void recorrerDiccionario(tDiccionario *pd, void (*accion)(void *elem, void *params), void *params);
void vaciarDiccionario(tDiccionario *pd);
void destruirDiccionario(tDiccionario *pd);

int obtenerHash(const char *clave, int cap);

#endif // DICCIONARIO_H_INCLUDED
