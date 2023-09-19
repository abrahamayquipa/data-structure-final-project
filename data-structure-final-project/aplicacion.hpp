#ifndef APLICACION_H
#define APLICACION_H
#include <iostream>
using namespace std;

class Aplicacion {
    string nombre, descripcion, comentarios;
    int calificacion, numeroDescargas;
    bool estaDisponibleComprar;
public:
    Aplicacion() {
        this->nombre = "";
        this->descripcion = "";
        this->comentarios = "";
        this->calificacion = 0;
        this->numeroDescargas = 0;
    }
    Aplicacion(string nombre, string descripcion, bool estaDisponibleComprar) {
        this->nombre = nombre;
        this->descripcion = descripcion;
        this->estaDisponibleComprar = estaDisponibleComprar;
    }
    Aplicacion(string nombre, string descripcion, string comentarios, int calificacion, int numeroDescargas, bool estaDisponibleComprar) {
        this->nombre = nombre;
        this->descripcion = descripcion;
        this->comentarios = comentarios;
        this->calificacion = calificacion;
        this->numeroDescargas = numeroDescargas;
        this->estaDisponibleComprar = estaDisponibleComprar;
    }
    ~Aplicacion() {};

    string getNombre() { return nombre; };
    string getDescripcion() { return descripcion; };
    string getComentarios() { return comentarios; };
    int getCalificacion() { return calificacion; };
    int getNumeroDescargas() { return numeroDescargas; };
    bool getEstaDisponibleComprar() { return estaDisponibleComprar; };
};

#endif