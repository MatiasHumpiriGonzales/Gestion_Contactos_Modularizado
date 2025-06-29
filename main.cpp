#include <iostream>
#include "contactos.h"
using namespace std;

int main() {
    contactoEmail contactos[MAX_CONTACTOS];
    int total = 0;
    int opcion;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Agregar contacto\n";
        cout << "2. Eliminar contacto\n";
        cout << "3. Mostrar listado general\n";
        cout << "4. Mostrar contactos ordenados por servidor de correo\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: agregarContacto(contactos, total); break;
            case 2: eliminarContacto(contactos, total); break;
            case 3: listarContactos(contactos, total); break;
            case 4: ordenarYListarPorServidor(contactos, total); break;
            case 5: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n"; break;
        }

    } while (opcion != 5);

    return 0;
}

