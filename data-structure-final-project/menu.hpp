#include <iostream>
#include "operaciones.hpp"
using namespace std;

Operaciones* objetoOperaciones = new Operaciones();
int opcion = 0;

int menuRegularPrincipal() {
    cout << "TIENDA DE APLICACIONES" << endl;
    cout << "MENU COMO USUARIO REGULAR:" << endl;
    cout << "1. Buscar aplicacion" << endl;
    cout << "Elegir opcion: "; cin >> opcion;
    return opcion;
}

void menuRegularSecundario(int opcion) {
    switch (opcion) {
    case 1:
        cout << "BUSCAR APLICACION: " << endl;

        break;
    }
}

int menuDesarrolladorPrincipal() {
    cout << "TIENDA DE APLICACIONES" << endl;
    cout << "MENU COMO USUARIO DESARROLLADOR:" << endl;
    cout << "1. Buscar aplicacion" << endl;
    cout << "2. Agregar aplicacion" << endl;
    cout << "Elegir opcion: "; cin >> opcion;
    return opcion;
}

void menuDesarrolladorSecundario(int opcion) {
    switch (opcion) {
    case 1:
        cout << "BUSCAR APLICACION: " << endl;

        break;
    case 2: 
        objetoOperaciones->insertarFinal();
        break;
    }
}

int menuStaffPrincipal() {
    cout << "TIENDA DE APLICACIONES" << endl;
    cout << "MENU COMO USUARIO STAFF:" << endl;
    cout << "1. Buscar aplicacion" << endl;
    cout << "Elegir opcion: "; cin >> opcion;
    return opcion;
}

void menuStaffSecundario(int opcion) {
    switch (opcion) {
    case 1:
        cout << "BUSCAR APLICACION: " << endl;

        break;
    }
}

int menuInterno() {
    cout << "PLAY STORE" << endl;
    cout << "MENU:" << endl;
    cout << "2. Instalar aplicacion" << endl;
    cout << "3. Desinstalar aplicacion" << endl;
    cout << "4. Comprar aplicacion" << endl;
    cout << "5. Calificar aplicacion" << endl;
    cout << "6. Comentar aplicacion" << endl;
    cout << "7. Ver informacion de aplicacion" << endl;
    cout << "8. Denunciar aplicacion" << endl;
    cout << "Elegir opcion: "; cin >> opcion;
    return opcion;
}