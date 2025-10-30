#include "myCType.h"

int esVocalMayusConAcento(char c){
    return c == (129-195+3) || c == (137-195+3) || c == (141-195+3) || c == (147-195+3) || c == (154-195+3);
}

int esVocalMinConAcento(char c){
    return c == (161-195+3) || c == (169-195+3) || c == (173-195+3) || c == (179-195+3) || c == (186-195+3);
}

int esLetra(char c){
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == (145-195+3) || c == (177-195+3) ||
        esVocalMayusConAcento(c) || esVocalMinConAcento(c);
}

int esSignoOCaracterEspecial(char c) {
    return (c == '.' || c == ',' || c == ';' || c == ':' ||
    c == '!' || c == '?' || c == '"' || c == '\'' ||
    c == '(' || c == ')' || c == '[' || c == ']' ||
    c == '{' || c == '}' || c == '-' || c == '_' ||
    c == ' ');
}

char transformarCarLatin(int c){
    char aux;

    switch (c){
        case 129: aux = 'Á'; break;
        case 137: aux = 'É'; break;
        case 141: aux = 'Í'; break;
        case 145: aux = 'Ñ'; break;
        case 147: aux = 'Ó'; break;
        case 154: aux = 'Ú'; break;
        case 161: aux = 'á'; break;
        case 169: aux = 'é'; break;
        case 173: aux = 'í'; break;
        case 177: aux = 'ñ'; break;
        case 179: aux = 'ó'; break;
        case 186: aux = 'ú'; break;
    }

    return aux;
}
