#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "validaciones.h"

#define TAM_BUFFER 100

/* Lee una linea completa del teclado. Devuelve 0 si se cerro la entrada. */
static int leer_linea(char *buf, int tam) {
    if (fgets(buf, tam, stdin) == NULL) return 0;
    if (strchr(buf, '\n') == NULL) {          /* linea mas larga que el buffer */
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
    return 1;
}

double leer_double(const char *msg, double min, double max) {
    char buf[TAM_BUFFER];
    char *fin;
    double x;

    while (1) {
        printf("%s", msg);
        if (!leer_linea(buf, TAM_BUFFER)) {
            printf("\nEntrada cerrada. Saliendo.\n");
            exit(1);
        }
        x = strtod(buf, &fin);
        if (fin == buf) {
            printf("  Error: eso no es un numero.\n");
            continue;
        }
        while (*fin == ' ' || *fin == '\t' || *fin == '\n') fin++;
        if (*fin != '\0') {
            printf("  Error: hay caracteres de mas (use punto, no coma).\n");
            continue;
        }
        if (!isfinite(x) || x < min || x > max) {
            printf("  Error: el valor debe estar entre %.1f y %.1f.\n", min, max);
            continue;
        }
        return x;
    }
}

int leer_entero(const char *msg, int min, int max) {
    char buf[TAM_BUFFER];
    char *fin;
    long x;

    while (1) {
        printf("%s", msg);
        if (!leer_linea(buf, TAM_BUFFER)) {
            printf("\nEntrada cerrada. Saliendo.\n");
            exit(1);
        }
        x = strtol(buf, &fin, 10);
        if (fin == buf) {
            printf("  Error: eso no es un numero entero.\n");
            continue;
        }
        while (*fin == ' ' || *fin == '\t' || *fin == '\n') fin++;
        if (*fin != '\0') {
            printf("  Error: hay caracteres de mas.\n");
            continue;
        }
        if (x < min || x > max) {
            printf("  Error: elija un numero entre %d y %d.\n", min, max);
            continue;
        }
        return (int)x;
    }
}