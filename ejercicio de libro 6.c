#include <stdio.h>

#define MAX_VENDEDORES 100
#define SALARIO_BASE 200
#define COMISION 0.09

void calcularSalarios(float ventas[], int salarios[], int numVendedores);
void imprimirResultados(int salarios[]);

int main() {
    int numVendedores;
    float ventas[MAX_VENDEDORES];  
    int salarios[9] = {0};  

    printf("Ingrese el número de vendedores: ");
    scanf("%d", &numVendedores);

    for (int i = 0; i < numVendedores; i++) {
        printf("Ingrese las ventas del vendedor %d: $", i + 1);
        scanf("%f", &ventas[i]);
    }

    calcularSalarios(ventas, salarios, numVendedores);

    imprimirResultados(salarios);

    return 0;
}

void calcularSalarios(float ventas[], int salarios[], int numVendedores) {
    for (int i = 0; i < numVendedores; i++) {
        float salario = SALARIO_BASE + (ventas[i] * COMISION);  

        if (salario >= 200 && salario < 300) {
            salarios[0]++;
        } else if (salario >= 300 && salario < 400) {
            salarios[1]++;
        } else if (salario >= 400 && salario < 500) {
            salarios[2]++;
        } else if (salario >= 500 && salario < 600) {
            salarios[3]++;
        } else if (salario >= 600 && salario < 700) {
            salarios[4]++;
        } else if (salario >= 700 && salario < 800) {
            salarios[5]++;
        } else if (salario >= 800 && salario < 900) {
            salarios[6]++;
        } else if (salario >= 900 && salario < 1000) {
            salarios[7]++;
        } else {
            salarios[8]++; 
        }
    }
}

void imprimirResultados(int salarios[]) {
    printf("\n--- Resultados de salarios ---\n");
    printf("1) $200 - $299: %d vendedores\n", salarios[0]);
    printf("2) $300 - $399: %d vendedores\n", salarios[1]);
    printf("3) $400 - $499: %d vendedores\n", salarios[2]);
    printf("4) $500 - $599: %d vendedores\n", salarios[3]);
    printf("5) $600 - $699: %d vendedores\n", salarios[4]);
    printf("6) $700 - $799: %d vendedores\n", salarios[5]);
    printf("7) $800 - $899: %d vendedores\n", salarios[6]);
    printf("8) $900 - $999: %d vendedores\n", salarios[7]);
    printf("9) $1000 o más: %d vendedores\n", salarios[8]);
}
