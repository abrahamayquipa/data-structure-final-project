#include <iostream>
#include <string>
#include "aplicacion.hpp"
#include "usuarioRegular.hpp"
#include "usuarioDesarrollador.hpp"
#include "usuarioStaff.hpp"
#include "menu.hpp"
using namespace std;

int main() {
    int opcionMenuPrincipal, opcionMenuSecundario;

    UsuarioRegular* objetoUsuarioRegular = new UsuarioRegular();
    UsuarioDesarrollador* objetoUsuarioDesarrollador = new UsuarioDesarrollador();
    UsuarioStaff* objetoUsuarioStaff = new UsuarioStaff();

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
        system("cls");
        if (correoElectronico == "regular") { 
            opcionMenuPrincipal = menuRegularPrincipal(); 
            opcionMenuSecundario = 1; 
        } else if (correoElectronico == "desarrollador") { 
            opcionMenuPrincipal = menuDesarrolladorPrincipal(); 
            opcionMenuSecundario = 2; 
        } else { 
            opcionMenuPrincipal = menuStaffPrincipal(); 
            opcionMenuSecundario = 3; 
        }
        system("cls");

        switch (opcionMenuSecundario){
        case 1: 
            menuRegularSecundario(opcionMenuPrincipal); 
            break;
        case 2: 
            menuDesarrolladorSecundario(opcionMenuPrincipal); 
            break;
        case 3: 
            menuStaffSecundario(opcionMenuPrincipal); 
            break;
        }
    };
    system("pause>0");
    delete objetoUsuarioRegular;
    delete objetoUsuarioDesarrollador;
    delete objetoUsuarioStaff;
    return 0;
};