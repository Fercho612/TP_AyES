#include "headers.h"

int obtenerHash(const char *clave, int cap) {
    int auxHash = 0;
    while (*clave != '\n') {
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

    printf("%s: %s\n", info->clave, (char*)info->valor);
}
