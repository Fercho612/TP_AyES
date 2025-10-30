#include "headers.h"
#include "diccionario.h"
#include "lista.h"
#include "myString.h"

void crearDiccionario(tDiccionario *pd, int cap){
    pd->tabla = malloc(sizeof(tLista) * cap);
    if(!pd){
        printf("Error en la memoria\n");
        exit(SIN_MEM);
    }

    pd->capacidad = cap;

    //Inicializo los punteros de tabla en NULL
    for(int i=0; i<cap; i++) {
        pd->tabla[i] = NULL;
    }
}

int ponerEnDiccionario(tDiccionario *pd, char *clave, void *valor, size_t tamValor){
    int indiceHash = obtenerHash(clave, pd->capacidad);
    tLista *pLista = &(pd->tabla[indiceHash]);
    tInfo *nInfo, *actInfo;
    void *nValor;

    //Reccorido de Lista en el Indice del Hash
    while(*pLista){
        actInfo = (tInfo *)(*pLista)->info;
        //Se verifica la igualdad de las claves
        if(strcmp(actInfo->clave, clave) == 0){
            nValor = realloc(actInfo->valor, tamValor);
            if(!nValor) return SIN_MEM;

            actInfo->valor = nValor;
            memcpy(actInfo->valor, valor, tamValor);
            return OK;
        }
        pLista = &(*pLista)->sig;
    }

    if(!RESERVAR_MEMORIA_TINFO(nInfo, sizeof(tInfo), nInfo->valor, tamValor, nInfo->clave, myStrlen(clave) + 1)){
           printf("Error en la memoria\n");
           exit(SIN_MEM);
    }

    myStrcpy(nInfo->clave, clave);
    memcpy(nInfo->valor, valor, tamValor);

    insertarUltimoLista(pLista, nInfo, sizeof(nInfo));

    return OK;
}


void* obtenerDiccionario(tDiccionario *pd, char *clave){
    int indiceHash = obtenerHash(clave, pd->capacidad);

    tLista *pLista = &(pd->tabla[indiceHash]);
    tInfo *actInfo;

    if(!*pLista) return NULL; //Lista Vacia

    while(*pLista){
        actInfo = (tInfo *)(*pLista)->info;
        if(myStrcmp(actInfo->clave, clave) == 0)
            return actInfo->valor;

        pLista = &(*pLista)->sig;
    }

    return NULL; //No se encuentra valor para esa clave.
}

int sacarDeDiccionario(tDiccionario *pd, const char *clave){
    int indiceHash = obtenerHash(clave, pd->capacidad);

    tLista *pLista = &(pd->tabla[indiceHash]);
    tNodo *elim;
    tInfo *actInfo;

    if(!*pLista) return LISTA_VACIA; //Lista Vacia

    while(*pLista){
        actInfo = (tInfo *)(*pLista)->info;
        if(myStrcmp(actInfo->clave, clave) == 0){
            elim = *pLista;
            *pLista = elim->sig;

            liberarInfo(elim->info);
            free(elim);
            return OK;
        }
        pLista = &(*pLista)->sig;
    }

    return NO_ENCONTRADO; //No se encontro elemento con esa clave en el diccionario.
}

void recorrerDiccionario(tDiccionario *pd, void (*accion)(void *elem, void *params), void *params){
    for(int i=0; i<pd->capacidad; i++){
        recorrerLista(&(pd->tabla[i]), accion, params);
    }
}

void vaciarDiccionario(tDiccionario *pd){
    for(int i=0; i < pd->capacidad; i++){
        if(pd->tabla[i] != NULL)
            vaciarLista(&(pd->tabla[i]));
    }
}

void destruirDiccionario(tDiccionario *pd){
    vaciarDiccionario(pd);
    free(pd->tabla);
    pd->tabla = NULL;
    pd->capacidad = 0;
}
