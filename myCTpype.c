#include "myCType.h"

int esVocalMayusConAcento(char c){
    return c == 144 || c == 181 || c == 214 || c == 224 || c == 233;
}

int esLetra(char c){
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
        (c >= 160 && c <= 165) || esVocalMayusConAcento(c);
}
