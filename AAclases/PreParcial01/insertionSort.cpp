
#include <iostream> // Include the iostream library for input and output operations

using namespace std; // Use the standard namespace to avoid prefixing std:: before standard library names

// El código que encajaría en $PLACEHOLDER$ es:

// Función para realizar la ordenación por inserción en un array
// arr[]: array a ordenar
// n: tamaño del array
void insertionSort(int arr[], int n) {
    // Recorre cada elemento del array comenzando desde el segundo elemento
    for(int i = 1; i < n; i++) {
        int key = arr[i]; // Almacena el elemento actual en key
        int j = i - 1; // Inicializa j al índice del elemento anterior

        // Mueve los elementos de arr[0..i-1], que son mayores que key, una posición adelante de su posición actual
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j]; // Desplaza el elemento a la derecha
            j = j - 1; // Pasa al elemento anterior
        }
        arr[j+1] = key; // Coloca el key en su posición correcta
    }
}

// Función principal
int main() {
    int arr[] = {12, 11, 13, 5, 6}; // Inicializa un array con elementos desordenados
    int n = sizeof(arr)/sizeof(arr[0]); // Calcula el número de elementos en el array
    insertionSort(arr, n); // Llama a la función insertionSort para ordenar el array

    // Recorre el array ordenado e imprime cada elemento
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Imprime el elemento actual seguido de un espacio
    }
    cout << endl; // Imprime un carácter de nueva línea
    return 0; // Retorna 0 para indicar una ejecución exitosa
}

// Pseudocódigo para la función de ordenación por inserción

// Función: insertionSort
// Entrada: arr (array de enteros), n (tamaño del array)
// Salida: array ordenado

// Para i desde 1 hasta n-1 hacer:
    // key = arr[i]
    // j = i - 1

    // Mientras j >= 0 y arr[j] > key hacer:
        // arr[j + 1] = arr[j]
        // j = j - 1

    // arr[j + 1] = key

// Fin de la función

// Función principal
// Inicializar arr con {12, 11, 13, 5, 6}
// Calcular n como el tamaño del array
// Llamar a insertionSort con arr y n

// Para i desde 0 hasta n-1 hacer:
    // Imprimir arr[i] seguido de un espacio

// Imprimir un carácter de nueva línea
// Retornar 0