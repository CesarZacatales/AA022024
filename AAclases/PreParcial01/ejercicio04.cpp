#include <iostream>
#include <vector>

bool tieneSeccionAscendente(const std::vector<int>& A, int n) {
    if (n <= 1) return true; // Cualquier subsección de longitud 1 es ascendente

    int count = 1; // Contador de la longitud de la subsección ascendente actual

    for (size_t i = 1; i < A.size(); ++i) {
        if (A[i] > A[i - 1]) {
            count++;
            if (count >= n) {
                return true;
            }
        } else {
            count = 1; // Reiniciar el contador si la secuencia se rompe
        }
    }

    return false;
}

int main() {
    std::vector<int> A = {1, 2, 3, 5, 4, 6, 7, 8};
    int n = 4;

    if (tieneSeccionAscendente(A, n)) {
        std::cout << "El arreglo tiene al menos una sección de " << n << " enteros en orden ascendente." << std::endl;
    } else {
        std::cout << "El arreglo no tiene una sección de " << n << " enteros en orden ascendente." << std::endl;
    }

    return 0;
}

