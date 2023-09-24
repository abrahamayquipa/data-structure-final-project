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

    void insertarInicio(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);  // Cambiado a Nodo<T>*
        if (!longitud) {
            cabeza = cola = nuevoNodo;
        }
        else {
            nuevoNodo->siguiente = cabeza;
            cabeza->anterior = nuevoNodo;
            cabeza = nuevoNodo;
        }
        ++longitud;
    }

    void insertarFinal(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);
        if (longitud == 0) {
            this->cabeza = this->cola = nuevoNodo;
            longitud = 1;
            return;
        }
        this->cola->siguiente = nuevoNodo;
        nuevoNodo->anterior = this->cola;
        this->cola = this->cola->siguiente;
        longitud++;
    }

    void insertarEnPosicion(T dato, int posicion) {
        if (posicion < 0 || posicion > longitud) throw "Invalid position";
        if (posicion == 0) { insertarInicio(dato); return; }
        if (posicion == longitud) { insertarFinal(dato); return; }
        Nodo* auxiliar = this->cabeza;
        Nodo* nuevoNodo = new Nodo(dato);
        for (int i = 0; i < posicion - 1; ++i) auxiliar = auxiliar->siguiente;
        // Enlazar el nodo a insertar con el nodo en la posición pos (aux->next)
        nuevoNodo->siguiente = auxiliar->siguiente;
        auxiliar->siguiente->anterior = nuevoNodo;
        // Enlazamos el nodo a insertar con el nodo anterior al de la posición pos (aux)
        auxiliar->siguiente = nuevoNodo;
        nuevoNodo->anterior = auxiliar;

        ++this->longitud;
    }

    void eliminarInicio() {
        if (this->longitud == 0) throw "Cannot erase in empty list";
        if (this->longitud == 1) {
            delete cabeza;
            cabeza = cola = nullptr;
            longitud = 0;
            return;
        }
        cabeza = cabeza->siguiente;
        cabeza->anterior->siguiente = nullptr;
        delete cabeza->anterior;
        cabeza->anterior = nullptr;
        --longitud;
    }

    void eliminarFinal() {
        if (this->longitud == 0) throw "Cannot erase in empty list";
        if (this->longitud == 1) {
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

    void eliminaPosicion(int posicion) {
        if (posicion < 0 || posicion >= longitud) throw "Cannot erase out of bounds";
        if (posicion == 0) {
            eliminarInicio();
            return;
        }
        if (posicion == longitud - 1) {
            eliminarFinal();
            return;
        }
        Nodo<T>* auxiliar = cabeza;
        for (unsigned int i = 0; i < posicion - 1; ++i) auxiliar = auxiliar->siguiente;
        Nodo<T>* toErase = auxiliar->siguiente;

        auxiliar->siguiente = auxiliar->siguiente->siguiente;
        auxiliar->siguiente->anterior = auxiliar->siguiente->anterior->anterior;

        toErase->siguiente = toErase->anterior = nullptr;

        delete toErase;
        --longitud;
    }

    bool estaVacia() {
        return this->longitud == 0;
    }

    size_t tamano() {
        return this->longitud;
    }

    T obtenerPosicion(int posicion) {
        if (posicion >= 0 && posicion < longitud) {
            Nodo<T>* auxiliar = this->cabeza;
            for (int i = 0; i < posicion; i++) auxiliar = auxiliar->siguiente;
            return auxiliar->dato;
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