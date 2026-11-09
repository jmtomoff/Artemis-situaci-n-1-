#ifndef VALIDACIONES_H
#define VALIDACIONES_H

/* Lee un numero decimal validado dentro de [min, max]. */
double leer_double(const char *mensaje, double min, double max);

/* Lee un entero validado dentro de [min, max]. */
int leer_entero(const char *mensaje, int min, int max);

#endif
