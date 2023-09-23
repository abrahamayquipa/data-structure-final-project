#include <iostream>
#include <string>
// conio.h para usar _getch()
#include <conio.h> 
// windows.h para manipular la consola
#include <Windows.h>
#include "aplicacion.hpp"
#include "usuarioRegular.hpp"
#include "usuarioDesarrollador.hpp"
#include "usuarioStaff.hpp"
#include "menu.hpp"
using namespace std;

int main() {
    int opcionMenuPrincipal;

    UsuarioRegular* objetoUsuarioRegular = new UsuarioRegular();
    UsuarioDesarrollador* objetoUsuarioDesarrollador = new UsuarioDesarrollador();
    UsuarioStaff* objetoUsuarioStaff = new UsuarioStaff();

    Operaciones* objetoOperaciones = new Operaciones();

    string correoElectronico, contrasena;

    do {
        system("cls");
        cout << "LOGIN: " << endl;
        cout << "Ingresar usuario: "; cin >> correoElectronico;
        cout << "Ingresar contrasena: "; cin >> contrasena;
    } while (
        correoElectronico != objetoUsuarioRegular->getCorreoElectronico() && correoElectronico != objetoUsuarioDesarrollador->getCorreoElectronico() && correoElectronico != objetoUsuarioStaff->getCorreoElectronico() || 
        contrasena != objetoUsuarioRegular->getContrasena() && contrasena != objetoUsuarioDesarrollador->getContrasena() && contrasena != objetoUsuarioStaff->getContrasena());
    
    while (true) {
        if (correoElectronico == "regular") {
            opcionMenuPrincipal = menuRegularPrincipal();
            menuRegularSecundario(opcionMenuPrincipal, objetoOperaciones);
        }
        else if (correoElectronico == "desarrollador") {
            opcionMenuPrincipal = menuDesarrolladorPrincipal();
            menuDesarrolladorSecundario(opcionMenuPrincipal, objetoOperaciones);
        }
        else if (correoElectronico == "staff") {
            opcionMenuPrincipal = menuStaffPrincipal();
            menuStaffSecundario(opcionMenuPrincipal, objetoOperaciones);
        }
        else break;
        _getch();
    }

    system("pause>0");
    delete objetoUsuarioRegular;
    delete objetoUsuarioDesarrollador;
    delete objetoUsuarioStaff;
    return 0;
};