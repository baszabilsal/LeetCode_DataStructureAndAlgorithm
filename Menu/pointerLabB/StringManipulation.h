#include <bits/stdc++.h>
using namespace std;
class StringManipulation
{
public:
    char *strcpy(char *, const char *);
    char *strncpy(char *, const char *, size_t);
    char *strcat(char *, const char *);
    char *strncat(char *, const char *, size_t);
    int strcmp(const char *, const char *);
    int strncmp(const char *, const char *, size_t);
    char *strtok(char *, const char *);
    size_t strlen(const char *s);
    int strcmpThatArraySubscriptionNotation(const char[], const char[]);
    int strcmpThatPointerSubscriptionNotation(const char *, const char *);
    int strcmpThatArrayOffsetnNotation(const char[], const char[]);
    int strcmpThatPointerOffsetNotation(const char *, const char *);
};