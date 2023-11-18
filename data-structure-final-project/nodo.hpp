#ifndef __NODO_HPP__
#define __NODO_HPP__

template<class T>
class Nodo {
public:
	T valor;
	Nodo<T>* anterior;
	Nodo<T>* siguiente;

	T elemento;
	Nodo* nodoIzquierdo;
	Nodo* nodoDerecho;
	int altura;

	Nodo() {}
	Nodo(T valor, Nodo<T>* anterior = NULL, Nodo<T>* siguiente = NULL) {
		this->valor = valor;
		this->anterior = anterior;
		this->siguiente = siguiente;
		this->nodoDerecho = nullptr;
		this->nodoIzquierdo = nullptr;
		this->altura = 0;
	}
};

#endif