#ifndef __ARBOL_BINARIO_HPP__
#define __ARBOL_BINARIO_HPP__

#include <functional>
using namespace std;

template<class T>
class Nodo {
public:
	T elemento;
	Nodo* nodoIzquierdo;
	Nodo* nodoDerecho;
};

template<class T>
class ArbolBinario {
	typedef function<int(T, T)> Comp;
	void(*procesar)(T);
	Nodo<T>* raiz;
	Comp comparar;
private:
	bool _buscar(Nodo<T>* nodo, T elemento) {
		if (nodo == nullptr) return false;
		else {
			int r = comparar(nodo->elemento, elemento);
			if (r == 0)return true;
			else if (r < 0) {
				return _buscar(nodo->nodoDerecho, elemento);
			}
			else {
				return _buscar(nodo->nodoIzquierdo, elemento);
			}
		}
	}

	bool _insertar(Nodo<T>*& nodo, T elemento) {
		if (nodo == nullptr) {
			nodo = new Nodo<T>();
			nodo->elemento = elemento;
			return true;
		}
		else {
			int r = comparar(nodo->elemento, elemento);
			if (r == 0) return false; //no se acepta nodos con elemento igual
			else if (r < 0) return _insertar(nodo->nodoDerecho, elemento);
			else return _insertar(nodo->nodoIzquierdo, elemento);
		}
	}

	int _cantidad(Nodo<T>* nodo) {
		if (nodo == nullptr) return 0;
		else {
			int cantidadLadoIzquierdo, cantidadLadoDerecho;
			cantidadLadoIzquierdo = _cantidad(nodo->nodoIzquierdo);
			cantidadLadoDerecho = _cantidad(nodo->nodoDerecho);
			return 1 + cantidadLadoIzquierdo + cantidadLadoDerecho;
		}
	}

	int _altura(Nodo<T>* nodo) {
		if (nodo == nullptr) return 0;
		else {
			int alturaLadoIzquierdo, alturaLadoDerecho;
			alturaLadoIzquierdo = 1 + _altura(nodo->nodoIzquierdo);
			alturaLadoDerecho = 1 + _altura(nodo->nodoDerecho);
			return alturaLadoIzquierdo > alturaLadoDerecho ? alturaLadoIzquierdo : alturaLadoDerecho;
		}
	}

	void _enOrden(Nodo<T>* nodo) {
		if (nodo == nullptr) return;
		_enOrden(nodo->nodoIzquierdo);
		procesar(nodo->elemento);
		_enOrden(nodo->nodoDerecho);
	}

	void _preOrden(Nodo<T>* nodo) {
		if (nodo == nullptr) return;
		procesar(nodo->elemento);
		_preOrden(nodo->nodoIzquierdo);
		_preOrden(nodo->nodoDerecho);
	}

	void _postOrden(Nodo<T>* nodo) {
		if (nodo == nullptr)return;
		_postOrden(nodo->nodoIzquierdo);
		_postOrden(nodo->nodoDerecho);
		procesar(nodo->elemento);
	}
public:
	ArbolBinario(void(*nuevoProcesar)(T)) {
		this->procesar = nuevoProcesar;
		this->comparar = [](T a, T b)->int { return a - b; };
		this->raiz = nullptr;
	}

	bool buscar(T e) { return _buscar(raiz, e); }

	int busquedaBinaria(const vector<T>& lista, const T elemenetoBuscado) {
		int noEncontrado = -1;
		int low = 0;
		int high = lista.size() - 1;
		int mid;
		while (low < high) {
			mid = (low + high) / 2;
			if (lista[mid] < elemenetoBuscado) low = mid + 1;
			else high = mid;
		}
		return (low == high) && lista[low] == elemenetoBuscado ? low : noEncontrado;
	}

	bool insertar(T elemento) { return _insertar(raiz, elemento); }
	bool vacio() { return raiz == nullptr; }
	int cantidad() { return _cantidad(raiz); }
	int altura() { return _altura(raiz); }

	void ordenamientoEnOrden() { _enOrden(raiz); }
	void ordenamientoPreOrden() { _preOrden(raiz); }
	void ordenamientoPostOrden() { _postOrden(raiz); }
};

#endif