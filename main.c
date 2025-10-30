#include "procesador.h"

int main()
{
    tDiccionario dicc;
    int cap = 10;

    char c = 'á';

    printf("%d\n", c);
    printf("%c", c);

//    crearDiccionario(&dicc, cap);
//
//    procesarArchivo("Prueba.txt", &dicc);
//
//    recorrerDiccionario(&dicc, mostrarReg, NULL);
//

    return 0;
}


void pruebas(){
    tDiccionario dicc;
    int cap = 500;

    char cad1[] = "Hulaa";
    char cad2[] = "Chau";
    int vec[] = {1,2,3,4,5};
    int *pVec = vec;


    crearDiccionario(&dicc, cap);

    ponerEnDiccionario(&dicc, cad1, pVec, sizeof(int));
    ponerEnDiccionario(&dicc, cad1, pVec+1, sizeof(int));
    ponerEnDiccionario(&dicc, cad2, pVec+2, sizeof(int));

    recorrerDiccionario(&dicc, mostrarReg, NULL);

    destruirDiccionario(&dicc);
}
