#include <iostream>
#include "aplicacion.hpp"
#include "listaEnlazada.hpp"
#include "listaDoblementeEnlazada.hpp"
#include <string>
using namespace std;

class Operaciones {
	listaEnlazada<Aplicacion*, nullptr>* objetoListaEnlazada;
	ListaDoblementeEnlazada<Aplicacion> objetoListaDoblementeEnlazada;
public:
	Operaciones() {
		objetoListaEnlazada = new listaEnlazada<Aplicacion*, nullptr>();

	};
	~Operaciones() {
		delete objetoListaEnlazada; 
	};

	void buscarElemento(string nombre) {
		if (objetoListaDoblementeEnlazada.isEmpty()) cout << "La lista de aplicaciones esta vacia";
		else {
			for (int i = 0; i < objetoListaDoblementeEnlazada.size(); i++) {
				if (objetoListaDoblementeEnlazada.obtenerNodoPos(i).getNombre() == nombre) {
					cout << endl;
					cout << "DATOS ALUMNO " << i + 1 << ":" << endl;
					cout << "Nombre: " << objetoListaDoblementeEnlazada.obtenerNodoPos(i).getNombre() << endl;
					cout << "Descripcion: " << objetoListaDoblementeEnlazada.obtenerNodoPos(i).getDescripcion() << endl;
					if (objetoListaDoblementeEnlazada.obtenerNodoPos(i).getEstaDisponibleComprar() == 0)
						cout << "Opcion de compra: No dispoible, unicamente descarga" << endl;
					else cout << "Opcion de compra: Dispoible a $0.99" << endl;
				} else cout << "No se encontro la aplicacion, intentelo de nuevo";
			}
		}
	}

	void insertarFinal() {
		string nombre, descripcion, comentarios;
		int calificacion, numeroDescargas;
		bool disponibleParaComprar;
		cout << "Nombre: ";
		cin.ignore();
		getline(cin, nombre);

		cout << "Descripcion: ";
		cin.ignore();
		getline(cin, descripcion);

		cout << "Opcion de compra:" << endl;
		cout << "	0 - no disponible" << endl;
		cout << "	1 - disponible" << endl;
		cout << "Opcion: "; cin >> disponibleParaComprar;

		Aplicacion objetoAplicacion = Aplicacion(nombre, descripcion, disponibleParaComprar);
		objetoListaDoblementeEnlazada.pushBack(objetoAplicacion);
		cout << endl << "aplicacion guardada con exito...";
	}

	void mostrarContenidoLista() {
		if (objetoListaDoblementeEnlazada.isEmpty()) cout << "La lista de aplicaciones esta vacia";
		else {
			for (int i = 0; i < objetoListaDoblementeEnlazada.size(); i++) {
				cout << endl;
				cout << "DATOS ALUMNO " << i + 1 << ":" << endl;
				cout << "Nombre: " << objetoListaDoblementeEnlazada.obtenerNodoPos(i).getNombre() << endl;
				cout << "Descripcion: " << objetoListaDoblementeEnlazada.obtenerNodoPos(i).getDescripcion() << endl;
				if (objetoListaDoblementeEnlazada.obtenerNodoPos(i).getEstaDisponibleComprar() == 0)
					cout << "Opcion de compra: No dispoible, unicamente descarga" << endl;
				else cout << "Opcion de compra: Dispoible a $0.99" << endl;
			}
		}
	}
};