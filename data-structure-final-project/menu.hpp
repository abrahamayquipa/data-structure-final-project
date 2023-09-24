#ifndef __MENU_HPP__
#define __MENU_HPP__
#include "listaEnlazada.hpp"
#include "operaciones.hpp"
#include <iostream>
using namespace std;

int menuRegularPrincipal() {
    auto mostrarMenu = []() -> int {
        system("cls");
        int opcion = 0;
        cout << "TIENDA DE APLICACIONES" << endl;
        cout << "MENU COMO USUARIO REGULAR:" << endl;
        cout << "1. Buscar aplicacion" << endl;
        cout << "Elegir opcion: "; cin >> opcion;
        return opcion;
    };
    return mostrarMenu();
}

void menuRegularSecundario(int opcion, Operaciones* objetoOperaciones) {
    system("cls");
    string nombre;
    switch (opcion) {
    case 1:
        cout << "BUSCAR APLICACION: " << endl;
        cout << "Nombre de la aplicacion: "; cin >> nombre;
        objetoOperaciones->buscarAplicacion(nombre);
        break;
    }
}

int menuDesarrolladorPrincipal() {
    auto mostrarMenu = []() -> int {
        system("cls");
        int opcion = 0;
        cout << "TIENDA DE APLICACIONES" << endl;
        cout << "MENU COMO USUARIO DESARROLLADOR:" << endl;
        cout << "1. Buscar aplicacion" << endl;
        cout << "2. Agregar aplicacion" << endl;
        cout << "3. Listar todas las aplicaciones disponibles" << endl;
        cout << "4. Ordenamiento inverso de la lista de aplicaciones disponibles" << endl;
        cout << "5. Listar todas las aplicaciones instaladas actualmente" << endl;
        cout << "6. Listar todas las aplicaciones instaladas anteriormente - biblioteca de descargas" << endl;
        cout << "Elegir opcion: "; cin >> opcion;
        return opcion;
    };
    return mostrarMenu();
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
        objetoOperaciones->invertirLista();
        break;
    case 5:
        objetoOperaciones->menuInternoOpciones(8, 0);
        break;
    case 6: 
        objetoOperaciones->menuInternoOpciones(9, 0);
        break;
    }
}

int menuStaffPrincipal() {
    auto mostrarMenu = []() -> int {
        system("cls");
        int opcion = 0;
        cout << "TIENDA DE APLICACIONES" << endl;
        cout << "MENU COMO USUARIO STAFF:" << endl;
        cout << "1. Buscar aplicacion" << endl;
        cout << "Elegir opcion: "; cin >> opcion;
        return opcion;
    };
    return mostrarMenu();
}

void menuStaffSecundario(int opcion, Operaciones* objetoOperaciones) {
    system("cls");
    string nombre;
    switch (opcion) {
    case 1:
        cout << "BUSCAR APLICACION: " << endl;
        cout << "Nombre de la aplicacion: "; cin >> nombre;
        objetoOperaciones->buscarAplicacion(nombre);
        break;
    }
}

#endif