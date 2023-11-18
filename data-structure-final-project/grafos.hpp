#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <vector>
using namespace std;

template<class T, T vacio = -1>
class Grafo {
private:
	class Arco {
	public:
		T info;
		int vertice; //indice del vertice de llegada
		Arco(int verticeLlegada) {
			info = vacio;
			vertice = verticeLlegada;
		}
	};
	class Vertice {
	public:
		T info;
		vector<Arco*>* listaAdyacencia; //Lista de adyacencia
		Vertice() {
			info = vacio;
			listaAdyacencia = new vector<Arco*>();
		}
	};
	//Lista de vértices
	vector<Vertice*>* vertices;

public:
	Grafo() {
		vertices = new vector<Vertice*>();
	}

	//Operaciones del Grafo
	int adicionarVertice(T info) {
		Vertice* objetoVertice = new Vertice();
		objetoVertice->info = info;
		vertices->push_back(objetoVertice);
		return vertices->size() - 1;
	}

	int cantidadVertices() {
		return vertices->size();
	}

	T obtenerVertice(int vertice) {
		return (vertices->at(vertice))->info;
	}
	void modificarVertice(int vertice, T info) {
		(vertices->at(vertice))->info = info;
	}
	//Operaciones del arco
	int adicionarArco(int vertice, int verticeLlegada) {
		Vertice* objetoVertice = vertices->at(vertice);
		//Crear el objeto ARCO
		Arco* objetoArco = new Arco(verticeLlegada);
		objetoVertice->listaAdyacencia->push_back(objetoArco);
		return objetoVertice->listaAdyacencia->size() - 1;
	}

	int cantidadArcos(int vertice) {
		return (vertices->at(vertice))->listaAdyacencia->size();
	}

	T obtenerArco(int vertice, int apos) {
		Vertice* objetoVertice = vertices->at(vertice);
		return (objetoVertice->listaAdyacencia->at(apos))->info;
	}

	void modificarArco(int vertice, int apos, T info) {
		Vertice* objetoVertice = vertices->at(vertice);
		(objetoVertice->listaAdyacencia->at(apos))->info = info;
	}

	int obtenerVerticeLlegada(int vertice, int apos) {
		Vertice* objetoVertice = vertices->at(vertice);
		return (objetoVertice->listaAdyacencia->at(apos))->vertice;
	}

	bool estaVacio() { return vertices->empty(); }
};

#endif