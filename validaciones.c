#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

#define TAM_BUFFER 100

double leer_double(const char *mensaje, double min, double max) {
    char buffer[TAM_BUFFER];
    char *fin;
    double valor;

    while (1) {
        printf("%s", mensaje);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Error de lectura. Intente de nuevo.\n");
            clearerr(stdin);
            continue;
        }

        /* Si no hay '\n', la linea fue mas larga que el buffer */
        if (strchr(buffer, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            printf("Entrada demasiado larga.\n");
            continue;
        }

        valor = strtod(buffer, &fin);

        if (fin == buffer || (*fin != '\n' && *fin != '\0')) {
            printf("Entrada invalida: ingrese solo un numero.\n");
        } else if (valor < min || valor > max) {
            printf("Valor fuera de rango (%.2f a %.2f).\n", min, max);
        } else {
            return valor;
        }
    }
}

int leer_entero(const char *mensaje, int min, int max) {
    char buffer[TAM_BUFFER];
    char *fin;
    long valor;

    while (1) {
        printf("%s", mensaje);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Error de lectura. Intente de nuevo.\n");
            clearerr(stdin);
            continue;
        }

        if (strchr(buffer, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            printf("Entrada demasiado larga.\n");
            continue;
        }

        valor = strtol(buffer, &fin, 10);

        if (fin == buffer || (*fin != '\n' && *fin != '\0')) {
            printf("Entrada invalida: ingrese solo un numero entero.\n");
        } else if (valor < min || valor > max) {
            printf("Valor fuera de rango (%d a %d).\n", min, max);
        } else {
            return (int)valor;
        }
    }
}
