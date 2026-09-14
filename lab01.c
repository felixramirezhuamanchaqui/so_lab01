#include <stdio.h>

struct Proceso {
    int pid;
    char nombre[20];
    int prioridad; // 1 (alta) a 5 (baja)
};

int buscarMayorPrioridad(struct Proceso *procesos, int n) {
    int indice = 0;

    for (int i = 1; i < n; i++) {
        if (procesos[i].prioridad < procesos[indice].prioridad) {
            indice = i;
        }
    }

    return indice;
}

int main() {
    struct Proceso procesos[5];
    int n;

    printf("¿Cuántos procesos desea registrar (1-5)? ");
    scanf("%d", &n);

    if (n < 1 || n > 5) {
        printf("Cantidad de procesos no válida.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nProceso %d\n", i + 1);

        printf("PID: ");
        scanf("%d", &procesos[i].pid);

        printf("Nombre: ");
        scanf("%19s", procesos[i].nombre);

        printf("Prioridad (1-5): ");
        scanf("%d", &procesos[i].prioridad);
    }

    int indiceMayor = buscarMayorPrioridad(procesos, n);

    printf("\nProceso de mayor prioridad:\n");
    printf("PID: %d\n", procesos[indiceMayor].pid);
    printf("Nombre: %s\n", procesos[indiceMayor].nombre);
    printf("Prioridad: %d\n", procesos[indiceMayor].prioridad);

    return 0;
}
