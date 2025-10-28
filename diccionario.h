#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED

#include "lista.h"

typedef struct {
    tLista *tabla;
    int capacidad;
} tDiccionario;

void crearDiccionario(tDiccionario *pd, int cap);
int ponerEnDiccionario(tDiccionario *pd, char *clave, void *elem, size_t tamElem);
void obtenerDiccionario(tDiccionario *pd, char *clave);
void recorrerDiccionario(tDiccionario *pd, void (*accion)(void *elem, void *params), void *params);
void destruirDiccionario(tDiccionario *pd);

#endif // DICCIONARIO_H_INCLUDED
