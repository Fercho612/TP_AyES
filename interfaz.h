#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

#include "headers.h"
#include "diccionario.h"
#include "myCType.h"
#include <string.h>
#include <ctype.h>
#include <locale.h>

typedef struct {
    int cantidadPalabras;
    int cantidadSignos;
} tEstadisticas;

void ingresarArchivo(tDiccionario *pd);
void menu(tDiccionario *pd);
char seleccionarOpcion(const char* mensaje, const char* opciones);

void mostrarAparicionesPalabraParticular(tDiccionario *pd);
void calcularEstadisticasGenerales(void* elem, void* params);
void mostrarEstadisticasGenerales(tDiccionario *pd);
void mostrarClaveValor(void* elem, void* params);
void mostrarEstadisticasPorPalabra(tDiccionario *pd);

#endif // INTERFAZ_H_INCLUDED
