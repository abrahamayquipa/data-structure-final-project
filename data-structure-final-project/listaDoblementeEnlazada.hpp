#ifndef __LISTA_DOBLEMENTE_ENLAZADA_HPP__
#define __LISTA_DOBLEMENTE_ENLAZADA_HPP__
#include <cstdint>
#include <functional>

template<class T>
class ListaDoblementeEnlazada {
private:
    struct Nodo {
        T valor;
        Nodo* siguiente;
        Nodo* anterior;
        Nodo(T value) : valor(value), siguiente(nullptr), anterior(nullptr) {}
    };
    Nodo* nodoInicial;
    Nodo* nodoFinal;
    size_t longitud;
public:
    ListaDoblementeEnlazada() {
        this->nodoInicial = this->nodoFinal = nullptr;
        this->longitud = 0;
    }

    void insertarInicio(T valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (longitud == 0) {
            this->nodoInicial = this->nodoFinal = nuevoNodo;
            this->longitud = 1;
            return;
        }
        nuevoNodo->siguiente = this->nodoInicial;
        this->nodoInicial->anterior = nuevoNodo;
        this->nodoInicial = this->nodoInicial->anterior;
        ++this->longitud;
    }

    void insertarFinal(T valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (longitud == 0) {
            this->nodoInicial = this->nodoFinal = nuevoNodo;
            longitud = 1;
            return;
        }
        this->nodoFinal->siguiente = nuevoNodo;
        nuevoNodo->anterior = this->nodoFinal;
        this->nodoFinal = this->nodoFinal->siguiente;
        longitud++;
    }

    void insertarEnPosicion(T valor, int posicion) {
        if (posicion < 0 || posicion > longitud) throw "Invalid position";
        if (posicion == 0) { insertarInicio(valor); return; }
        if (posicion == longitud) { insertarFinal(valor); return; }
        Nodo* auxiliar = this->nodoInicial;
        Nodo* nuevoNodo = new Nodo(valor);
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
            delete nodoInicial;
            nodoInicial = nodoFinal = nullptr;
            longitud = 0;
            return;
        }
        nodoInicial = nodoInicial->siguiente;
        nodoInicial->anterior->siguiente = nullptr;
        delete nodoInicial->anterior;
        nodoInicial->anterior = nullptr;
        --longitud;
    }

    void eliminarFinal() {
        if (this->longitud == 0) throw "Cannot erase in empty list";
        if (this->longitud == 1) {
            delete nodoInicial;
            nodoInicial = nodoFinal = nullptr;
            longitud = 0;
            return;
        }
        nodoFinal = nodoFinal->anterior;
        nodoFinal->siguiente->anterior = nullptr;
        delete nodoFinal->siguiente;
        nodoFinal->siguiente = nullptr;
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
        Nodo* auxiliar = nodoInicial;
        for (unsigned int i = 0; i < posicion - 1; ++i) auxiliar = auxiliar->siguiente;
        Nodo* toErase = auxiliar->siguiente;

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
            Nodo* auxiliar = this->nodoInicial;
            for (int i = 0; i < posicion; i++) auxiliar = auxiliar->siguiente;
            return auxiliar->valor;
        }
        else throw "Posición fuera de rango";
    }

    //void shellSort(int a[], int n) {
    //    int i, j, k, intervalo = n/2;
    //    int temp;
    //    while (intervalo > 0) {
    //        for (int i = intervalo; i <= n; i++) {
    //            j = i - intervalo;
    //            while (j >= 0) {
    //                k = j + intervalo;
    //                if (a[j] <= a[k]) j = -1;
    //                else {
    //                    temp = a[j];
    //                    a[j] = a[k];
    //                    a[k] = temp;
    //                    j -= intervalo;
    //                }
    //            }
    //        }
    //        intervalo = intervalo / 2;
    //    }
    //}



    //void shellSort() {
    //    int intervalo = longitud / 2;
    //
    //    while (intervalo > 0) {
    //        Nodo* i = nodoInicial;
    //        for (int count = 0; count < intervalo; count++) i = i->siguiente;
    //
    //        while (i != nullptr) {
    //            T valorTemporal = i->valor;
    //            Nodo* j = i;
    //
    //            // Mover el nodo j hacia atrás por intervalo mientras sea mayor que valorTemporal
    //            int count = 0;
    //            while (j != nullptr && count < intervalo && j->anterior != nullptr && j->anterior->valor > valorTemporal) {
    //                j->valor = j->anterior->valor;
    //                j = j->anterior;
    //                count++;
    //            }
    //            // Asignar valorTemporal al nodo adecuado
    //            if (j != nullptr) j->valor = valorTemporal;
    //            if (i->siguiente != nullptr) i = i->siguiente;
    //            else i = nullptr;
    //        }
    //        intervalo /= 2;
    //    }
    //}

    //template <typename T>
    //void shellSort() {
    //    int intervalo = longitud / 2;
    //
    //    while (intervalo > 0) {
    //        Nodo<T>* i = nodoInicial;
    //        for (int count = 0; count < intervalo; count++) {
    //            if (i->siguiente == nullptr) break;
    //            i = i->siguiente;
    //        }
    //
    //        while (i != nullptr) {
    //            T valorTemporal = i->valor;
    //            Nodo<T>* j = i;
    //            Nodo<T>* j_gap = i;
    //
    //            for (int g = 0; g < intervalo && j_gap->anterior != nullptr; g++) {
    //                j_gap = j_gap->anterior;
    //            }
    //
    //            while (j_gap != nullptr && j_gap->valor > valorTemporal) {
    //                j->valor = j_gap->valor;
    //                j = j_gap;
    //
    //                for (int g = 0; g < intervalo && j_gap->anterior != nullptr; g++) {
    //                    j_gap = j_gap->anterior;
    //                }
    //            }
    //
    //            j->valor = valorTemporal;
    //            i = i->siguiente;
    //        }
    //        intervalo /= 2;
    //    }
    //}

};

#endif