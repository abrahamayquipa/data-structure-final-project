#ifndef __PILA_H__
#define __PILA_H__
#include "nodo.hpp"
using namespace std;

template<class T>
class Pila {
private:
    Nodo<T>* tope;
    int longitud; // Agrega la variable longitud

public:
    Pila() : tope(NULL), longitud(0) {} // Inicializa longitud a 0

    void push(T v) {
        // Lambda para comprobar si la pila está vacía
        auto estaVacia = [this]() -> bool {
            return tope == nullptr;
            };

        // Lambda para añadir un elemento al tope de una pila vacía
        auto pushEnPilaVacia = [this, &v]() {
            tope = new Nodo<T>(v);
            };

        // Lambda para añadir un elemento al tope de una pila no vacía
        auto pushEnPilaNoVacia = [this, &v]() {
            tope = new Nodo<T>(v, tope);
            };

        if (estaVacia()) {
            pushEnPilaVacia();
        }
        else {
            pushEnPilaNoVacia();
        }

        longitud++;  // Incrementa la longitud al añadir un nodo
    }

    T pop() {
        if (estaVacia()) return NULL;
        else {
            T elemento = (T)(tope->dato);
            Nodo<T>* aux = tope;
            tope = (Nodo<T>*) tope->siguiente;
            delete aux;
            longitud--; // Decrementa longitud cuando eliminas un nodo
            return elemento;
        }
    }

    bool estaVacia() {
        return this->longitud == 0;
    }

    int getLongitud() const { // Método para obtener la longitud actual
        return longitud;
    }

    Nodo<T>* getNodeAtPosition(int pos) {
        if (pos < 0) {
            throw "Posición inválida";
        }
        Nodo<T>* temp = tope;
        int index = 0;
        while (temp != NULL && index < pos) {
            temp = temp->siguiente;
            index++;
        }
        if (temp == NULL) {
            throw "Posición fuera de rango";
        }
        return temp;  // Devuelve el puntero al nodo en lugar de temp->dato
    }
};

#endif