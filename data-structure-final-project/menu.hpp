#include <iostream>
using namespace std;
#pragma once

int menuPrincipal() {
    int opcionPrincipal = 0;
    cout << "PLAY STORE" << endl;
    cout << "MENU:" << endl;
    cout << "1. Buscar aplicacion" << endl;
    cout << "2. Instalar aplicacion" << endl;
    cout << "3. Desinstalar aplicacion" << endl;
    cout << "4. Comprar aplicacion" << endl;
    cout << "5. Calificar aplicacion" << endl;
    cout << "6. Comentar aplicacion" << endl;
    cout << "7. Ver informacion de aplicacion" << endl;
    cout << "8. Denunciar aplicacion" << endl;
    cout << "9. Agregar aplicacion" << endl;
    cout << "Elegir opcion: ";
    cin >> opcionPrincipal;
    return opcionPrincipal;
}