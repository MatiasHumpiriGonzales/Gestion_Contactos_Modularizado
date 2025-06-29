#include <iostream>
#include "contactos.h"
string obtenerServidor(string correo) {
    size_t pos = correo.find('@');
    if (pos != string::npos) {
        return correo.substr(pos + 1);
    }
    return "";
}
void agregarContacto(contactoEmail contactos[], int &total) {
    if (total >= MAX_CONTACTOS) {
        cout << "No se puede agregar más contactos.\n";
        return;
    }
    contactoEmail a;
    cout << "Nombre completo: ";
    getline(cin, a.nombreCompleto);
    cout << "Sexo (M/F): ";
    cin >> a.sexo;
    cout << "Edad: ";
    cin >> a.edad;
    cin.ignore();
    cout << "Telefono: ";
    getline(cin, a.telefono);
    cout << "Email: ";
    getline(cin, a.email);
    cout << "Nacionalidad: ";
    getline(cin, a.nacionalidad);
    contactos[total] = a;
    total++;
    cout << "Contacto agregado.\n";
}
void eliminarContacto(contactoEmail contactos[], int &total) {
    string nombreBuscar;
    cout << "Ingrese el nombre del contacto a eliminar: ";
    getline(cin, nombreBuscar);
    bool encontrado = false;

    for (int i = 0; i < total; i++) {
        if (contactos[i].nombreCompleto == nombreBuscar) {
            for (int j = i; j < total - 1; j++) {
                contactos[j] = contactos[j + 1];
            }
            total--;
            encontrado = true;
            cout << "Contacto eliminado.\n";
            break;
        }
    }
    if (!encontrado) {
        cout << "No se encontró el contacto.\n";
    }
}
void listarContactos(contactoEmail contactos[], int total) {
    if (total == 0) {
        cout << "No hay contactos registrados.\n";
        return;
    }
    for (int i = 0; i < total; i++) {
        cout << "Nombre: " << contactos[i].nombreCompleto << endl;
        cout << "Sexo: " << contactos[i].sexo << endl;
        cout << "Edad: " << contactos[i].edad << endl;
        cout << "Telefono: " << contactos[i].telefono << endl;
        cout << "Email: " << contactos[i].email << endl;
        cout << "Nacionalidad: " << contactos[i].nacionalidad << endl;
        cout << "--------------------------\n";
    }
}
void ordenarYListarPorServidor(contactoEmail contactos[], int total) {
    if (total == 0) {
        cout << "No hay contactos registrados.\n";
        return;
    }
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (obtenerServidor(contactos[j].email) > obtenerServidor(contactos[j + 1].email)) {
                contactoEmail temp = contactos[j];
                contactos[j] = contactos[j + 1];
                contactos[j + 1] = temp;
            }
        }
    }
    listarContactos(contactos, total);
}

