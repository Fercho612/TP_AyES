#include "diccionario.h"

int main()
{
    tDiccionario dicc;
    int cap = 5;

    crearDiccionario(&dicc, cap);

    destruirDiccionario(&dicc);

    return 0;
}
