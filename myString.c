#include "myString.h"

size_t myStrlen(const char *str){
    size_t cant = 0;
    while(*str != '\0'){
        cant++;
        str++;
    }
    return cant;
}

int myStrcmp(const char *str1, const char *str2){
    char *auxStr1 = (char*)str1, *auxStr2 = (char*)str2;
    while(*auxStr1 && *auxStr2){
        if(*auxStr1 == *auxStr2){
            auxStr1++; auxStr2++;
        } else return *auxStr1 - *auxStr2;
    }
    return *auxStr1 - *auxStr2;
}

char *myStrcpy(char *str1, const char *str2){
    char *pIni = str1;
    while(*str2 != '\0'){
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
    return pIni;
}
