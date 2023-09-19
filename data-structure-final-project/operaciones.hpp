#include <iostream>
#include "aplicacion.hpp"
#include "listaEnlazada.hpp"
#include "listaDoblementeEnlazada.hpp"
#include <string>
using namespace std;

class Operaciones {
	string nombre, descripcion, comentarios;
	int calificacion, numeroDescargas;
	bool disponibleParaComprar;

	listaEnlazada<Aplicacion*, nullptr>* objetoListaEnlazada;
	ListaDoblemeneteEnlazadas<Aplicacion*> objetoListaDoblementeEnlazada;
public:
	Operaciones() {
		objetoListaEnlazada = new listaEnlazada<Aplicacion*, nullptr>();
	};
	~Operaciones() {
		delete objetoListaEnlazada; 
	};

	void insertarFinal() {
		cout << "AGREGAR APLICACION: " << endl;
		cout << "Nombre: ";
		cin.ignore();
		getline(cin, nombre);

		cout << "Descripcion: ";
		cin.ignore();
		getline(cin, descripcion);

		cout << "Opcion de compra(0 - no disponible, 1 - disponible): "; cin >> disponibleParaComprar;

		Aplicacion* objetoAplicacion = new Aplicacion(nombre, descripcion, disponibleParaComprar);
		objetoListaDoblementeEnlazada.insertarFinal(objetoAplicacion);
	}

	void mostrarContenidoLista() {
		cout << "LISTA:" << endl << endl;
		if (objetoListaDoblementeEnlazada.esVacia()) cout << "La lista esta vacia";
		else {
			for (int i = 0; i < objetoListaDoblementeEnlazada.longitud(); i++) {
				cout << "DATOS ALUMNO " << i + 1 << ":" << endl;
				//cout << "Nombre: " << objetoListaDoblementeEnlazada.obtenerPosicion(i)->getNombre() << endl;
			}
		}
	}
};