#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
using namespace std;

class Usuario {
    string correoElectronico, contrasena;
public:
    Usuario(string correoElectronico, string contrasena) {
        this->correoElectronico = correoElectronico;
        this->contrasena = contrasena;
    }
    ~Usuario() {};

    string getCorreoElectronico() { return correoElectronico; };
    string getContrasena() { return contrasena; };
};

#endif