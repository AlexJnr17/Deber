#include <stdio.h>

#define TAM 99

float calcularPromedio(int arr[], int tam);
float calcularMediana(int arr[], int tam);
int calcularModa(int arr[], int tam);
void ordenar(int arr[], int tam);

int main() {
    int respuestas[TAM] = {7, 3, 5, 2, 1, 9, 6, 4, 8, 5, 2, 3, 9, 7, 1, 6, 8, 3, 7, 5, 4, 8, 9, 6, 2, 5, 1, 3, 9, 8, 6, 4, 5, 7, 3, 2, 6, 4, 1, 8, 9, 3, 6, 4, 5, 7, 9, 3, 6, 2, 8, 5, 7, 1, 9, 4, 8, 6, 5, 3, 7, 2, 1, 4, 8, 6, 9, 3, 7, 2, 5, 8, 1, 4, 9, 6, 7, 3, 2, 5, 4, 1, 9, 8, 6, 7, 5, 3, 9};
    
    float promedio = calcularPromedio(respuestas, TAM);
    float mediana = calcularMediana(respuestas, TAM);
    int moda = calcularModa(respuestas, TAM);
    
    printf("Promedio: %.2f\n", promedio);
    printf("Mediana: %.2f\n", mediana);
    printf("Moda: %d\n", moda);
    
    return 0;
}

float calcularPromedio(int arr[], int tam) {
    float suma = 0;
    for (int i = 0; i < tam; i++) {
        suma += arr[i];
    }
    return suma / tam;
}

float calcularMediana(int arr[], int tam) {
    ordenar(arr, tam);  
    if (tam % 2 == 0) {
        return (arr[tam / 2 - 1] + arr[tam / 2]) / 2.0;  
    } else {
        return arr[tam / 2];  
    }
}

int calcularModa(int arr[], int tam) {
    int frecuencia[10] = {0};  
    for (int i = 0; i < tam; i++) {
        frecuencia[arr[i]]++;
    }
    
    int moda = 0;
    for (int i = 1; i <= 9; i++) {
        if (frecuencia[i] > frecuencia[moda]) {
            moda = i;
        }
    }
    return moda;
}

void ordenar(int arr[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
