#include <iostream>
#include <string>
// conio.h para usar _getch()
#include <conio.h> 
// librerias para nuestra semilla
#include <cstdlib> 
#include <ctime> 

#include "aplicacion.hpp"
#include "usuarioRegular.hpp"
#include "usuarioDesarrollador.hpp"
#include "usuarioStaff.hpp"
#include "menu.hpp"
using namespace std;

int main() {
    srand(time(NULL));

    Operaciones* objetoOperaciones = new Operaciones();

    system("cls");
    while (true) {
        menuSecundario(objetoOperaciones);
        _getch();
    }

    system("pause>0");
    delete objetoOperaciones;
    return 0;
};