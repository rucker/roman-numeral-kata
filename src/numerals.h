#ifndef NUMERALS_H
#define NUMERALS_H
#include <stdbool.h>

void add(const char *first, const char *second, char *buf);
void subtract(const char *first, const char *second, char *buf);
int numeralToInt(const char *numeral);
void intToNumeral(int number, char *buf);
int charToInt(const char *c);
void translateTotal(int total, char *buf);
bool boundsCheck(int total);

#endif
