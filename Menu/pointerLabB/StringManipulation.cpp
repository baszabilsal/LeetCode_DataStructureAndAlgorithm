#include <bits/stdc++.h>
#include "StringManipulation.h"

using namespace std;
char *StringManipulation::strcpy(char *s1, const char *s2)
{
    for (; *s2 != '\0'; s2++)
    {
        *s1 = *s2;
        s1++;
    }
    *s1 = '\0';
    return s1;
}

char *StringManipulation::strncpy(char *s1, const char *s2, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    return s1;
}

char *StringManipulation::strcat(char *s1, const char *s2)
{
    for (; *s1 != '\0'; s1++)
    {
    }
    for (; *s2 != '\0'; s2++)
    {
        *s1 = *s2;
        s1++;
    }
    *s1 = '\0';
    return s1;
}

char *StringManipulation::strncat(char *s1, const char *s2, size_t n)
{
    for (; *s1 != '\0'; s1++)
    {
    }
    for (size_t i = 0; i < n; i++)
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    return s1;
}
int StringManipulation::strcmp(const char *s1, const char *s2)
{
    while (*s2 != '\0' || *s1 != '\0')
    {
        int dif = *s1 - *s2;
        if (dif != 0)
        {
            return dif;
        }
        if (*s1 != '\0')
        {
            s1++;
        }
        if (*s2 != '\0')
        {
            s2++;
        }
    }
    return 0;
}

int StringManipulation::strncmp(const char *s1, const char *s2, size_t n)
{
    int count = 0;
    while ((*s2 != '\0' || *s1 != '\0') && count < n)
    {
        int dif = *s1 - *s2;
        if (dif != 0)
        {
            return dif;
        }
        if (*s1 != '\0')
        {
            s1++;
        }
        if (*s2 != '\0')
        {
            s2++;
        }
        count++;
    }
    return 0;
}
char *StringManipulation::strtok(char *s1, const char *s2)
{
    static char *temp = NULL;
    if (s1 != NULL)
    {
        temp = s1;
    }
    if (temp == NULL)
    {
        return NULL;
    }
    char *result = new char[strlen(temp) + 1];
    int i = 0;
    for (; temp[i] != '\0'; i++)
    {

        if (temp[i] != *s2)
        {
            result[i] = temp[i];
        }
        else
        {
            result[i] = '\0';
            temp = temp + i + 1;
            return result;
        }
    }
    result[i] = '\0';
    temp = NULL;
    return result;
}
size_t StringManipulation::strlen(const char *s)
{
    size_t n = 0;
    while (*s != '\0')
    {
        n++;
        s++;
    }
    return n;
}
int StringManipulation::strcmpThatArraySubscriptionNotation(const char s1[], const char s2[])
{
    int i = 0;
    int j = 0;
    while (s2[i] != '\0' || s1[j] != '\0')
    {
        int dif = s1[j] - s2[i];
        if (dif != 0)
        {
            return dif;
        }
        if (s1[j] != '\0')
        {
            j++;
        }
        if (s2[i] != '\0')
        {
            i++;
        }
    }
    return 0;
}
int StringManipulation::strcmpThatPointerSubscriptionNotation(const char *s1, const char *s2)
{
    while (*s2 != '\0' || *s1 != '\0')
    {
        int dif = *s1 - *s2;
        if (dif != 0)
        {
            return dif;
        }
        if (*s1 != '\0')
        {
            s1++;
        }
        if (*s2 != '\0')
        {
            s2++;
        }
    }
    return 0;
}
int StringManipulation::strcmpThatArrayOffsetnNotation(const char s1[], const char s2[])
{
    int i = 0;
    int j = 0;
    while (*(s2 + i) != '\0' || *(s1 + j) != '\0')
    {
        int dif = *(s1 + j) - *(s2 + i);
        if (dif != 0)
        {
            return dif;
        }
        if (*(s1 + i) != '\0')
        {
            j++;
        }
        if (*(s2 + i) != '\0')
        {
            i++;
        }
    }
    return 0;
}
int StringManipulation::strcmpThatPointerOffsetNotation(const char *s1, const char *s2)
{
    int i = 0;
    int j = 0;
    while (*(s2 + i) != '\0' || *(s1 + j) != '\0')
    {
        int dif = *(s1 + j) - *(s2 + i);
        if (dif != 0)
        {
            return dif;
        }
        if (*(s1 + i) != '\0')
        {
            j++;
        }
        if (*(s2 + i) != '\0')
        {
            i++;
        }
    }
    return 0;
}