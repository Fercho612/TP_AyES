#include "interfaz.h"
#include "procesador.h"

// Función temporal para pruebas
void iniciar()
{
    tDiccionario diccionario;

    crearDiccionario(&diccionario, 500);

    procesarArchivo("test.txt", &diccionario);

    menu(&diccionario);
}

void mostrarAparicionesPalabraParticular(tDiccionario *pd) {
    char cad[TAM_CAD_PALABRA];
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

void menu(tDiccionario *pd) {
    char opcionSeleccionada;

    do {
        opcionSeleccionada = seleccionarOpcion("Elija una opcion\n\n"
                                          "a) Monstrar estadisticas generales.\n"
                                          "b) Mostrar listado de apariciones por palabra.\n"
                                          "c) Mostrar cantidad de apariciones de palabra en particular.\n", "abcdef");

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
        default:
            break;
        }
    }
    while(opcionSeleccionada != 'd');
}

char seleccionarOpcion(const char* mensaje, const char* opciones)
{
    char opcionSeleccionada;
    int primeraVez = 1;

    do {
        puts(mensaje);
        fflush(stdin);
        scanf("%c", &opcionSeleccionada);
        putchar('\n');
        if(!primeraVez)
            puts("La opcion ingresada no es valida.");
        primeraVez = 0;
    }
    while(!strchr(opciones, opcionSeleccionada = tolower(opcionSeleccionada)));

    return opcionSeleccionada;
}
