#ifndef __LISTA_DOBLEMENTE_ENLAZADA_HPP__
#define __LISTA_DOBLEMENTE_ENLAZADA_HPP__
#include "nodo.hpp"
#include "operaciones.hpp"
#include <cstdint>
#include <functional>

template<class T>
class ListaDoblementeEnlazada {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;
    size_t longitud;
public:
    ListaDoblementeEnlazada() : cabeza(nullptr), cola(nullptr), longitud(0) {}

    void insertarFinal(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);
        if (longitud == 0) {
            cabeza = cola = nuevoNodo;
            longitud = 1;
            return;
        }
        cola->siguiente = nuevoNodo;
        nuevoNodo->anterior = cola;
        cola = cola->siguiente;
        longitud++;
    }

    void eliminarFinal() {
        if (longitud == 0) throw "Cannot erase in empty list";
        if (longitud == 1) {
            delete cabeza;
            cabeza = cola = nullptr;
            longitud = 0;
            return;
        }
        cola = cola->anterior;
        cola->siguiente->anterior = nullptr;
        delete cola->siguiente;
        cola->siguiente = nullptr;
        --longitud;
    }

    bool estaVacia() {
        return longitud == 0;
    }

    size_t tamano() {
        return longitud;
    }

    Nodo<T>* obtenerPosicion(int posicion) {
        if (posicion >= 0 && posicion < longitud) {
            Nodo<T>* auxiliar = cabeza;
            for (int i = 0; i < posicion; i++) auxiliar = auxiliar->siguiente;
            return auxiliar;
        }
        else throw "Posición fuera de rango";
    }

    void ordenamientoBurbuja(int posicion) {
        if (posicion < 0 || posicion >= longitud - 1) throw "Posición fuera de rango";
        Nodo<T>* nodo1 = cabeza;
        for (int i = 0; i < posicion; i++) nodo1 = nodo1->siguiente;
        Nodo<T>* nodo2 = nodo1->siguiente;

        T temp = nodo1->dato;
        nodo1->dato = nodo2->dato;
        nodo2->dato = temp;
    }
};

#endif