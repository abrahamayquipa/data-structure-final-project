#ifndef __OPERACIONES_HPP__
#define __OPERACIONES_HPP__
#include "aplicacion.hpp"
#include "listaEnlazada.hpp"
#include "listaDoblementeEnlazada.hpp"
#include "pila.hpp"
#include "cola.hpp"
#include "menu.hpp"
#include <iostream>
#include <string>
using namespace std;

class Operaciones {
private:
	listaEnlazada<Aplicacion*, nullptr>* objetoListaEnlazada;
	ListaDoblementeEnlazada<Aplicacion*>* objetoListaDoblementeEnlazada;
	Pila<Aplicacion*>* pila;
	Cola<Aplicacion*>* cola;
public:
	Operaciones() {
		objetoListaEnlazada = new listaEnlazada<Aplicacion*, nullptr>();
		objetoListaDoblementeEnlazada = new ListaDoblementeEnlazada<Aplicacion*>();
		pila = new Pila<Aplicacion*>();
		cola = new Cola<Aplicacion*>();
	};
	~Operaciones() {
		delete objetoListaEnlazada;
		delete objetoListaDoblementeEnlazada;
		delete pila;
		delete cola;
	};

	int menuInterno() {
		int opcion = 0;
		cout << endl;
		cout << "OPCIONES EXTRAS:" << endl;
		cout << "1. Instalar aplicacion" << endl;
		cout << "2. Desinstalar aplicacion" << endl;
		cout << "3. Calificar aplicacion" << endl;
		cout << "4. Comentar aplicacion" << endl;
		cout << "Elegir opcion: "; cin >> opcion;
		return opcion;
	}

	void agregarAplicacion() {
		string nombre, descripcion;
		bool disponibleParaComprar;

		cout << "Nombre: ";
		cin.ignore();
		getline(cin, nombre);

		cout << "Descripcion: ";
		cin.ignore();
		getline(cin, descripcion);

		cout << "Opcion de compra:" << endl;
		cout << "* 0 - aplicacion gratuita" << endl;
		cout << "* 1 - disponible para comprar por $0.99" << endl;
		cout << "Opcion: "; cin >> disponibleParaComprar;

		Aplicacion* objetoAplicacion = new Aplicacion(nombre, descripcion, disponibleParaComprar);
		objetoListaDoblementeEnlazada->insertarFinal(objetoAplicacion);
		cout << endl << "aplicacion guardada con exito...";
	}

	void mostrarAplicacion(int i) {
		if (i >= objetoListaDoblementeEnlazada->tamano()) return;
			cout << endl;
			cout << "DATOS ALUMNO " << i + 1 << ":" << endl;
			cout << "Identificador: #" << objetoListaDoblementeEnlazada->obtenerPosicion(i)->dato->getIdentificador() << endl;
			cout << "Nombre: " << objetoListaDoblementeEnlazada->obtenerPosicion(i)->dato->getNombre() << endl;
			cout << "Descripcion: " << objetoListaDoblementeEnlazada->obtenerPosicion(i)->dato->getDescripcion() << endl;

			if (objetoListaDoblementeEnlazada->obtenerPosicion(i)->dato->getAplicacionDisponibleComprar() == 0) cout << "Opcion de compra: No dispoible, unicamente descarga" << endl;
			else cout << "Opcion de compra: Dispoible a $0.99" << endl;

			cout << "Comentario: " << objetoListaDoblementeEnlazada->obtenerPosicion(i)->dato->getComentarios() << endl;
			cout << "Calificacion: " << objetoListaDoblementeEnlazada->obtenerPosicion(i)->dato->getCalificacion() << " estrellas" << endl;
		mostrarAplicacion(i + 1);
	}

	void mostrarAplicaciones() {
		if (objetoListaDoblementeEnlazada->estaVacia()) {
			cout << "La lista de aplicaciones esta vacia";
			return;
		}
		mostrarAplicacion(0);
	}

