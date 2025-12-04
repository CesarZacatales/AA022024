#include <iostream>

using namespace std;

// Función para realizar la ordenación por burbuja en un array
// arr[]: array a ordenar
// n: tamaño del array
void bubbleSort(int arr[], int n) {
    // Recorre cada elemento del array
    for(int i = 0; i < n-1; i++) {
        // Bandera para indicar si se realizó un intercambio en la iteración actual
        bool swapped = false;

        // Recorre los elementos del array de 0 a n-i-1
        for(int j = 0; j < n-i-1; j++) {
            // Compara el elemento actual con el siguiente elemento
            if(arr[j] > arr[j+1]) {
                // Intercambia los elementos si el elemento actual es mayor que el siguiente
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        // Si no se realizó ningún intercambio en la iteración actual, el array ya está ordenado
        if(!swapped) {
            break;
        }
    }
}

// Función principal
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; // Inicializa un array con elementos desordenados
    int n = sizeof(arr)/sizeof(arr[0]); // Calcula el número de elementos en el array
    bubbleSort(arr, n); // Llama a la función bubbleSort para ordenar el array

    // Recorre el array ordenado e imprime cada elemento
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Imprime el elemento actual seguido de un espacio
    }
    cout << endl; // Imprime un carácter de nueva línea
    return 0; // Retorna 0 para indicar una ejecución exitosa
}

