#include "procesador.h"

int main()
{
    setlocale(LC_ALL, "");

    tDiccionario dicc;

    int cap = 10;

    crearDiccionario(&dicc, cap);

    procesarArchivo("Prueba.txt", &dicc);

    recorrerDiccionario(&dicc, mostrarReg, NULL);

    return 0;
}
