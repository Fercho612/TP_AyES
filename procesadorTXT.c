#include "procesador.h"
#include "diccionario.h"
#include "myCType.h"

int procesarArchivo(const char *arch, tDiccionario *pd){
    char auxPalabra[100] = "";
    char *pPalabra = auxPalabra;
    int auxChar;

    FILE *pf = fopen(arch, "rt");
    if(!pf){
        printf("Error al abrir el archivo");
        return ERROR_ARCH;
    }

    auxChar = fgetc(pf);
    while(auxChar != EOF){

        if (!esLetra(auxChar)){
            char aux[2] = { auxChar, '\0' };
            crearOActualizar(pd, aux);
        }

        while(esLetra(auxChar) && auxChar != EOF){
            *pPalabra = auxChar;
            pPalabra++;
            auxChar = fgetc(pf);
        }
        *pPalabra  = '\0';
        crearOActualizar(pd, auxPalabra);

        pPalabra = auxPalabra;
        *pPalabra = '\0';

        auxChar = fgetc(pf);
    }

    return OK;
}

void crearOActualizar(tDiccionario *pd, char* clave) {
    int cantidad = 1;
    int* pCantidad;

    if((pCantidad = (int*)obtenerDiccionario(pd, clave)))
        cantidad += *pCantidad;

    ponerEnDiccionario(pd, clave, &cantidad, sizeof(int));
}
