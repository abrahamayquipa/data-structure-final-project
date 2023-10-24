#ifndef __PILA_HPP__
#define __PILA_HPP__
#include "nodo.hpp"
using namespace std;

/*
* Fuente 1: parte del codigo subido al aula virtual - semana 5
* https://aulavirtual.upc.edu.pe/ultra/courses/_390567_1/cl/outline
*/
template<class T>
class Pila {
private:
    Nodo<T>* tope;
    size_t longitud;
public:
    Pila() : tope(NULL), longitud(0) {}

    void insertar(T valor) {
        auto estaVacia = [this]() -> bool {
            return tope == nullptr;
        };

        auto insertarEnPilaVacia = [this, &valor]() {
            tope = new Nodo<T>(valor);
        };

        auto insertarEnPilaNoVacia = [this, &valor]() {
            tope = new Nodo<T>(valor, tope);
        };

        if (estaVacia()) insertarEnPilaVacia();
        else insertarEnPilaNoVacia();
        longitud++;
    }

    bool estaVacia() { return this->longitud == 0; }
    size_t getLongitud() { return longitud; }

    Nodo<T>* getNodoEnPosicion(int posicion) {
        if (posicion < 0) {
            throw "Posición inválida";
        }
        Nodo<T>* nuevoNodo = tope;
        int index = 0;
        while (nuevoNodo != NULL && index < posicion) {
            nuevoNodo = nuevoNodo->siguiente;
            index++;
        }
        if (nuevoNodo == NULL) {
            throw "Posición fuera de rango";
        }
        return nuevoNodo;
    }
};

#endif