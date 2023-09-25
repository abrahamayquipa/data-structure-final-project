#ifndef __COLA_HPP__
#define __COLA_HPP__

#include "nodo.hpp"
#include <iostream>
using namespace std;

/*
* Fuente 1: parte del codigo subido al aula virtual - semana 5
* https://aulavirtual.upc.edu.pe/ultra/courses/_390567_1/cl/outline
* 
* Fuente 1: parte del codigo subido al aula virtual - semana 4
* https://aulavirtual.upc.edu.pe/ultra/courses/_390567_1/cl/outline
*/
template<class T>
class Cola {
private:
	Nodo<T>* inicio;
	Nodo<T>* fin;
	size_t longitud;

public:
	Cola() : inicio(NULL), fin(NULL), longitud(0) {}

	void enqueue(T valor) {
		Nodo<T>* nuevoNodo = new Nodo<T>(valor);
		if (estaVacia()) {
			inicio = nuevoNodo;
			fin = inicio;
		}
		else {
			fin->siguiente = nuevoNodo;
			fin = nuevoNodo;
		}
		longitud++;
		nuevoNodo = NULL;
	}

	T dequeue() {
		if (estaVacia()) return NULL;
		T dato = inicio->valor;

		if (inicio == fin) {
			delete inicio;
			inicio = NULL;
			fin = NULL;
		}
		else {
			Nodo<T>* aux = inicio;
			inicio = inicio->siguiente;
			delete aux;
		}
		longitud--;
		return dato;
	}

	bool estaVacia() { return this->longitud == 0; }
	size_t getLongitud() { return longitud; }

	Nodo<T>* getNodoEnPosicion(int posicion) {
		if (posicion < 0 || estaVacia()) throw "Posición inválida o cola vacía";

		int contador = 0;
		Nodo<T>* actual = inicio;

		while (actual != NULL) {
			if (contador == posicion) return actual;
			contador++;
			actual = actual->siguiente;
		}
		throw "Posición fuera de rango";
	}
};

#endif
