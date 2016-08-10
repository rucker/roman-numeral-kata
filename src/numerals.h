#ifndef NUMERALS_H
#define NUMERALS_H

void add(const char *first, const char *second, char *buf);
void subtract(const char *first, const char *second, char *buf);
int numeralToInt(const char *numeral);
void intToNumeral(int number, char *buf);
int charToInt(const char *c);

#endif
