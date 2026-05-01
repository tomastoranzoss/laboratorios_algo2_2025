#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    int i = 0;
    unsigned int longitud_total = 0;
    while (s[i] != '\0')
    {
        longitud_total ++;
        i++;
    }
    return longitud_total;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    int i = 0;
    bool son_iguales = true;
    while (s1[i] == s2[i] && s1[i] != '\0')
    {
        i ++;
    }
    if (s1[i] != s2[i])
    {
        son_iguales = false;
    }
    
    return son_iguales;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    int i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0')
    {
        i ++;
    }
    return s1[i] <= s2[i];
}

