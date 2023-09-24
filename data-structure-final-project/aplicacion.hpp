#ifndef __APLICACION_HPP__
#define __APLICACION_HPP__

#include <time.h>
#include <iostream>
using namespace std;

class Aplicacion {
    string nombre, descripcion, comentario;
    int calificacion, numeroDescargas, identificador;
    bool disponibleParaComprar;
public:
    Aplicacion(string nombre, string descripcion, bool disponibleParaComprar) {
        this->nombre = nombre;
        this->descripcion = descripcion;
        this->disponibleParaComprar = disponibleParaComprar;
        this->identificador = 1 + rand() % 10;
        this->comentario = "Sin comentarios";
        this->calificacion = 0;
    }
    ~Aplicacion() {};

    string getNombre() { return nombre; };
    string getDescripcion() { return descripcion; };
    string getComentarios() { return comentario; };
    int getCalificacion() { return calificacion; };
    int getNumeroDescargas() { return numeroDescargas; };
    int getIdentificador() { return identificador; };
    bool getAplicacionDisponibleComprar() { return disponibleParaComprar; };

    void setComentario(string comentarios) { this->comentario = comentarios; };
    void setCalificacion(int calificacion) { this->calificacion = calificacion; };
    void setAplicacionDisponibleComprar(bool valor) { this->disponibleParaComprar = valor; };
};

#endif