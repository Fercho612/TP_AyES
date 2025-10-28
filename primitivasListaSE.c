#include "lista.h"

void crearLista(tLista *pl){
    *pl = NULL;
}

void vaciarLista(tLista *pl){
    tNodo *elimNodo;
    tInfo *elimInfo;

    while(*pl){
        elimNodo = *pl;
        *pl = elimNodo->sig;

        elimInfo = (tInfo*)elimNodo->info;
        free(elimInfo->clave);
        free(elimInfo->valor);
        free(elimInfo);

        free(elimNodo);
    }
}

void recorrerLista(tLista *pl, void (*accion)(void *elem, void *params), void *params){
    while(*pl){
        accion((*pl)->info, params);
        pl = &(*pl)->sig;
    }
}


int insertarUltimoLista(tLista *pl, void *elem, size_t tamElem){
    tNodo *nNodo;
    if(!RESERVAR_MEMORIA_NODO(nNodo, sizeof(tNodo), nNodo->info, tamElem))
        return SIN_MEM;

    while(*pl)
        pl = &(*pl)->sig;

    nNodo->info = elem;
    nNodo->tamInfo = tamElem;
    nNodo->sig = NULL;

    *pl = nNodo;

    return OK;
}
