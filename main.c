#include <stdio.h>
#include "simulador.h"
#include "validaciones.h"

int main(void) {
    SimulacionSLS sim = { .a1 = 20.0, .t1 = 120.0, .a2 = 12.5, .h_target = 160000.0 };
    int op;

    calcular_mision(&sim);
    simular_ascenso(&sim);

    do {
        printf("\n=== SIMULADOR ARTEMIS - SLS ===\n");
        printf("[Actual -> a1: %.1f m/s2 | t1: %.1f s | a2: %.1f m/s2 | h: %.0f m]\n",
               sim.a1, sim.t1, sim.a2, sim.h_target);
        printf("1. Ver reporte de la mision\n");
        printf("2. Cambiar parametros\n");
        printf("3. Ver trayectoria del ascenso\n");
        printf("4. Salir\n");

        op = leer_entero("Opcion [1-4]: ", 1, 4);

        switch (op) {
            case 1:
                mostrar_reporte(&sim);
                break;
            case 2:
                sim.a1       = leer_double("Aceleracion a1 (5-50): ", 5.0, 50.0);
                sim.t1       = leer_double("Tiempo t1 (10-300): ", 10.0, 300.0);
                sim.a2       = leer_double("Aceleracion a2 (1-30): ", 1.0, 30.0);
                sim.h_target = leer_double("Altura objetivo (50000-500000): ", 50000.0, 500000.0);
                calcular_mision(&sim);
                simular_ascenso(&sim);
                mostrar_reporte(&sim);
                break;
            case 3:
                mostrar_trayectoria(&sim);
                break;
            case 4:
                printf("Fin del simulador.\n");
                break;
        }
    } while (op != 4);

    return 0;
}