	void invertirLista() {
		for (int i = 0; i < objetoListaDoblementeEnlazada->tamano() - 1; i++) {
			for (int j = 0; j < objetoListaDoblementeEnlazada->tamano() - i - 1; j++) {
				if (objetoListaDoblementeEnlazada->obtenerPosicion(j)->dato->getIdentificador() > objetoListaDoblementeEnlazada->obtenerPosicion(j + 1)->dato->getIdentificador()) {
					objetoListaDoblementeEnlazada->ordenamientoBurbuja(j);
				}
			}
		}
		mostrarAplicaciones();
	}

	void buscarAplicacion(string nombre) {
		if (objetoListaDoblementeEnlazada->estaVacia()) {
			system("cls");
			cout << "La lista de aplicaciones esta vacia"; 
		} else {
			for (int i = 0; i < objetoListaDoblementeEnlazada->tamano(); i++) {
				if (objetoListaDoblementeEnlazada->obtenerPosicion(i)->dato->getNombre() == nombre) {
					cout << endl;
					cout << "DATOS DE LA APLICACION " << i + 1 << ":" << endl;
					cout << "Nombre: " << objetoListaDoblementeEnlazada->obtenerPosicion(i)->dato->getNombre() << endl;
					cout << "Descripcion: " << objetoListaDoblementeEnlazada->obtenerPosicion(i)->dato->getDescripcion() << endl;
					if (objetoListaDoblementeEnlazada->obtenerPosicion(i)->dato->getAplicacionDisponibleComprar() == 0)
						cout << "Opcion de compra: No dispoible, unicamente descarga" << endl;
					else cout << "Opcion de compra: Dispoible a $0.99" << endl;
					int opcionMenuInterno = menuInterno();
					menuInternoOpciones(opcionMenuInterno, i);
				}
			}
		}
	}

	void menuInternoOpciones(int opcion, int posicion) {
		system("cls");
		switch (opcion) {
		case 1:
			cout << endl;
			pila->push(new Aplicacion(*objetoListaDoblementeEnlazada->obtenerPosicion(posicion)->dato));
			cola->enqueue(new Aplicacion(*objetoListaDoblementeEnlazada->obtenerPosicion(posicion)->dato));
			cout << "APLICACION INSTALADA...";
			break;
		case 2:
			cout << endl;
			pila->pop();
			cout << "APLICACION DESINSTALADA...";
			break;
		case 3:
		{
			int calificacion;
			cout << "Ingrese tu calificacion(1-5 estrellas): ";
			cin >> calificacion;
			objetoListaDoblementeEnlazada->obtenerPosicion(posicion)->dato->setCalificacion(calificacion);
			break;
		}
		case 4:
		{
			string comentario;
			cout << "Ingrese tu comentario: ";
			cin.ignore();
			getline(cin, comentario);
			objetoListaDoblementeEnlazada->obtenerPosicion(posicion)->dato->setComentario(comentario);
			break;
		}
		case 5:
			cout << "ORDENAR INVERSAMENTE:" << endl;
			if (objetoListaDoblementeEnlazada->estaVacia() == 0) {
				cout << "LISTA ORIGINAL:" << endl;
				mostrarAplicaciones();
				cout << endl;
				cout << "LISTA INVERSA:" << endl;
				invertirLista();
			}
			else cout << "No se puede ordenar las aplicaciones, puesto a que no hay ninguna registrada en la tienda";
			break;
		case 6:
			cout << "APLICACIONES INSTALADAS ACTUALMENTE:" << endl;
			if (pila->estaVacia() == 0) {
				for (int i = 0; i < pila->getLongitud(); i++)
					cout << "Aplicacion " << i + 1 << ": " << pila->getNodeAtPosition(i)->dato->getNombre() << endl;
			}
			else cout << "No hay aplicaciones instaladas";
			break;
		case 7:
			cout << "APLICACIONES INSTALADAS ACTUALMENTE:" << endl;
			if (cola->esVacia() == 0) {
				for (int i = 0; i < cola->getLongitud(); i++)
					cout << "Aplicacion " << i + 1 << ": " << pila->getNodeAtPosition(i)->dato->getNombre() << endl;
			}
			else cout << "No hay aplicaciones instaladas";
			break;
		};
	}
};

#endif