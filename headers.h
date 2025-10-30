#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "lista.h"

#define ERROR_ARCH -1
#define SIN_MEM -1
#define OK 1

#define RESERVAR_MEMORIA_TINFO(A,B,C,D,X,Y) ( \
        ((A) = (tInfo*)malloc(B)) == NULL ? 0 : \
        ((C) = malloc(D)) == NULL ? (free(A),0) : \
        ((X) = (char *)malloc(Y)) == NULL ? (free((C)), free((A)), 0) : 1 )

typedef struct {
    char *clave;
    void *valor;
} tInfo;


void liberarInfo(void *info);
void mostrarReg(void *elem, void *params);


#endif // HEADERS_H_INCLUDED
