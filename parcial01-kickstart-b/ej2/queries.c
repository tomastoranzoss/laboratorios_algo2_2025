/*
  @file queries.c
  @brief Consultas sobre tablas de datos climáticos.
*/

#include "queries.h"

/**
 * @brief Máxima temperatura de un año dado.
 *
 * @param a Tabla de datos climáticos.
 * @param year Año, entre FST_YEAR (1980) y LST_YEAR (2016).
 */
int year_max_temp(WeatherTable a, int year) {
    int resultado = a[year - FST_YEAR][0][0]._max_temp;
    for (int mes = 0; mes < MONTHS; mes++)
    {
      for (int dia = 0; dia < DAYS; dia++)
      {
        int temperatura_actual = a[year - FST_YEAR][mes][dia]._max_temp;
        if (temperatura_actual > resultado)
        {
          resultado = temperatura_actual;
        }
      }
    }
    return resultado;
}
