// header guards
#ifndef READER_H
#define READER_H

#include <iostream>
#include <fstream>

using namespace std;

// Define la estructura para almacenar la información de ventas
struct SalesData
{
    char customer_id[10]; // Ajusta el tamaño según lo necesario
    char product_id[10];  // Ajusta el tamaño según lo necesario
    int quantity;         // Puedes usar int directamente
    double total_price;   // Precio total
    char purchase_date[11]; // Por ejemplo, "MM/DD/YYYY"
};

// Función para cargar datos
void load_data(SalesData *data, const int rows = 1000)
{
    // Define el nombre del archivo
    const char *filename = "./sales.txt";

    // Abre el archivo
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Failed to open the file." << endl;
        return;
    }

    int i = 0;
    while (i < rows && file)
    {
        // Lee los datos
        file >> data[i].customer_id >> data[i].product_id >> data[i].quantity >> data[i].total_price >> data[i].purchase_date;

        // Verifica si se han leído todos los datos
        if (file) {
            i++; // Incrementa el índice solo si la lectura fue exitosa
        }
    }

    // Cierra el archivo
    file.close();
}

#endif
