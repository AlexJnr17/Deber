#include <stdio.h>

#define MAX_ALUMNOS 100

void ingresarCalificaciones(float calificaciones[], int *numAlumnos);
void mostrarCalificaciones(float calificaciones[], int numAlumnos);
void calcularCalificaciones(float calificaciones[], int numAlumnos);

int main() {
    float calificaciones[MAX_ALUMNOS];  
    int numAlumnos = 0;
    int opcion;

    do {
        printf("\nMENU\n");
        printf("1. Ingresar calificaciones\n");
        printf("2. Mostrar calificaciones\n");
        printf("3. Calcular calificaciones\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                ingresarCalificaciones(calificaciones, &numAlumnos);
                break;
            case 2:
                mostrarCalificaciones(calificaciones, numAlumnos);
                break;
            case 3:
                calcularCalificaciones(calificaciones, numAlumnos);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    } while (opcion != 4);

    return 0;
}

void ingresarCalificaciones(float calificaciones[], int *numAlumnos) {
    printf("Ingrese el número de alumnos: ");
    scanf("%d", numAlumnos);

    for (int i = 0; i < *numAlumnos; i++) {
        printf("Ingrese la calificación del alumno %d: ", i + 1);
        scanf("%f", &calificaciones[i]);
    }
}

void mostrarCalificaciones(float calificaciones[], int numAlumnos) {
    printf("\nCalificaciones ingresadas:\n");
    for (int i = 0; i < numAlumnos; i++) {
        printf("Alumno %d: %.2f\n", i + 1, calificaciones[i]);
    }
}

void calcularCalificaciones(float calificaciones[], int numAlumnos) {
    int rangoA = 0, rangoB = 0, rangoC = 0, rangoD = 0, rangoE = 0;
    float max = calificaciones[0], min = calificaciones[0];

    for (int i = 0; i < numAlumnos; i++) {
        if (calificaciones[i] >= 9 && calificaciones[i] <= 10) {
            rangoA++;
        } else if (calificaciones[i] >= 8 && calificaciones[i] < 9) {
            rangoB++;
        } else if (calificaciones[i] >= 6 && calificaciones[i] < 8) {
            rangoC++;
        } else if (calificaciones[i] >= 4 && calificaciones[i] < 6) {
            rangoD++;
        } else {
            rangoE++;
        }

        if (calificaciones[i] > max) {
            max = calificaciones[i];
        }

        if (calificaciones[i] < min) {
            min = calificaciones[i];
        }
    }

    printf("\nEstadísticas de las calificaciones:\n");
    printf("Cantidad de estudiantes con A (9 - 10): %d\n", rangoA);
    printf("Cantidad de estudiantes con B (8 - 8.99): %d\n", rangoB);
    printf("Cantidad de estudiantes con C (6 - 7.99): %d\n", rangoC);
    printf("Cantidad de estudiantes con D (4 - 5.99): %d\n", rangoD);
    printf("Cantidad de estudiantes con E (menos de 4): %d\n", rangoE);
    printf("Nota más alta: %.2f\n", max);
    printf("Nota más baja: %.2f\n", min);
}
