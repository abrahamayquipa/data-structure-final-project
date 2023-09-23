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
public:
	Cola() {
		this->inicio = NULL;
		this->fin = NULL;
	}

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
		return dato;
	}

	bool esVacia() {
		return (inicio == NULL);
	}

};

#endif