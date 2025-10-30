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
        case 129: aux = '�'; break;
        case 137: aux = '�'; break;
        case 141: aux = '�'; break;
        case 145: aux = '�'; break;
        case 147: aux = '�'; break;
        case 154: aux = '�'; break;
        case 161: aux = '�'; break;
        case 169: aux = '�'; break;
        case 173: aux = '�'; break;
        case 177: aux = '�'; break;
        case 179: aux = '�'; break;
        case 186: aux = '�'; break;
    }

    return aux;
}
