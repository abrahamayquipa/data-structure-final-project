#ifndef __COLA_H__
#define __COLA_H__
#include "nodo.hpp"
#include <iostream>

using namespace std;

template<class T>
class Cola {
private:
	Nodo<T>* inicio;
	Nodo<T>* fin;
	int longitud;  // Variable para mantener la longitud de la cola

public:
	Cola() : inicio(NULL), fin(NULL), longitud(0) {}  // Inicializamos longitud a 0

	void enqueue(T v) {
		Nodo<T>* nodo = new Nodo<T>(v);
		if (esVacia()) {
			inicio = nodo;
			fin = inicio;
		}
		else {
			fin->siguiente = nodo;
			fin = nodo;
		}
		longitud++;  // Incrementa la longitud cuando añades un nodo
		nodo = NULL;
	}

	T dequeue() {
		if (esVacia()) return NULL;
		T dato = inicio->dato;

		if (inicio == fin) {
			delete inicio;
			inicio = NULL;
			fin = NULL;
		}
		else {
			Nodo* aux = inicio;
			inicio = inicio->siguiente;
			delete aux;
		}
		longitud--;  // Decrementa la longitud cuando eliminas un nodo
		return dato;
	}

	bool esVacia() {
		return this->longitud == 0;
	}

	int getLongitud() const {  // Método para obtener la longitud actual
		return longitud;
	}

	Nodo<T>* getNodoEnPosicion(int pos) {
		if (pos < 0 || esVacia()) {
			throw "Posición inválida o cola vacía";  // puedes usar return NULL en lugar de lanzar una excepción si lo prefieres
		}

		int contador = 0;
		Nodo<T>* actual = inicio;

		while (actual != NULL) {
			if (contador == pos) {
				return actual;
			}
			contador++;
			actual = actual->siguiente;
		}

		throw "Posición fuera de rango";  // puedes usar return NULL en lugar de lanzar una excepción si lo prefieres
	}
};

#endif
