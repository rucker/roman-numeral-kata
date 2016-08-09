#include <string.h>
#include "numerals.h"

void add(char *first, char *second, char *str) {
    strcpy(str, first);
    strcat(str, second);
}

int charToInt(char *c) {
     switch(*c) {
         case 'i':
             return 1;
        case 'v':
            return 5;
        case 'x':
            return 10;
        case 'l':
            return 50;
        case 'c':
            return 100;
        case 'd':
            return 500;
        case 'm':
            return 1000;
         default:
             return 0;
     }
}
