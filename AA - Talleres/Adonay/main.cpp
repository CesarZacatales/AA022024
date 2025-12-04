#include <iostream>
#include "reader.hpp"

using namespace std;

// Intercambia los valores del array
void swap(SalesData *array, int i, int j)
{
    SalesData temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

// Funciones MinHeapify y heapsort (no cambiarán)
void MinHeapify(SalesData *array, int i, int heap_size)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;

    if (l < heap_size && array[l].total_price < array[smallest].total_price)
        smallest = l;

    if (r < heap_size && array[r].total_price < array[smallest].total_price)
        smallest = r;

    if (smallest != i)
    {
        swap(array, i, smallest);
        MinHeapify(array, smallest, heap_size);
    }
}

void BuildMinHeap(SalesData *array, int size)
{
    for (int i = (size / 2) - 1; i >= 0; i--)
        MinHeapify(array, i, size);
}

void Heapsort(SalesData *data, int n)
{
    int heap_size = n;
    BuildMinHeap(data, heap_size);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(data, 0, i);
        heap_size--;
        MinHeapify(data, 0, heap_size);
    }
}

int main()
{
    const int maxSales = 1000;
    SalesData *sales = new SalesData[maxSales];

    load_data(sales, maxSales);

    // Contar cuántas filas fueron leídas
    int n = 0;
    while (n < maxSales && sales[n].customer_id != 0) {
        n++;
    }

    // Ordena el trade price con heapsort
    Heapsort(sales, n);

    cout << "Con minHeap: \n";
    for (int i = 0; i < n; i++)
    {
        cout << "ID Cliente: " << sales[i].customer_id << ", "
             << "ID Producto: " << sales[i].product_id << ", "
             << "Cantidad: " << sales[i].quantity << ", "
             << "Precio Total: " << sales[i].total_price << ", "
             << "Fecha de Compra: " << sales[i].purchase_date << endl;
    }

    delete[] sales; // Liberar memoria
    return 0;
}
