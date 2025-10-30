#include "headers.h"

unsigned int obtenerHash(const char *clave, int cap) {
    unsigned int auxHash = 0;
    while (*clave != '\0') {
        auxHash += *clave;
        clave++;
    }
    return auxHash % cap;
}


void liberarInfo(void *info) {
    tInfo *elimInfo = (tInfo *)info;

    if (!elimInfo) return;

    free(elimInfo->clave);
    free(elimInfo->valor);
    free(elimInfo);
}


void mostrarReg(void *elem, void *params){
    tInfo *info = (tInfo *)elem;

    printf("%s: %d\n", info->clave, *(int *)info->valor);
}
