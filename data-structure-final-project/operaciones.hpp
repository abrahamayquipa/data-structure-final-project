#ifndef __OPERACIONES_HPP__
#define __OPERACIONES_HPP__

#include "aplicacion.hpp"
#include "listaEnlazada.hpp"
#include "listaDoblementeEnlazada.hpp"
#include "menu.hpp"
#include <iostream>
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

	int menuInterno() {
		int opcion = 0;
		cout << endl;
		cout << "OPCIONES EXTRAS:" << endl;
		cout << "1. Instalar aplicacion" << endl;
		cout << "2. Desinstalar aplicacion" << endl;
		cout << "3. Comprar aplicacion" << endl;
		cout << "4. Calificar aplicacion" << endl;
		cout << "5. Comentar aplicacion" << endl;
		cout << "6. Ver informacion de aplicacion" << endl;
		cout << "7. Denunciar aplicacion" << endl;
		cout << "Elegir opcion: "; cin >> opcion;
		return opcion;
	}

	void menuInternoOpciones(int opcion) {
		system("cls");
		switch (opcion) {
		case 1:
			cout << endl;
			cout << "APLICACION INSTALADA...";
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;
		}
	}

	void buscarAplicacion(string nombre) {
		if (objetoListaDoblementeEnlazada.estaVacia()) cout << "La lista de aplicaciones esta vacia";
		else {
			for (int i = 0; i < objetoListaDoblementeEnlazada.tamano(); i++) {
				if (objetoListaDoblementeEnlazada.obtenerPosicion(i).getNombre() == nombre) {
					cout << endl;
					cout << "DATOS ALUMNO " << i + 1 << ":" << endl;
					cout << "Nombre: " << objetoListaDoblementeEnlazada.obtenerPosicion(i).getNombre() << endl;
					cout << "Descripcion: " << objetoListaDoblementeEnlazada.obtenerPosicion(i).getDescripcion() << endl;
					if (objetoListaDoblementeEnlazada.obtenerPosicion(i).getEstaDisponibleComprar() == 0)
						cout << "Opcion de compra: No dispoible, unicamente descarga" << endl;
					else cout << "Opcion de compra: Dispoible a $0.99" << endl;
					int opcionMenuInterno = menuInterno();
					menuInternoOpciones(opcionMenuInterno);
				} else cout << "No se encontro la aplicacion, intentelo de nuevo";
			}
		}
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
		cout << "	0 - no disponible" << endl;
		cout << "	1 - disponible" << endl;
		cout << "Opcion: "; cin >> disponibleParaComprar;

		Aplicacion objetoAplicacion = Aplicacion(nombre, descripcion, disponibleParaComprar);
		objetoListaDoblementeEnlazada.insertarFinal(objetoAplicacion);
		cout << endl << "aplicacion guardada con exito...";
	}

	void mostrarAplicaciones() {
		if (objetoListaDoblementeEnlazada.estaVacia()) cout << "La lista de aplicaciones esta vacia";
		else {
			for (int i = 0; i < objetoListaDoblementeEnlazada.tamano(); i++) {
				cout << endl;
				cout << "DATOS ALUMNO " << i + 1 << ":" << endl;
				cout << "Nombre: " << objetoListaDoblementeEnlazada.obtenerPosicion(i).getNombre() << endl;
				cout << "Descripcion: " << objetoListaDoblementeEnlazada.obtenerPosicion(i).getDescripcion() << endl;
				if (objetoListaDoblementeEnlazada.obtenerPosicion(i).getEstaDisponibleComprar() == 0)
					cout << "Opcion de compra: No dispoible, unicamente descarga" << endl;
				else cout << "Opcion de compra: Dispoible a $0.99" << endl;
			}
		}
	}

	void ordenarInvesamente() {
		//objetoListaDoblementeEnlazada.shellSort();
	}
};

#endif