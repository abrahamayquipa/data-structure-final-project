#ifndef __MENU_HPP__
#define __MENU_HPP__

#include "operaciones.hpp"
#include <iostream>
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
    cout << "TIENDA DE APLICACIONES" << endl;
    cout << "MENU COMO USUARIO DESARROLLADOR:" << endl;
    cout << "1. Buscar aplicacion" << endl;
    cout << "2. Agregar aplicacion" << endl;
    cout << "3. Listar todas las aplicaciones disponibles" << endl;
    cout << "4. Ordenamiento inverso de la lista de aplicaciones disponibles" << endl;
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
        objetoOperaciones->buscarAplicacion(nombre);
        break;
    case 2: 
        cout << "AGREGAR APLICACION: " << endl;
        objetoOperaciones->agregarAplicacion();
        break;
    case 3:
        cout << "LISTA:" << endl;
        objetoOperaciones->mostrarAplicaciones();
        break;
    case 4:
        cout << "ORDENAR INVERSAMENTE:" << endl;
        cout << "LISTA ORIGINAL:" << endl;
        objetoOperaciones->mostrarAplicaciones();
        cout << endl;
        cout << "LISTA INVERSA:" << endl;
        objetoOperaciones->ordenarInvesamente();
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

#endif