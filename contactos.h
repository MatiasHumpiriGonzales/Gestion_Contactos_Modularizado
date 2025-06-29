#ifndef CONTACTOS_H
#define CONTACTOS_H

#include <string>
using namespace std;

const int MAX_CONTACTOS = 100;

struct contactoEmail {
    string nombreCompleto;
    char sexo;
    int edad;
    string telefono;
    string email;
    string nacionalidad;
};

void agregarContacto(contactoEmail contactos[], int &total);
void eliminarContacto(contactoEmail contactos[], int &total);
void listarContactos(contactoEmail contactos[], int total);
void ordenarYListarPorServidor(contactoEmail contactos[], int total);

#endif

