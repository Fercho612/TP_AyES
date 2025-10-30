#include "procesador.h"
#include "diccionario.h"
#include "myCType.h"


int procesarArchivo(const char *arch, tDiccionario *pd){
    char auxPalabra[TAM_PALABRA] = "";
    char *pPalabra = auxPalabra;
    char auxSigno[2];
    int fileChar;

    FILE *pf = fopen(arch, "rt");
    if(!pf){
        printf("Error al abrir el archivo\n\n");
        return ERROR_ARCH;
    }

    fileChar = fgetc(pf);
    while(fileChar != EOF){
        if (fileChar == 195)
            fileChar = transformarCarLatin(fgetc(pf));


        if (!esLetra(fileChar)){
            auxSigno[0] = fileChar;
            auxSigno[1] = '\0';
            crearOActualizar(pd, auxSigno);
        } else {
            while(esLetra(fileChar) && fileChar != EOF){
                *pPalabra = fileChar;
                pPalabra++;

                fileChar = fgetc(pf);
                if (fileChar == 195)
                    fileChar = transformarCarLatin(fgetc(pf));
            }
            *pPalabra  = '\0';
            crearOActualizar(pd, auxPalabra);

            pPalabra = auxPalabra;
            *pPalabra = '\0';
        }

        fileChar = fgetc(pf);
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
