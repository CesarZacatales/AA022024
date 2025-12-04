#include <iostream>
#include <fstream>
#include "heap.hpp"

using namespace std;

int main() {
    // abrir y leer empleados.txt
    ifstream archivo("../empleados.txt");
    if (!archivo.is_open()) {
        cout << "Archivo no encontrado" << endl;
        return 1;
    }

    Empleado empleados[1000];
    int descendenteCount = 0;

    // lee y almacena los datos del archivo en el arreglo
    while (archivo >> empleados[descendenteCount].id) {
        archivo.ignore();
        getline(archivo, empleados[descendenteCount].nombreCompleto, '\t'); // lee hasta que encuentra una tabulación
        archivo >> empleados[descendenteCount].salario;
        descendenteCount++;
        if (descendenteCount >= 1000)
            break; // Frena el ciclo para no leer más de mil empleados (para este caso)
    }
    // cerrando empleados.txt
    archivo.close();

    // ordenamiento de empleados por salario mayor a salario menor
    heapsort(empleados, descendenteCount);

    // llamada a la función para mostrar empleados
    mostrarEmpleados(empleados, descendenteCount);

    return 0;
}