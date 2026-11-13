#ifndef SIMULADOR_H
#define SIMULADOR_H

#define G_TIERRA              9.80
#define MAX_PASOS             2000   /* alcanza para todos los rangos permitidos */
#define G_LIMITE_TRIPULACION  4.0    /* criterio propio: mas de 4 g = excesivo   */

typedef struct {
    /* Entradas */
    double a1, t1, a2, h_target;

    /* Resultados */
    double v1, y1, v2, h_max, g_max, t_apagado;
    int    fase2_valida;

    /* Trayectoria segundo a segundo */
    double altura[MAX_PASOS];
    double velocidad[MAX_PASOS];
    int    pasos;
} SimulacionSLS;

void calcular_mision(SimulacionSLS *sim);
void simular_ascenso(SimulacionSLS *sim);
void mostrar_reporte(const SimulacionSLS *sim);
void mostrar_trayectoria(const SimulacionSLS *sim);

#endif