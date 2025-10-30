#ifndef PROCESADOR_H_INCLUDED
#define PROCESADOR_H_INCLUDED

#include "headers.h"
#include "diccionario.h"

int procesarArchivo(const char *arch, tDiccionario *pd);
void crearOActualizar(tDiccionario *pd, char* clave);

#endif // PROCESADOR_H_INCLUDED
