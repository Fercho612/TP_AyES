#include "headers.h"




void mostrarReg(void *elem, void *params){
    tInfo *info = (tInfo *)elem;

    printf("%s: %d\n", info->clave, *(int *)info->valor);
}
