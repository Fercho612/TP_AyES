#include "interfaz.h"
#include "procesador.h"
#include "myString.h"

/* to do:
    - Funcion que limpia buffer
    - Limpiar consola
*/

void ingresarArchivo(tDiccionario *pd){
    char arch[50];

    printf("Ingrese nombre de archivo a procesar: ");
    scanf("%s", arch);
    limpiarBuffer();

    while (procesarArchivo(arch, pd) == ERROR_ARCH){
        printf("Ingrese nombre de archivo a procesar: ");
        scanf("%s", arch);
        limpiarBuffer();
    }
}

void menu(tDiccionario *pd) {
    char opcionSeleccionada;

    do {
        opcionSeleccionada = seleccionarOpcion("abcs");

        switch(opcionSeleccionada) {
            case 'a':
                mostrarEstadisticasGenerales(pd);
                system("pause");
                break;
            case 'b':
                mostrarEstadisticasPorPalabra(pd);
                system("pause");
                break;
            case 'c':
                mostrarAparicionesPalabraParticular(pd);
                system("pause");
                break;
            case 's':
                printf("\tHasta Pronto!\n");
                exit(1);
                break;
            default:
                break;
        }
    }
    while(opcionSeleccionada != 's');
}

void imprimirMenu(){
    system("cls");
    printf("\t\tMenu de opciones\n\n");
    printf("a) Mostrar estadisticas generales.\n");
    printf("b) Mostrar listado de apariciones por palabra.\n");
    printf("c) Mostrar cantidad de apariciones de palabra en particular.\n");
    printf("s) Salir del Programa\n\n");
    printf("Seleccione una opción: ");
}


char seleccionarOpcion(const char* opciones){
    char opcionSeleccionada;

    imprimirMenu();
    scanf("%c", &opcionSeleccionada);
    limpiarBuffer();

    opcionSeleccionada = myToLower(opcionSeleccionada);

    while(!charEnCad(opciones, opcionSeleccionada)){
        printf("La opción ingresada no es valida.\n");
        printf("Ingrese una opción nuevamente: ");

        scanf("%c", &opcionSeleccionada);
        limpiarBuffer();

        opcionSeleccionada = myToLower(opcionSeleccionada);
    }
    system("cls");
    return opcionSeleccionada;
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

// B
void mostrarEstadisticasPorPalabra(tDiccionario *pd) {
    printf("\t\tEstadisticas por cada palabra y signo:\n\n");
    recorrerDiccionario(pd, mostrarClaveValor, NULL);
    putchar('\n');
}


void mostrarAparicionesPalabraParticular(tDiccionario *pd) {
    char cad[TAM_PALABRA];
    int *valor;
    int cantidad;

    printf("Ingrese la palabra sobre la que desea la informacion: ");
    scanf("%s", cad);
    limpiarBuffer();

    valor = obtenerDiccionario(pd, cad);

    if(!valor)
        cantidad = 0;
    else
        cantidad = *valor;

    printf("Apariciones de la palabra '%s': %d\n\n\n", cad, cantidad);
}

void mostrarClaveValor(void* elem, void* params) {
    tInfo *info = (tInfo*)elem;

    if(myStrcmp(info->clave, " ") == 0) {
        printf("' ': %d \n", *(int *)info->valor);
        return;
    }

    printf("%s: %d\n", info->clave, *(int*)info->valor);
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return;
}
