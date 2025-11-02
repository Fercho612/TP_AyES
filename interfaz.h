#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

#include "headers.h"
#include "diccionario.h"
#include "myCType.h"
#include <string.h>
#include <locale.h>

typedef struct {
    int cantidadPalabras;
    int cantidadSignos;
} tEstadisticas;

void ingresarArchivo(tDiccionario *pd);

void menu(tDiccionario *pd);
void imprimirMenu();
char seleccionarOpcion(const char* opciones);

void mostrarAparicionesPalabraParticular(tDiccionario *pd);
void calcularEstadisticasGenerales(void* elem, void* params);
void mostrarEstadisticasGenerales(tDiccionario *pd, tEstadisticas *pe);
void mostrarClaveValor(void* elem, void* params);
void mostrarEstadisticasPorPalabra(tDiccionario *pd);

void limpiarBuffer();

#endif // INTERFAZ_H_INCLUDED
