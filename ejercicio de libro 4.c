#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANZAMIENTOS 1000

void simularLanzamientos(int resultados[], int numLanzamientos);
void imprimirResultados(int resultados[]);

int main() {
    int resultados[13] = {0};  
    
    srand(time(NULL));  
    
    simularLanzamientos(resultados, NUM_LANZAMIENTOS);
    imprimirResultados(resultados);
    
    return 0;
}

void simularLanzamientos(int resultados[], int numLanzamientos) {
    for (int i = 0; i < numLanzamientos; i++) {
        int dado1 = rand() % 6 + 1;  
        int dado2 = rand() % 6 + 1;  
        int suma = dado1 + dado2;  
        resultados[suma]++;
    }
}

void imprimirResultados(int resultados[]) {
    printf("\nResultados de %d lanzamientos:\n", NUM_LANZAMIENTOS);
    for (int i = 2; i <= 12; i++) {
        printf("Suma %d: %d veces (%.2f%%)\n", i, resultados[i], (resultados[i] / (float)NUM_LANZAMIENTOS) * 100);
    }
    printf("\nAproximadamente %.2f%% de los lanzamientos resultaron en una suma de 7.\n", (resultados[7] / (float)NUM_LANZAMIENTOS) * 100);
}