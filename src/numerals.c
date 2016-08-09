#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "numerals.h"

void add(char *first, char *second, char *str) {
    strcpy(str, first);
    strcat(str, second);
}

int numeralToInt(char *numeral) {
    int i, len = strlen(numeral);
    char thisChar[2];
    char *numeralPtr = numeral + len -1;
    int thisVal;
    int prevVal = 0;
    int totalForNumeral = 0;

    for (i = len; i > 0; i--) {
        memcpy(thisChar, numeralPtr--, sizeof(int));
        thisVal = charToInt(thisChar);
        if (thisVal < prevVal) {
            totalForNumeral -= thisVal;
        }
        else {
            totalForNumeral += thisVal;
        }
        prevVal = thisVal;
     }
     return totalForNumeral;
}

int charToInt(char *c) {
    char lnumeral = tolower(*c);
     switch(lnumeral) {
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
            printf("The letter %s is not a valid Roman numeral!\n", c);
            exit(1);
     }
}
