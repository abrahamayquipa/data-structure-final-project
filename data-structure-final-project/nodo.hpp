#ifndef __NODO_HPP__
#define __NODO_HPP__

template<class T>
class Nodo {
public:
	T dato;
	Nodo<T>* siguiente;

	Nodo(T v, Nodo<T>* sig = NULL) {
		dato = v;
		siguiente = sig;
	}
};

#endif