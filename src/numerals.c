#include <string.h>
#include <ctype.h>
#include "numerals.h"

static const char *NULLA = "nulla";
static const int MAX_ROMAN_NUMERAL_VALUE = 3999;

void add(const char *first, const char *second, char *buf) {
    int firstVal = numeralToInt(first);
    int secondVal = numeralToInt(second);
    int total = firstVal + secondVal;
    if (total > MAX_ROMAN_NUMERAL_VALUE) {
        strcpy(buf, NULLA);
        return;
    }
    intToNumeral(total, buf);
}

void subtract(const char *first, const char *second, char *buf) {
    intToNumeral(numeralToInt(first) - numeralToInt(second), buf);
}

int numeralToInt(const char *numeral) {
    int i, len = strlen(numeral);
    char thisChar[2];
    const char *numeralPtr = numeral + len -1;
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
            if (totalForNumeral > MAX_ROMAN_NUMERAL_VALUE) {
                return 0;
            }
        }
        prevVal = thisVal;
     }
     return totalForNumeral;
}

void intToNumeral(int number, char *buf) {
    const char numerals[13][3] = { "m", "cm", "d", "cd", "c", "xc", "l", "xl", "x", "ix", "v", "iv", "i" };
    int numeralArrLen = 3;
    const char *numeralsPtr = numerals[0];
    char numeral[numeralArrLen];
    strcpy(numeral, numeralsPtr);
    numeralsPtr += numeralArrLen;

    while (number > 0) {
        while (number < numeralToInt(numeral)) {
            strcpy(numeral, numeralsPtr);
            numeralsPtr += numeralArrLen;
        }
        while (number >= numeralToInt(numeral)) {
            strcat(buf, numeral);
            number -= numeralToInt(numeral);
        }
    }
}

int charToInt(const char *c) {
    const char lnumeral = tolower(*c);
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
            return 0;
     }
}
