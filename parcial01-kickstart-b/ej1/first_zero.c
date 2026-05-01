#include <assert.h>
#include <stdbool.h>
#include "first_zero.h"

/**
 * @brief Posición del primero cero en un arreglo de la forma [1, 1, ... , 1, 0, 0, ..., 0].
 * 
 * Dado un arreglo de la forma [1, 1, ... , 1, 0, 0, ..., 0], devolver la
 * posición del primer elemento que es un cero (0). Si no hay ningún cero,
 * devolver -1. La búsqueda se realiza usando una estrategia divide y vencerás
 * de complejidad O(log n).
 *
 * @param a Arreglo de forma [1, 1, ... , 1, 0, 0, ..., 0].
 * @param length Largo del arreglo.
 */

int first_zero_rec(int a[],int izq, int der){
    int resultado;
    int medio;
    if (izq == der)
    {
        if (a[izq] == 0)
        {
            resultado = izq;
        } else if (a[izq] == 1) 
        {
            resultado = -1;
        }
    } else if (izq < der)
    {
        medio = (izq + der) / 2;
        if (a[medio] == 0)
        {
            resultado = first_zero_rec(a, izq,medio);
        } else if (a[medio] == 1)
        {
            resultado = first_zero_rec(a,medio + 1,der);
        }
    }
    return resultado;
}


int first_zero(int a[], int length) {
    int resultado;
    return  resultado = first_zero_rec(a,0,length - 1);
}
