#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    res.is_upperbound = true;
    res.is_lowerbound = true;
    res.where = 0;
    unsigned int i = 0;
    while (i < length)
    {
        res.is_upperbound = res.is_upperbound && (arr[i] <= value);
        res.is_lowerbound = res.is_lowerbound && (arr[i] > value);
        if (arr[i] == value)
        {
            res.exists = true;
            res.where = i;
        }
        i ++;
    }
    
    return res;
}

int main(void) {
    int a[ARRAY_SIZE];
    int value;
    int i = 0;
    while (i < ARRAY_SIZE)
    {
        printf("Ingrese el valor para la posicion %d\n",i);
        scanf("%d", &a[i]);
        i++;
    }
    printf("Ingrese el valor que quiere comparar con el arrelgo\n");
    scanf("%d", &value);


    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    if (result.is_upperbound == true)
    {
        printf("El valor que ingreso es cota superior\n");

    } else if (result.is_lowerbound == true)
    {
        printf("El valor que ingreso es cota inferior\n");

    } 
    
    
    if (result.is_upperbound == true && result.exists == true)
    {
        printf("El valor que ingreso es maximo y se encontro en la posicion %d\n", result.where);

    } else if (result.is_lowerbound == true && result.exists == true)
    {
        printf("El valor que ingreso es minimo y se encontro en la posicion %d\n", result.where);
    }

    return EXIT_SUCCESS;
}

