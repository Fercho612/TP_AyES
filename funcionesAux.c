#include "headers.h"

int obtenerHash(const char *clave, int cap) {
    int auxHash = 0;
    while (*clave != '\n') {
        auxHash += *clave;
        clave++;
    }
    return auxHash % cap;
}


void mostrarReg(void *elem, void *params){
    tInfo *info = (tInfo *)elem;

    printf("%s: %s\n", info->clave, (char*)info->valor);
}
