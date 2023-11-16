#ifndef __MENU_HPP__
#define __MENU_HPP__
//biblioteca que permite el manipular la consola
#include <windows.h>

#include "operaciones.hpp"
#include <iostream>
using namespace std;

/*
* Fuente 1:
* Generador de ASCII ART: https://es.rakko.tools/tools/68/
* Fuente 2:
* Poner colores a la consola: https://github.com/abrahamayquipa/programming-I-final-project/blob/main/main.cpp
*/

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

int menuPrincipal() {
    auto mostrarMenu = []() -> int {
        system("cls");
        SetConsoleTextAttribute(color, 11);
        int opcion = 0;
        cout << "\n\n\n\n";
        cout << "\t\t\t\t********************************************************************" << endl;
        cout << "\t\t\t      ::::::::   :::::::::::           :::        :::::::::       ::::::::" << endl;
        cout << "\t\t\t    :+:    :+:      :+:             :+: :+:      :+:    :+:     :+:    :+:" << endl;
        cout << "\t\t\t   +:+             +:+            +:+   +:+     +:+    +:+     +:+" << endl;
        cout << "\t\t\t  +#++:++#++      +#+           +#++:++#++:    +#++:++#:      +#++:++#++" << endl;
        cout << "\t\t\t        +#+      +#+           +#+     +#+    +#+    +#+            +#+" << endl;
        cout << "\t\t\t#+#    #+#      #+#           #+#     #+#    #+#    #+#     #+#    #+#" << endl;
        cout << "\t\t\t########       ###           ###     ###    ###    ###      ########" << endl;
        cout << "\t\t\t*********************************STORE********************************" << endl;
        SetConsoleTextAttribute(color, 15);
        cout << "\n\t\t\t****************************MENU DE OPCIONES**************************" << endl;
        cout << "\t\t\t1. Buscar aplicacion" << endl;
        cout << "\t\t\t2. Agregar aplicacion" << endl;
        cout << "\t\t\t3. Listar todas las aplicaciones disponibles" << endl;
        cout << "\t\t\t4. Ordenamiento ascendente la lista de aplicaciones disponibles" << endl;
        cout << "\t\t\t5. Listar todas las aplicaciones instaladas actualmente" << endl;
        cout << "\t\t\t6. Listar todas las aplicaciones instaladas anteriormente - biblioteca de descargas" << endl;
        cout << "\t\t\t7. Listar mediante QUICKSELECT" << endl;
        cout << endl << "\t\t\tOPCION EXTRA:" << endl;
        cout << "\t\t\t8. Cambiar tipo de usuario" << endl;
        cout << "\t\t\t9. Usar el algoritmo dataset generator" << endl << endl;
        cout << "\t\t\tElegir opcion: "; cin >> opcion;
        return opcion;
        };
    return mostrarMenu();
}

void menuSecundario(Operaciones* objetoOperaciones) {
    string nombre;
    int opcion = menuPrincipal();

    system("cls");
    switch (opcion) {
    case 1:
        cout << "\n\n\n\n\t\t\tBUSCAR APLICACION: " << endl;
        cout << "\t\t\tNombre de la aplicacion: "; cin >> nombre;
        cout << endl;
        objetoOperaciones->buscarAplicacion(nombre);
        break;
    case 2:
        cout << "\n\n\n\n\t\t\tAGREGAR APLICACION: " << endl;
        objetoOperaciones->agregarAplicacion();
        break;
    case 3:
        cout << "\n\n\n\n\t\t\tLISTA:" << endl;
        objetoOperaciones->mostrarAplicaciones();
        break;
    case 4:
        objetoOperaciones->menuInternoOpciones(5, 0);
        break;
    case 5:
        objetoOperaciones->menuInternoOpciones(6, 0);
        break;
    case 6:
        objetoOperaciones->menuInternoOpciones(7, 0);
        break;
    case 7:
        objetoOperaciones->menuInternoOpciones(8, 0);
        break;
    case 8:
        objetoOperaciones->menuInternoOpciones(9, 0);
        break;
    case 9:
        objetoOperaciones->menuInternoOpciones(10, 0);
        break;
    }
}

#endif