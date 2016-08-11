#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "numerals.h"

static const char *NOTHING = "nullus";
static const int MAX_ROMAN_NUMERAL_VALUE = 3999;
static const int MIN_ROMAN_NUMERAL_VALUE = 1;

void add(const char *first, const char *second, char *buf) {
    translateTotal(numeralToInt(first) + numeralToInt(second), buf);
}

void subtract(const char *first, const char *second, char *buf) {
    translateTotal(numeralToInt(first) - numeralToInt(second), buf);
}

void translateTotal(int total, char *buf) {
    if (boundsCheck(total)) {
        intToNumeral(total, buf);
        return;
    }
    strcpy(buf, NOTHING);
}

bool boundsCheck(int total) {
    return total >= MIN_ROMAN_NUMERAL_VALUE && total <= MAX_ROMAN_NUMERAL_VALUE;
}

int numeralToInt(const char *numeral) {
    if (numeral == NULL) {
        return 0;
    }
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
    if (buf == NULL) {
        return;
    }
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
