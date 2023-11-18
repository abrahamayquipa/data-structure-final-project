#ifndef __ARBOLAVL_HPP__
#define __ARBOLAVL_HPP__

#include "nodo.hpp"

template<class T>
class ArbolAVL {
private:
	Nodo<T>* raiz;

	void procesar(T elemento) {
		cout << "\t\t\t" << elemento << endl;
	};

	//Operaciones privadas
	int _altura(Nodo<T>* nodo) {
		if (nodo == nullptr) return 0;
		return nodo->altura;
	}

	void _rotarDerecha(Nodo<T>*& nodo) {
		Nodo<T>* p = nodo->nodoIzquierdo;
		nodo->nodoIzquierdo = p->nodoDerecho;
		p->nodoDerecho = nodo;
		// Actualizamos la altura
		nodo = p;
	}

	void _rotarIzquierda(Nodo<T>*& nodo) {
		Nodo<T>* p = nodo->nodoDerecho;
		nodo->nodoDerecho = p->nodoIzquierdo;
		p->nodoIzquierdo = nodo;
		// Actualizamos la altura

		nodo = p;
	}
	void _balanceo(Nodo<T>*& nodo) {
		int hizq = _altura(nodo->nodoIzquierdo);
		int hder = _altura(nodo->nodoDerecho);
		int fb = hder - hizq;

		if (fb > 1) {
			// Rotar a la izqquierda
			int hhizq = _altura(nodo->nodoDerecho->nodoIzquierdo);
			int hhder = _altura(nodo->nodoDerecho->nodoDerecho);
			if (hhizq > hhder) {
				// Verificar si aplica doble rotación
				_rotarDerecha(nodo->nodoDerecho);
			}
			_rotarIzquierda(nodo);
		}
		if (fb < -1) {
			// Rotar a la derecha
			int hhizq = _altura(nodo->nodoIzquierdo->nodoIzquierdo);
			int hhder = _altura(nodo->nodoIzquierdo->nodoDerecho);
			if (hhizq < hhder) {
				//verificar si aplica doble rotación 
				_rotarIzquierda(nodo->nodoIzquierdo);
			}
			_rotarDerecha(nodo);
		}
		// Actualizar la altura del nodo raiz
		hizq = _altura(nodo->nodoIzquierdo);
		hder = _altura(nodo->nodoDerecho);
		nodo->altura = 1 + ((hizq > hder) ? hizq : hder);
	}

	bool _insertar(Nodo<T>*& nodo, T e) {
		if (nodo == nullptr) {
			// Nuevo elemento
			nodo = new Nodo<T>();
			nodo->elemento = e;
			return true;
		}
		else if (e == nodo->elemento)
			return false;
		else if (e < nodo->elemento) {
			_insertar(nodo->nodoIzquierdo, e);
		}
		else if (e > nodo->elemento) {
			_insertar(nodo->nodoDerecho, e);
		}
		_balanceo(nodo);
		return true;
	}

	void _inOrden(Nodo<T>* nodo) {
		if (nodo == nullptr) return;
		_inOrden(nodo->nodoIzquierdo);
		procesar(nodo->elemento);
		_inOrden(nodo->nodoDerecho);
	}

	void _inOrdenH(Nodo<T>* nodo) {
		if (nodo == nullptr) return;
		_inOrdenH(nodo->nodoIzquierdo);
		procesar(nodo->altura);
		_inOrdenH(nodo->nodoDerecho);
	}

	int _cantidad(Nodo<T>* nodo) {
		if (nodo == nullptr) return 0;
		return 1 + _cantidad(nodo->nodoIzquierdo) + _cantidad(nodo->nodoDerecho);
	}

	bool _estaVacio(Nodo<T>* nodo) {
		return nodo == nullptr;
	}

public:
	ArbolAVL() {
		this->raiz = nullptr;
	}

	bool Insertar(T e) { return _insertar(raiz, e); }
	void inOrden() { _inOrden(raiz); }
	void inOrdenH() { _inOrdenH(raiz); }
	int cantidad() { return _cantidad(raiz); }
	bool estaVacio() { return _estaVacio(raiz); }
};

#endif