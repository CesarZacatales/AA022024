#pragma once
#include <iostream>

using namespace std;

// Struct que almacena los datos de los empleados
struct Empleado
{
    int id;
    string nombreCompleto;
    float salario;
};

// Intercambio de nodos (swap)
void intercambiar(Empleado &a, Empleado &b)
{
    Empleado temp = a;
    a = b;
    b = temp;
}

// funcion que aplica max heap en el árbol binario
void maxHeap(Empleado arr[], int n, int i)
{
    int mayor = i;
    int Lf = 2 * i + 1;
    int Rg = 2 * i + 2;

    if (Lf < n && arr[Lf].salario > arr[mayor].salario)
        mayor = Lf;

    if (Rg < n && arr[Rg].salario > arr[mayor].salario)
        mayor = Rg;

    if (mayor != i)
    {
        intercambiar(arr[i], arr[mayor]);

        maxHeap(arr, n, mayor);
    }
}

// funcion que implementa heapsort
void heapsort(Empleado arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeap(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        intercambiar(arr[0], arr[i]);
        maxHeap(arr, i, 0);
    }
}

// Nueva función para mostrar los empleados
void mostrarEmpleados(const Empleado empleados[], int descendenteCount) {
    cout << "ID\t\tNombre Completo\t\t\t\t\tSalario" << endl;
    cout << "----------------------------------------------------------------" << endl;
    for (int i = descendenteCount - 1; i >= 0; i--) {
        cout << "ID: " << empleados[i].id << "\t\t" 
             << "Nombre: " << empleados[i].nombreCompleto << "\t\t" 
             << "Salario: $" << empleados[i].salario << endl;
    }
}