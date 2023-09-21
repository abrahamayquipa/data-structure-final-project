#include <iostream>
#include "operaciones.hpp"
using namespace std;

int menuRegularPrincipal() {
    system("cls");
    int opcion = 0;
    cout << "TIENDA DE APLICACIONES" << endl;
    cout << "MENU COMO USUARIO REGULAR:" << endl;
    cout << "1. Buscar aplicacion" << endl;
    cout << "Elegir opcion: "; cin >> opcion;
    return opcion;
}

void menuRegularSecundario(int opcion, Operaciones* objetoOperaciones) {
    system("cls");
    switch (opcion) {
    case 1:
        cout << "BUSCAR APLICACION: " << endl;
        break;
    }
}

int menuDesarrolladorPrincipal() {
    system("cls");
    int opcion = 0;
    cout << "TIENDA DE APLICACIONES";
    cout << "MENU COMO USUARIO DESARROLLADOR:" << endl;
    cout << "1. Buscar aplicacion" << endl;
    cout << "2. Agregar aplicacion" << endl;
    cout << "3. Listar aplicacion" << endl;
    cout << "Elegir opcion: "; cin >> opcion;
    return opcion;
}

void menuDesarrolladorSecundario(int opcion, Operaciones* objetoOperaciones) {
    system("cls");
    string nombre;
    switch (opcion) {
    case 1:
        cout << "BUSCAR APLICACION: " << endl;
        cout << "Nombre de la aplicacion: "; cin >> nombre;
        objetoOperaciones->buscarElemento(nombre);
        break;
    case 2: 
        cout << "AGREGAR APLICACION: " << endl;
        objetoOperaciones->insertarFinal();
        break;
    case 3:
        cout << "LISTA:" << endl << endl;
        objetoOperaciones->mostrarContenidoLista();
        break;
    }
}

int menuStaffPrincipal() {
    system("cls");
    int opcion = 0;
    cout << "TIENDA DE APLICACIONES" << endl;
    cout << "MENU COMO USUARIO STAFF:" << endl;
    cout << "1. Buscar aplicacion" << endl;
    cout << "Elegir opcion: "; cin >> opcion;
    return opcion;
}

void menuStaffSecundario(int opcion, Operaciones* objetoOperaciones) {
    system("cls");
    switch (opcion) {
    case 1:
        cout << "BUSCAR APLICACION: " << endl;

        break;
    }
}

int menuInterno() {
    system("cls");
    int opcion = 0;
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