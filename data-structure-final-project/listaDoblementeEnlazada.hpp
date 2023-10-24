#ifndef __LISTA_DOBLEMENTE_ENLAZADA_HPP__
#define __LISTA_DOBLEMENTE_ENLAZADA_HPP__

#include "nodo.hpp"
#include "operaciones.hpp"
#include <cstdint>
#include <functional>

/*
* Fuente 1: taller 3 de algoritmos y estructura de datos(no hay link de bibliografia)
*/
template<class T>
class ListaDoblementeEnlazada {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;
    size_t longitud;
public:
    ListaDoblementeEnlazada() : cabeza(nullptr), cola(nullptr), longitud(0) {}

    ~ListaDoblementeEnlazada() {
        if (cabeza != nullptr) {
            Nodo<T>* temporal = cabeza;
            Nodo<T>* siguiente;
            do {
                siguiente = temporal->siguiente;
                delete temporal;
                temporal = siguiente;
            } while (temporal != cabeza);
        }
    }

    void limpiarLista() {
        while (cabeza != nullptr) {
            Nodo<T>* temporal = cabeza;
            cabeza = cabeza->siguiente;
            delete temporal;
        }
        cola = nullptr;
        longitud = 0;
    }

    void insertarFinal(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);

        if (cabeza == nullptr) {
            cabeza = cola = nuevoNodo;
            cabeza->siguiente = cabeza;
            cabeza->anterior = cabeza;
        }
        else {                              
            nuevoNodo->anterior = cola;
            nuevoNodo->siguiente = cabeza;

            cola->siguiente = nuevoNodo;
            cabeza->anterior = nuevoNodo;
            cola = nuevoNodo;
        }
        longitud++;
    }

    bool estaVacia() { return longitud == 0; }
    size_t getLongitud() { return longitud; }


    Nodo<T>* getNodoEnPosicion(int posicion) {
        if (posicion >= 0 && posicion < longitud) {
            Nodo<T>* auxiliar = cabeza;
            for (int i = 0; i < posicion; i++) auxiliar = auxiliar->siguiente;
            return auxiliar;
        }
        else throw "Posici�n fuera de rango";
    }

    /*
    * Fuente 2: stackoverflow
    * https://stackoverflow.com/questions/46128144/trying-to-modify-a-bubble-sort-in-a-very-specific-way-for-an-array-of-random-dou
    */
    void ordenamientoBurbuja(int posicion) {
        if (posicion < 0 || posicion >= longitud - 1) throw "Posici�n fuera de rango";

        Nodo<T>* nodo1 = cabeza;
        for (int i = 0; i < posicion; i++) nodo1 = nodo1->siguiente;
        Nodo<T>* nodo2 = nodo1->siguiente;

        swap(nodo1->valor, nodo2->valor);
    }

    /*
    * Fuente 3: stackoverflow
    * https://stackoverflow.com/questions/60776300/quickselect-algorithm-for-singly-linked-list-c
    */
    Nodo<Aplicacion*>* particion(Nodo<Aplicacion*>* inicio, Nodo<Aplicacion*>* fin) {
        int pivote = fin->valor->getIdentificador();
        Nodo<Aplicacion*>* posicionMenor = inicio->anterior;

        for (Nodo<Aplicacion*>* i = inicio; i != fin; i = i->siguiente) {
            if (i->valor->getIdentificador() <= pivote) {
                posicionMenor = (posicionMenor == nullptr) ? cabeza : posicionMenor->siguiente;
                swap(posicionMenor->valor, i->valor);
            }
        }
        posicionMenor = (posicionMenor == nullptr) ? cabeza : posicionMenor->siguiente;
        swap(posicionMenor->valor, fin->valor);
        return posicionMenor;
    }

    Aplicacion* quickselect(Nodo<Aplicacion*>* inicio, Nodo<Aplicacion*>* fin, int posicionBuscada) {
        if (inicio == fin) return inicio->valor;

        Nodo<Aplicacion*>* nodoPivote = particion(inicio, fin);

        int longitudIzquierda = 0;
        Nodo<Aplicacion*>* temp = inicio;
        while (temp != nodoPivote) {
            longitudIzquierda++;
            temp = temp->siguiente;
        }

        if (longitudIzquierda == posicionBuscada) return nodoPivote->valor;
        if (longitudIzquierda > posicionBuscada) return quickselect(inicio, nodoPivote->anterior, posicionBuscada);
        return quickselect(nodoPivote->siguiente, fin, posicionBuscada - longitudIzquierda - 1);
    }

    Aplicacion* ordenamientoQuickselect(int posicionBuscada) {
        if (posicionBuscada < 0 || posicionBuscada >= longitud) throw "�ndice fuera de rango";
        return quickselect(cabeza, cola, posicionBuscada);
    }
};

#endif