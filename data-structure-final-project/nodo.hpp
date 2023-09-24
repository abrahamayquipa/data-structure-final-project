#ifndef __NODO_HPP__
#define __NODO_HPP__

template<class T>
class Nodo {
public:
	T dato;
	Nodo<T>* anterior;
	Nodo<T>* siguiente;

	Nodo(T v, Nodo<T>* ant = NULL, Nodo<T>* sig = NULL) {
		dato = v;
		anterior = ant;
		siguiente = sig;
	}
};

#endif