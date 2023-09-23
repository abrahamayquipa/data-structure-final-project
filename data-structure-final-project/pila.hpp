#ifndef __PILA_H__
#define __PILA_H__
#include "nodo.hpp"
using namespace std;

template<class T>
class Pila {
private:
	Nodo<T>* tope;
public:
	Pila() { tope = NULL; };

	void push(T v) {
		if (estaVacia()) tope = new Nodo<T>(v);
		else tope = new Nodo<T>(v, tope);
	}

	T pop() {
		if (estaVacia()) return NULL;
		else {
			T elemento = (T)(tope->dato);
			Nodo* aux = tope;
			tope = (Nodo<T>*) tope->siguiente;
			delete aux;
			return elemento;
		}
	}

	bool estaVacia() {
		return (tope == NULL);
	}
};

#endif