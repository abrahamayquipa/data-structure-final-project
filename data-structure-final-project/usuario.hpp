#ifndef __USUARIO_HPP__
#define __USUARIO_HPP__

#include <iostream>
using namespace std;

class Usuario {
private:
    int tipoUsuario;
public:
    Usuario(int tipoUsuario): tipoUsuario(tipoUsuario) {}
    ~Usuario() {}

    int getTipoUsuario() { return tipoUsuario; }
};

#endif 