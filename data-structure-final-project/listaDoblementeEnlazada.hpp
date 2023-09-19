#ifndef __LISTA_H__
#define __LISTA_H__
#include "nodo.hpp"

template<class T>
class ListaDoblemeneteEnlazadas {
private:
	Nodo<T>* inicio;
	int lon;
public:
	ListaDoblemeneteEnlazadas() { 
		inicio = NULL;
		lon = 0;
	}
	~ListaDoblemeneteEnlazadas();
	void insertarFinal(T v);
	T obtenerPos(T pos);
	int  longitud();
	bool esVacia();
};

template<class T>
ListaDoblemeneteEnlazadas<T>::~ListaDoblemeneteEnlazadas() {
	Nodo<T>* temp;
	while (inicio != NULL) {
		temp = inicio;
		inicio = inicio->siguiente;
		delete temp;
		temp = NULL;
	}
	delete inicio;
	inicio = NULL;
}

template<class T>
void ListaDoblemeneteEnlazadas<T>::insertarFinal(T v) {
	Nodo<T>* nodo = new Nodo<T>(v);
	if (inicio == NULL) inicio = nodo;
	else {
		//posicionar en el ultimo nodo
		Nodo<T>* final = inicio->anterior;
		//recableo del nuevo final
		nodo->anterior = final;
		nodo->siguiente = inicio;
		//recabler el anterior finl
		final->siguiente = nodo;
		inicio->anterior = nodo;
	}
	lon++;
}

template<class T>
int ListaDoblemeneteEnlazadas<T>::longitud() {
	return lon;
}

template<class T>
bool ListaDoblemeneteEnlazadas<T>::esVacia() {
	return lon == 0;
}

template<class T>
T ListaDoblemeneteEnlazadas<T>::obtenerPos(T pos) {
	/* if (inicio == nullptr || posicion < 0) {
		return nullptr;
	}

	int indice = 0;
	Nodo<T>* nodoActual = inicio;

	while (indice < posicion) {
		nodoActual = nodoActual->siguiente;
		if (nodoActual == inicio) {
			return nullptr;
		}
		indice++;
	}
	return nodoActual;*/
}

#endif