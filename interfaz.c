#include "interfaz.h"
#include "procesador.h"
#include "myString.h"

void ingresarArchivo(tDiccionario *pd){
    char arch[50];

    printf("Ingrese nombre de archivo a procesar: ");
    scanf("%s", arch);

    while (procesarArchivo(arch, pd) == ERROR_ARCH){
        printf("Ingrese nombre de archivo a procesar: ");
        scanf("%s", arch);
    }

}

void menu(tDiccionario *pd) {

    char opcionSeleccionada;
    do {
        opcionSeleccionada = seleccionarOpcion("\n\t Menu de opciones \n"
                                          "a) Mostrar estadisticas generales.\n"
                                          "b) Mostrar listado de apariciones por palabra.\n"
                                          "c) Mostrar cantidad de apariciones de palabra en particular.\n"
                                          "s) Salir del Programa\n\n"
                                          "Elija una opción: ", "abcs");

        switch(opcionSeleccionada) {
        case 'a':
            mostrarEstadisticasGenerales(pd);
            break;
        case 'b':
            mostrarEstadisticasPorPalabra(pd);
            break;
        case 'c':
            mostrarAparicionesPalabraParticular(pd);
            break;
        case 's':
            printf("Hasta Pronto!");
            exit(1);
            break;
        default:
            break;
        }
    }
    while(opcionSeleccionada != 'd');
}

char seleccionarOpcion(const char* mensaje, const char* opciones)
{
    char opcionSeleccionada;

    puts(mensaje);
    scanf(" %c", &opcionSeleccionada);

    opcionSeleccionada = myToLower(opcionSeleccionada);

    while(!charEnCad(opciones, opcionSeleccionada)){
        printf("La opción ingresada no es valida.\n");
        printf("Ingrese una opción nuevamente: ");

        scanf(" %c", &opcionSeleccionada);
        putchar('\n');

        opcionSeleccionada = myToLower(opcionSeleccionada);
    }

    return opcionSeleccionada;
}




void mostrarAparicionesPalabraParticular(tDiccionario *pd) {
    char cad[TAM_PALABRA];
    int *valor;
    int cantidad;

    puts("Ingrese la palabra sobre la que desea la informacion:\n");
    scanf("%s", cad);

    valor = obtenerDiccionario(pd, cad);

    if(!valor)
        cantidad = 0;
    else
        cantidad = *valor;

    printf("Apariciones de la palabra '%s': %d\n", cad, cantidad);
}

void calcularEstadisticasGenerales(void* elem, void* params) {
    tInfo *info = (tInfo*)elem;

    if(esLetra(*info->clave))
        ((tEstadisticas*)params)->cantidadPalabras += (*(int*)info->valor);
    else
        ((tEstadisticas*)params)->cantidadSignos += (*(int*)info->valor);
}

void mostrarEstadisticasGenerales(tDiccionario *pd) {
    tEstadisticas estadisticas;

    estadisticas.cantidadPalabras = 0;
    estadisticas.cantidadSignos = 0;

    recorrerDiccionario(pd, calcularEstadisticasGenerales, &estadisticas);

    printf("Cantidad de palabras: %d\nCantidad de signos: %d\n\n", estadisticas.cantidadPalabras, estadisticas.cantidadSignos);
}

void mostrarClaveValor(void* elem, void* params) {
    tInfo *info = (tInfo*)elem;

    printf("%s: %d\n", info->clave, *(int*)info->valor);
}

void mostrarEstadisticasPorPalabra(tDiccionario *pd) {
    puts("Estadisticas por cada palabra y signo:\n");
    recorrerDiccionario(pd, mostrarClaveValor, NULL);
    putchar('\n');
}



