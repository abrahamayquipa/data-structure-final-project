#include <iostream>
#include <string>
#include "aplicacion.hpp"
#include "listaEnlazadaSimple.hpp"
#include "usuario.hpp"
#include "usuarioRegular.hpp"
#include "usuarioDesarrollador.hpp"
#include "menu.hpp"
using namespace std;

int main() {
    int opcionMenuPrincipal, opcionMenuSecundario;

    // Estructuras de datos
    listaEnlazadaSimple<Aplicacion*, nullptr>* objetoListaEnlazadaSimple = new listaEnlazadaSimple<Aplicacion*, nullptr>();

    // Objetos
    UsuarioRegular* objetoUsuarioRegular = new UsuarioRegular();
    UsuarioDesarrollador* objetoUsuarioDesarrollador = new UsuarioDesarrollador();

    string correoElectronico, contrasena;

    do {
        system("cls");
        cout << "LOGIN: " << endl;
        cout << "Ingresar usuario: "; cin >> correoElectronico;
        cout << "Ingresar contrasena: "; cin >> contrasena;
    } while (correoElectronico != objetoUsuarioRegular->getCorreoElectronico() && correoElectronico != objetoUsuarioDesarrollador->getCorreoElectronico() ||
            contrasena != objetoUsuarioRegular->getContrasena() && contrasena != objetoUsuarioDesarrollador->getContrasena());

    string nombre, descripcion, comentarios;
    int calificacion, numeroDescargas;
    bool estaDisponibleComprar;

    while (true) {
        system("cls");
        opcionMenuPrincipal = menuPrincipal();
        system("cls");

        switch (opcionMenuPrincipal) {
        case 1:
            cout << "BUSCAR APLICACION: " << endl;

            break;
        case 2:
            cout << "INSTALAR APLICACION: " << endl;

            break;
        case 3:
            cout << "DESINSTALAR APLICACION: " << endl;

            break;
        case 4:
            cout << "COMPRAR APLICACION: " << endl;

            break;
        case 5:
            cout << "CALIFICAR APLICACION: " << endl;

            break;
        case 6:
            cout << "COMENTAR APLICACION: " << endl;

            break;
        case 7:
            cout << "VER INFORMACION DE LA APLICACION: " << endl;

            break;
        case 8:
            cout << "DENUNCIAR APLICACION: " << endl;
            break;
        case 9:
            cout << "AGREGAR APLICACION: " << endl;
            cout << "Nombre: "; cin >> nombre;
            cout << "Descripcion: "; cin >> descripcion;
            cout << "Opcion de compra: "; cin >> estaDisponibleComprar;

            Aplicacion* objetoAplicacion = new Aplicacion(nombre, descripcion, estaDisponibleComprar);
            objetoListaEnlazadaSimple->agregaFinal(objetoAplicacion);
            break;
        }
    };
    system("pause>0");
  
    delete objetoListaEnlazadaSimple;
    delete objetoUsuarioRegular;
    delete objetoUsuarioDesarrollador;
    return 0;
};