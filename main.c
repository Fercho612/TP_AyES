#include "diccionario.h"

int main()
{
    tDiccionario dicc;
    int cap = 5;
    char valor[] = "Anashei";
    char valor2[] = "ola" ;

    printf("Hula: hash = %d\n", obtenerHash("Hula", cap));
    printf("Dona: hash = %d\n", obtenerHash("Dona", cap));
    printf("Que_: hash = %d\n", obtenerHash("Que_", cap));

    crearDiccionario(&dicc, cap);

    ponerEnDiccionario(&dicc, "Hula", &valor, 8);
    ponerEnDiccionario(&dicc, "Dona", &valor2, sizeof(int));
    ponerEnDiccionario(&dicc, "Que_", &valor, 8);

    recorrerDiccionario(&dicc, mostrarReg, NULL);

    destruirDiccionario(&dicc);

    return 0;
}
