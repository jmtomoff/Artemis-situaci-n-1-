#include <stdio.h>
#include <math.h>
#include "simulador.h"

void calcular_mision(SimulacionSLS *sim) {
    /* Fase 1 */
    sim->v1 = sim->a1 * sim->t1;
    sim->y1 = 0.5 * sim->a1 * sim->t1 * sim->t1;
    double a_mayor = (sim->a1 > sim->a2) ? sim->a1 : sim->a2;
sim->g_max = a_mayor / G_TIERRA;

    /* Caso borde: la fase 1 ya llego (o paso) la altura objetivo */
    if (sim->y1 >= sim->h_target) {
        sim->fase2_valida = 0;
        sim->v2 = 0.0;
        sim->h_max = 0.0;
        sim->t_apagado = 0.0;
        return;
    }

    /* Fase 2 */
    sim->fase2_valida = 1;
    sim->v2 = sqrt(sim->v1 * sim->v1 + 2.0 * sim->a2 * (sim->h_target - sim->y1));
    sim->t_apagado = sim->t1 + (sim->v2 - sim->v1) / sim->a2;

    /* Caida libre desde h_target */
    sim->h_max = sim->h_target + (sim->v2 * sim->v2) / (2.0 * G_TIERRA);
}

void simular_ascenso(SimulacionSLS *sim) {
    sim->pasos = 0;
    if (!sim->fase2_valida) return;

    for (int t = 0; sim->pasos < MAX_PASOS; t++) {
        double y, v;

        if (t <= sim->t1) {                       /* fase 1 */
            v = sim->a1 * t;
            y = 0.5 * sim->a1 * t * t;
        } else {                                  /* fase 2 */
            double tau = t - sim->t1;
            v = sim->v1 + sim->a2 * tau;
            y = sim->y1 + sim->v1 * tau + 0.5 * sim->a2 * tau * tau;
        }

        if (y >= sim->h_target) {                 /* llego: ultimo punto */
            sim->altura[sim->pasos] = sim->h_target;
            sim->velocidad[sim->pasos] = sim->v2;
            sim->pasos++;
            break;
        }

        sim->altura[sim->pasos] = y;
        sim->velocidad[sim->pasos] = v;
        sim->pasos++;
    }
}

void mostrar_reporte(const SimulacionSLS *sim) {
    printf("\n--- REPORTE DE MISION ---\n");
    printf("a) v1 = %.1f m/s, y1 = %.1f m\n", sim->v1, sim->y1);

    if (sim->fase2_valida) {
        printf("b) v2 = %.1f m/s (apagado de motores a los %.1f s)\n",
               sim->v2, sim->t_apagado);
        printf("c) Altura maxima en caida libre = %.1f m\n", sim->h_max);
    } else {
        printf("AVISO: la fase 1 ya supera la altura objetivo (%.1f m).\n", sim->h_target);
        printf("       La fase 2 no existe con estos datos.\n");
    }

    printf("d) Aceleracion maxima = %.2f g\n", sim->g_max);

    if (!sim->fase2_valida)
        printf("VEREDICTO: perfil de vuelo invalido (sin fase 2).\n\n");
    else if (sim->g_max > G_LIMITE_TRIPULACION)
        printf("VEREDICTO: aceleracion excesiva para la tripulacion.\n\n");
    else
        printf("VEREDICTO: mision exitosa.\n\n");
}

void mostrar_trayectoria(const SimulacionSLS *sim) {
    if (sim->pasos == 0) {
        printf("\nNo hay trayectoria: con estos datos la fase 2 no existe.\n");
        return;
    }

    printf("\n  t[s]    altura[m]  velocidad[m/s]\n");

    for (int i = 0; i < sim->pasos - 1; i++) {
        int es_desacople = (i == (int)sim->t1);
        if (i % 20 == 0 || es_desacople) {
            printf("%7.1f %12.1f %15.1f", (double)i, sim->altura[i], sim->velocidad[i]);
            if (es_desacople) printf("   <- desacople SRB");
            printf("\n");
        }
    }

    printf("%7.1f %12.1f %15.1f   <- apagado motores\n",
           sim->t_apagado,
           sim->altura[sim->pasos - 1],
           sim->velocidad[sim->pasos - 1]);
}