#pragma once
#include <functional>
using namespace std;
typedef unsigned int uint;

template <typename T, T NADA = 0>
class listaEnlazada {
    struct Nodo;
    typedef function<int(T, T)> Comp;

    Nodo* ini;
    uint lon;

    Comp comparar;
public:
    listaEnlazada() : ini(nullptr), lon(0), comparar([](T a, T b) {return a - b; }) {}
    listaEnlazada(Comp comparar) : ini(nullptr), lon(0), comparar(comparar) {}
    ~listaEnlazada();

    uint    longitud();

    bool    esVacia();

    void    agregaInicial(T elem);
    void    agregaPos(T elem, uint pos);
    void    agregaFinal(T elem);

    void    modificarInicial(T elem);
    void    modificarPos(T elem, uint pos);
    void    modificarFinal(T elem);

    void    eliminaInicial();
    void    eliminaPos(uint pos);
    void    eliminaFinal();

    T       obtenerInicial();
    T       obtenerPos(uint pos);
    T       obtenerFinal();

    T       buscar(T elem);
};

template <typename T, T NADA>
struct listaEnlazada<T, NADA>::Nodo {
    T       elem;
    Nodo* sig; // puntero apunta al siguiente nodo

    Nodo(T elem = NADA, Nodo* sig = nullptr) : elem(elem), sig(sig) {}
};

template <typename T, T NADA>
listaEnlazada<T, NADA>::~listaEnlazada() {
    Nodo* aux = ini;
    while (ini != nullptr) {
        aux = ini;
        ini = ini->sig;
        delete aux;
    }
}

template <typename T, T NADA>
uint listaEnlazada<T, NADA>::longitud() {
    return lon;
}

template <typename T, T NADA>
bool listaEnlazada<T, NADA>::esVacia() {
    return lon == 0;
}

template <typename T, T NADA>
void listaEnlazada<T, NADA>::agregaInicial(T elem) {
    Nodo* nuevo = new Nodo(elem, ini);
    if (nuevo != nullptr) {
        ini = nuevo;
        lon++;
    }
}

template <typename T, T NADA>
void listaEnlazada<T, NADA>::agregaPos(T elem, uint pos) {
    if (pos > lon) return;
    if (pos == 0) {
        agregaInicial(elem);
    }
    else {
        Nodo* aux = ini;
        for (int i = 1; i < pos; i++) {
            aux = aux->sig;
        }
        Nodo* nuevo = new Nodo(elem, aux->sig);
        if (nuevo != nullptr) {
            aux->sig = nuevo;
            lon++;
        }
    }
}
template <typename T, T NADA>
void listaEnlazada<T, NADA>::agregaFinal(T elem) {
    Nodo* nuevo = new Nodo(elem);
    if (!nuevo) return;
    if (!ini) ini = nuevo;
    else {
        Nodo* aux = ini;
        while (aux->sig) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
    lon++;
}

template <typename T, T NADA>
void listaEnlazada<T, NADA>::modificarInicial(T elem) {
    if (lon > 0) {
        ini->elem = elem;
    }
}
template <typename T, T NADA>
void listaEnlazada<T, NADA>::modificarPos(T elem, uint pos) {
    if (pos >= 0 && pos < lon) {
        Nodo* aux = ini;
        for (int i = 0; i < pos; i++) {
            aux = aux->sig;
        }
        aux->elem = elem;
    }
}
template <typename T, T NADA>
void listaEnlazada<T, NADA>::modificarFinal(T elem) {
    modificarPos(elem, lon - 1);
}

template <typename T, T NADA>
void listaEnlazada<T, NADA>::eliminaInicial() {
    if (lon > 0) {
        Nodo* aux = ini;
        ini = ini->sig;
        delete aux;
        lon--;
    }
}
template <typename T, T NADA>
void listaEnlazada<T, NADA>::eliminaPos(uint pos) {
    if (pos >= lon) return;
    if (pos == 0) eliminaInicial();
    else {
        Nodo* aux = ini;
        for (uint i = 1; i < pos; i++) {
            aux = aux->sig;
        }
        Nodo* nodoAEliminar = aux->sig;
        aux->sig = nodoAEliminar->sig;
        delete nodoAEliminar;
        lon--;
    }
}
template <typename T, T NADA>
void listaEnlazada<T, NADA>::eliminaFinal() {
    eliminaPos(lon - 1);
}

template <typename T, T NADA>
T listaEnlazada<T, NADA>::obtenerInicial() {
    return obtenerPos(0);
}
template <typename T, T NADA>
T listaEnlazada<T, NADA>::obtenerPos(uint pos) {
    if (pos >= 0 && pos < lon) {
        Nodo* aux = ini;
        for (int i = 0; i < pos; i++) {
            aux = aux->sig;
        }
        return aux->elem;
    }
    else {
        return NADA;
    }
}
template <typename T, T NADA>
T listaEnlazada<T, NADA>::obtenerFinal() {
    return obtenerPos(lon - 1);
}

template <typename T, T NADA>
T listaEnlazada<T, NADA>::buscar(T elem) {
    Nodo* aux = ini;
    while (aux != nullptr) {
        if (comparar(aux->elem, elem) == 0) {
            return aux->elem;
        }
        aux = aux->sig;
    }
    return NADA;
}