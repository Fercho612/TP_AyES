#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

#include "headers.h"
#include "diccionario.h"
#include "myCType.h"
#include <string.h>
#include <ctype.h>

#define TAM_CAD_PALABRA 50

typedef struct {
    int cantidadPalabras;
    int cantidadSignos;
} tEstadisticas;

void iniciar();
void menu();
char seleccionarOpcion(const char* mensaje, const char* opciones);
void mostrarAparicionesPalabraParticular(tDiccionario *pd);
void calcularEstadisticasGenerales(void* elem, void* params);
void mostrarEstadisticasGenerales(tDiccionario *pd);
void mostrarClaveValor(void* elem, void* params);
void mostrarEstadisticasPorPalabra(tDiccionario *pd);

#endif // INTERFAZ_H_INCLUDED
