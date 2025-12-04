#include <vector>
#include <iostream>

using namespace std;

// Definir un macro para obtener el bit menos significativo de un número
#define LSOne(S) (S & (-S))

// Definición de la clase para el Árbol Fenwick (también conocido como Árbol Binario Indexado)
class FenwickTree {
private:
    vector<int> FT; // Vector interno para almacenar el Árbol Fenwick

public:
    // Constructor para inicializar el Árbol Fenwick con un tamaño dado
    FenwickTree(int m) {
        FT.assign(m + 1, 0); // Inicializar el vector con ceros
    }

    // Constructor para inicializar el Árbol Fenwick con un arreglo dado
    FenwickTree(vector<int> &arr) {
        int m = arr.size(); // Obtener el tamaño del arreglo de entrada
        FT.assign(m + 1, 0); // Inicializar el vector con ceros
        // Construir el Fenwick Tree usando el método de actualización
        for (int i = 0; i < m; i++) {
            update(i + 1, arr[i]); // Usamos i+1 porque el árbol Fenwick es 1-indexed
        }
    }

    // Función para obtener la consulta de suma de rango desde 1 hasta pos
    int rsq(int pos) {
        int sum = 0; // Inicializar la suma
        while (pos > 0) {
            sum += FT[pos]; // Agregar el valor en la posición actual a la suma
            pos -= LSOne(pos); // Moverse al nodo padre
        }
        return sum; // Devolver la suma calculada
    }

    // Función para obtener la consulta de suma de rango desde a hasta b
    int rsq(int a, int b) {
        return rsq(b) - rsq(a - 1); // Usar la función rsq para obtener la suma desde a hasta b
    }

    // Función para actualizar el valor en una posición específica
    void update(int pos, int val) {
        while (pos < FT.size()) {
            FT[pos] += val; // Actualizar el valor en la posición actual
            pos += LSOne(pos); // Moverse al siguiente índice a actualizar
        }
    }
};

int main() {
    int n;
    cout << "Ingrese el tamano del arreglo: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Ingrese los elementos del arreglo:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Ingresar el arreglo
    }

    FenwickTree ft(arr); // Inicializar el Árbol Fenwick con el arreglo

    int a, b;
    cout << "Ingrese el rango para la suma (a b): ";
    cin >> a >> b;
    cout << "Suma entre: " << ft.rsq(a, b) << "\n"; // Imprimir la suma desde a hasta b

    int pos;
    cout << "Ingrese la posicion para la suma hasta: ";
    cin >> pos;
    cout << "Suma hasta: " << ft.rsq(pos) << "\n"; // Imprimir la suma desde 1 hasta pos

    return 0; // Retornar 0 para indicar una ejecución exitosa
}
