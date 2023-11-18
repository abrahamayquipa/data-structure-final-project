#ifndef __OPERACIONES_HPP__
#define __OPERACIONES_HPP__

#include "aplicacion.hpp"
#include "listaDoblementeEnlazada.hpp"
#include "pila.hpp"
#include "cola.hpp"
#include "hashEntidad.hpp"
#include "hashtable.hpp"
#include "arbolAVL.hpp"
#include "arbolBinario.hpp"
#include "grafos.hpp"
#include "menu.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Operaciones {
private:
	ListaDoblementeEnlazada<Aplicacion*>* objetoListaDoblementeEnlazada;
	Pila<Aplicacion*>* pila;
	Cola<Aplicacion*>* cola;
	Usuario* objetoUsuario;
	ArbolBinario<int>* objetoArbolBinario;
	ArbolAVL<string>* objetoArbolAVL;
	Grafo<int>* objetoGrafo;
	HashTable<int, string> objetoHashtable;
	int pos;
public:
	Operaciones() {
		objetoListaDoblementeEnlazada = new ListaDoblementeEnlazada<Aplicacion*>();
		pila = new Pila<Aplicacion*>();
		cola = new Cola<Aplicacion*>();
		objetoUsuario = new UsuarioRegular();
		objetoArbolBinario = new ArbolBinario<int>();
		objetoArbolAVL = new ArbolAVL<string>();
		objetoGrafo = new Grafo<int>();
		objetoHashtable;
	};
	~Operaciones() {
		delete objetoListaDoblementeEnlazada;
		delete pila;
		delete cola;
		delete objetoUsuario;
		delete objetoArbolBinario;
		delete objetoArbolAVL;
	};

	int menuInterno() {
		int opcion = 0;
		cout << endl;
		cout << "\t\t\tOPCIONES EXTRAS:" << endl;
		cout << "\t\t\t1. Instalar aplicacion" << endl;
		cout << "\t\t\t2. Desinstalar aplicacion" << endl;
		cout << "\t\t\t3. Calificar aplicacion" << endl;
		cout << "\t\t\t4. Comentar aplicacion" << endl;
		cout << "\t\t\tElegir opcion: "; cin >> opcion;
		return opcion;
	}

	void cambiarUsuario(int tipo) {
		delete objetoUsuario;

		switch (tipo) {
		case 1:
			objetoUsuario = new UsuarioRegular();
			break;
		case 2:
			objetoUsuario = new UsuarioDesarrollador();
			break;
		case 3:
			objetoUsuario = new UsuarioStaff();
			break;
		default:
			cout << "\t\t\tTipo de usuario no valido";
		}
	}

	void agregarAplicacion() {
		if (objetoUsuario->getTipoUsuario() == 2 || objetoUsuario->getTipoUsuario() == 3) {
			string nombre, descripcion;
			bool disponibleParaComprar;

			cout << "\t\t\tNombre: ";
			cin.ignore();
			getline(cin, nombre);

			cout << "\t\t\tDescripcion: ";
			cin.ignore();
			getline(cin, descripcion);

			cout << "\t\t\tOpcion de compra:" << endl;
			cout << "\t\t\t\t* 0 - aplicacion gratuita" << endl;
			cout << "\t\t\t\t* 1 - disponible para comprar por $0.99" << endl;
			cout << "\t\t\tOpcion: ";
			cin >> disponibleParaComprar;

			Aplicacion* objetoAplicacion = new Aplicacion(nombre, descripcion, disponibleParaComprar);
			objetoListaDoblementeEnlazada->insertarFinal(objetoAplicacion);
			cout << endl << "\t\t\taplicacion guardada con exito...";
		}
		else cout << "\t\t\tOpcion solo disponible para desarrolladores o staff de la app";
	}

	void setPosicion(int nuevaPosicion) {
		pos = nuevaPosicion;
	}
	
	void mostrarAplicacion(int i) {
		if (i >= objetoListaDoblementeEnlazada->getLongitud()) return;
		cout << endl;
		cout << "\t\t\tDATOS DE LA APLICACION " << i + 1 << ":" << endl;
		cout << "\t\t\tIdentificador: #" << objetoListaDoblementeEnlazada->getNodoEnPosicion(i)->valor->getIdentificador() << endl;
		cout << "\t\t\tNombre: " << objetoListaDoblementeEnlazada->getNodoEnPosicion(i)->valor->getNombre() << endl;
		cout << "\t\t\tDescripcion: " << objetoListaDoblementeEnlazada->getNodoEnPosicion(i)->valor->getDescripcion() << endl;

		if (objetoListaDoblementeEnlazada->getNodoEnPosicion(i)->valor->getAplicacionDisponibleComprar() == 0)
			cout << "\t\t\tOpcion de compra: No dispoible, unicamente descarga" << endl;
		else
			cout << "\t\t\tOpcion de compra: Dispoible a $0.99" << endl;

		cout << "\t\t\tComentario: " << objetoListaDoblementeEnlazada->getNodoEnPosicion(i)->valor->getComentarios() << endl;
		
		for (int j = 0; j < objetoGrafo->cantidadVertices(); j++) {
			if(objetoListaDoblementeEnlazada->getNodoEnPosicion(i)->valor->getCalificacion() != 0)
			cout << "\t\t\tCalificacion: " << objetoGrafo->obtenerVertice(j) << " estrellas" << endl;
			else
				cout << "\t\t\tCalificacion: " << objetoListaDoblementeEnlazada->getNodoEnPosicion(i)->valor->getCalificacion() << " estrellas" << endl;
		}
		mostrarAplicacion(i + 1);
	}

	void mostrarAplicaciones() {
		if (objetoListaDoblementeEnlazada->estaVacia()) {
			cout << "\t\t\tLa lista de aplicaciones esta vacia";
			return;
		}
		mostrarAplicacion(0);
	}

	void odernarAscendentemente() {
		for (int i = 0; i < objetoListaDoblementeEnlazada->getLongitud() - 1; i++) {
			for (int j = 0; j < objetoListaDoblementeEnlazada->getLongitud() - i - 1; j++) {
				if (objetoListaDoblementeEnlazada->getNodoEnPosicion(j)->valor->getIdentificador() >
					objetoListaDoblementeEnlazada->getNodoEnPosicion(j + 1)->valor->getIdentificador()) {

					objetoListaDoblementeEnlazada->ordenamientoBurbuja(j);
				}
			}
		}
		mostrarAplicaciones();
	}

	void buscarAplicacion(string nombre) {
		if (objetoListaDoblementeEnlazada->estaVacia()) {
			system("cls");
			cout << "\n\n\n\t\t\tLa lista de aplicaciones esta vacia";
		}
		else {
			bool aplicacionEncontrada = false;

			for (int i = 0; i < objetoListaDoblementeEnlazada->getLongitud(); i++) {
				Aplicacion* aplicacionActual = objetoListaDoblementeEnlazada->getNodoEnPosicion(i)->valor;

				if (aplicacionActual->getNombre() == nombre) {
					aplicacionEncontrada = true;

					cout << endl;
					cout << "\t\t\t*Coincidencias en la posicion " << i + 1 << "*" << endl;
					cout << "\t\t\tNombre: " << aplicacionActual->getNombre() << endl;
					cout << "\t\t\tDescripcion: " << aplicacionActual->getDescripcion() << endl;

					if (aplicacionActual->getAplicacionDisponibleComprar() == 0)
						cout << "\t\t\tOpcion de compra: No disponible, únicamente descarga" << endl;
					else
						cout << "\t\t\tOpcion de compra: Disponible a $0.99" << endl;

					int opcionMenuInterno = menuInterno();
					menuInternoOpciones(opcionMenuInterno, i);
				}
			}
			if (!aplicacionEncontrada) cout << "\t\t\tLa aplicacion no se encontro";
		}
	}

	void menuInternoOpciones(int opcion, int posicion) {
		system("cls");
		switch (opcion) {
		case 1:
		{
			string nombre = objetoListaDoblementeEnlazada->getNodoEnPosicion(posicion)->valor->getNombre();
			objetoHashtable.insertar(HashEntidad<int, string>(posicion, nombre));
			objetoArbolAVL->Insertar(objetoListaDoblementeEnlazada->getNodoEnPosicion(posicion)->valor->getNombre());
			cout << "\n\n\n\n\t\t\tAPLICACION INSTALADA...";
			break;
		}
		case 2:
		{
			if (!objetoHashtable.estaVacio()) {
				
				objetoHashtable.eliminar(posicion);
				cout << "\n\n\n\n\t\t\tAPLICACION DESINSTALADA...";
			}
			else cout << "\n\n\n\n\t\t\tNo puedes desinstalar una aplicacion que no instalaste antes" << endl;
			break;
		}
		case 3:
		{
			int calificacion;
			cout << "\n\n\n\n\t\t\tIngrese tu calificacion(1-5 estrellas): ";
			cin >> calificacion;
			// objetoListaDoblementeEnlazada->getNodoEnPosicion(posicion)->valor->setCalificacion(calificacion);
			for (int i = 0; i <= posicion; i++) {
				if (i == posicion) objetoGrafo->adicionarVertice(calificacion);
			};
			break;
		}
		case 4:
		{
			string comentario;
			cout << "\n\n\n\n\t\t\tIngrese tu comentario: ";
			cin.ignore();
			getline(cin, comentario);
			objetoListaDoblementeEnlazada->getNodoEnPosicion(posicion)->valor->setComentario(comentario);
			setPosicion(posicion);
			break;
		}
		case 5:
		{
			cout << "\n\n\n\n\t\t\tORDENAR ASCENDENTEMENTE:" << endl;
			if (objetoListaDoblementeEnlazada->estaVacia()) cout << "\t\t\tOrdenamiento imposible, la tieda no tiene aplicaciones";
			else {
				cout << "\t\t\tLISTA ORIGINAL:" << endl;
				mostrarAplicaciones();
				cout << endl;
				
				cout << "\t\t\tLISTA ORDENADA POR MERGESORT SEGUN LOS IDENTIFICADORES:" << endl;
				cout << "\t\t\t";

				vector<int> arreglo;

				if (objetoListaDoblementeEnlazada != nullptr) {
					for (int i = 0; i < objetoListaDoblementeEnlazada->getLongitud(); i++) {
						int valor = objetoListaDoblementeEnlazada->getNodoEnPosicion(i)->valor->getIdentificador();
						arreglo.push_back(valor);
					}
					objetoListaDoblementeEnlazada->mergeSort(arreglo, arreglo.size());
					for (int i = 0; i < objetoListaDoblementeEnlazada->getLongitud(); i++) {
						cout << arreglo.at(i) << " ";
					}
				}

				cout << "\n\n\t\t\tLISTA ASCENDENTE POR BURBURJA:";
				odernarAscendentemente();
				cout << endl;
			}
			break;
		}
		case 6:
		{
			cout << "\n\n\n\n\t\t\tAPLICACIONES INSTALADAS ACTUALMENTE:" << endl;
			if (objetoHashtable.estaVacio()) cout << "\t\t\tNo hay aplicaciones instaladas ahora mismo";
			else {
				cout << "\t\t\t";
				objetoHashtable.mostrar();
			}
			break;
		}
		case 7:
		{
			cout << "\n\n\n\n\t\t\tAPLICACIONES INSTALADAS ANTERIORMENTE:" << endl;
			if (objetoArbolAVL->estaVacio()) cout << "\t\t\tHistorial vacio";
			else objetoArbolAVL->inOrden();
			break;
		}
		case 8:
		{
			cout << "\n\n\n\n\t\t\tORDENAR MEDIANTE QUICKSELCT:" << endl;
			if (objetoListaDoblementeEnlazada->estaVacia())
				cout << "\t\t\tOrdenamiento imposible, la tieda no tiene aplicaciones";
			else {
				cout << "\t\t\tLISTA ORIGINAL:" << endl;
				mostrarAplicaciones();
				cout << endl;
				cout << "\t\t\tLISTA ORDENADA POR QUICKSELECT:" << endl;
				cout << "\t\t\tEl segundo elemento mas pequeño por QUICKSELECT es: " << objetoListaDoblementeEnlazada->ordenamientoQuickselect(1)->getIdentificador() << endl;
			}
			break;
		}
		case 9:
		{
			int tipo;
			cout << "\n\n\n\n\t\t\tCAMBIAR TIPO DE USUARIO:" << endl << endl;
			cout << "\t\t\tSeleccione tipo de usuario:" << endl;
			cout << "\t\t\t1. Regular" << endl;
			cout << "\t\t\t2. Desarrollador" << endl;
			cout << "\t\t\t3. Staff" << endl;
			cout << "\t\t\tOpcion: "; cin >> tipo;
			cambiarUsuario(tipo);
			break;
		}
		case 10:
		{
			cout << "\n\n\n\n\t\t\tDATASET GENERATOR: " << endl;

			if (objetoUsuario->getTipoUsuario() == 2 || objetoUsuario->getTipoUsuario() == 3) {
				int numero;
				cout << "\t\t\tNumero de datos de aplicaciones a generar: ";
				cin >> numero;

				const int maxNombres = 20;
				string listaNombres[maxNombres] = {
					"Facebook", "Instagram", "Twitter", "Snapchat", "LinkedIn",
					"WhatsApp", "Telegram", "Signal", "Skype", "Zoom",
					"Netflix", "Hulu", "Amazon Prime Video", "Disney+", "Apple TV+",
					"Spotify", "Apple Music", "Google Play Music", "SoundCloud", "Deezer",
				};

				string listaDescripciones[2] = { "Aplicacion de entretenimiento", "Red social" };
				string listaComentarios[5] = { "Muy buena aplicacion", "Aplicacion buena", "Estuvo el algo", "Mala aplicacion", "Pesima aplicacion" };

				Aplicacion* objetoAplicacion;

				vector<string> nombresUsados;

				for (int i = 0; i < min(numero, maxNombres); i++) {
					if (nombresUsados.size() == maxNombres) {
						cout << "\t\t\tNo hay suficientes nombres de aplicaciones unicas disponibles.";
						break;
					}

					string nombre;
					do {
						nombre = listaNombres[rand() % maxNombres];
					} while (find(nombresUsados.begin(), nombresUsados.end(), nombre) != nombresUsados.end());

					nombresUsados.push_back(nombre);

					objetoAplicacion = new Aplicacion(nombre, listaDescripciones[rand() % 2], rand() % 2, listaComentarios[rand() % 5], rand() % 6);
					objetoListaDoblementeEnlazada->insertarFinal(objetoAplicacion);
				}
			}
			else {
				cout << "\t\t\tOpcion solo disponible para desarrolladores o staff de la app";
			}
		}
		};
	}
};

#endif