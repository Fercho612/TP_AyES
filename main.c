#include "procesador.h"
#include "interfaz.h"

int main()
{
    setlocale(LC_ALL, "");

    tDiccionario diccionario;

    crearDiccionario(&diccionario, 500);

    printf("\tBienvenido al Procesador de Texto\n\n");

    ingresarArchivo(&diccionario);

    menu(&diccionario);

    return 0;
}
