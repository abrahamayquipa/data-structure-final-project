#ifndef __APLICACION_HPP__
#define __APLICACION_HPP__

#include <time.h>
#include <iostream>
using namespace std;

class Aplicacion {
    string nombre, descripcion, comentarios;
    int calificacion, numeroDescargas, identificador;
    bool aplicacionRegistrada;
public:
    Aplicacion() {
        this->nombre = "";
        this->descripcion = "";
        this->comentarios = "";
        this->calificacion = 0;
        this->numeroDescargas = 0;
        this->identificador = 0;
        this->aplicacionRegistrada = 0;
    }
    Aplicacion(string nombre, string descripcion, bool aplicacionRegistrada) {
        this->nombre = nombre;
        this->descripcion = descripcion;
        this->aplicacionRegistrada = aplicacionRegistrada;
        this->identificador = 1 + rand() % 10;
    }
    Aplicacion(string nombre, string descripcion, string comentarios, int calificacion, int numeroDescargas, bool aplicacionRegistrada) {
        this->nombre = nombre;
        this->descripcion = descripcion;
        this->comentarios = comentarios;
        this->calificacion = calificacion;
        this->numeroDescargas = numeroDescargas;
        this->aplicacionRegistrada = aplicacionRegistrada;
    }
    ~Aplicacion() {};

    string getNombre() { return nombre; };
    string getDescripcion() { return descripcion; };
    string getComentarios() { return comentarios; };
    int getCalificacion() { return calificacion; };
    int getNumeroDescargas() { return numeroDescargas; };
    int getIdentificador() { return identificador; };
    bool getAplicacionRegistrada() { return aplicacionRegistrada; };

    void setAplicacionRegistrada(bool valor) { this->aplicacionRegistrada = valor; };
};

#endif