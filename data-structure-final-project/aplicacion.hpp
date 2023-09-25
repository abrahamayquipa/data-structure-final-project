#ifndef __APLICACION_HPP__
#define __APLICACION_HPP__

#include <time.h>
#include <iostream>
using namespace std;

class Aplicacion {
    string tipoUsuario, nombre, descripcion, comentario;
    int calificacion, identificador;
    bool disponibleParaComprar;
public:
    Aplicacion(string nombre, string descripcion, bool disponibleParaComprar) {
        this->tipoUsuario = "regular";
        this->nombre = nombre;
        this->identificador = 1 + rand() % 10;
        this->descripcion = descripcion;
        this->disponibleParaComprar = disponibleParaComprar;
        this->comentario = "Sin comentarios";
        this->calificacion = 0;
    }
    ~Aplicacion() {};

    string getTipoUsario() { return tipoUsuario; };
    string getNombre() { return nombre; };
    int getIdentificador() { return identificador; };
    string getDescripcion() { return descripcion; };
    bool getAplicacionDisponibleComprar() { return disponibleParaComprar; };
    string getComentarios() { return comentario; };
    int getCalificacion() { return calificacion; };

    void setTipoUsuario(string tipoUsuario) { this->tipoUsuario = tipoUsuario; };
    void setComentario(string comentarios) { this->comentario = comentarios; };
    void setCalificacion(int calificacion) { this->calificacion = calificacion; };
    void setAplicacionDisponibleComprar(bool valor) { this->disponibleParaComprar = valor; };
};

#endif