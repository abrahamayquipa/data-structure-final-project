#ifndef __OPERACIONES_HPP__
#define __OPERACIONES_HPP__

#include "aplicacion.hpp"
#include "listaDoblementeEnlazada.hpp"
#include "pila.hpp"
#include "cola.hpp"
#include "hashEntidad.hpp"
#include "hashtable.hpp"
#include "menu.hpp"
#include <iostream>
#include <string>
using namespace std;

class Operaciones {
private:
	ListaDoblementeEnlazada<Aplicacion*>* objetoListaDoblementeEnlazada;
	Pila<Aplicacion*>* pila;
	Cola<Aplicacion*>* cola;
	Usuario* objetoUsuario;
public:
	Operaciones() {
		objetoListaDoblementeEnlazada = new ListaDoblementeEnlazada<Aplicacion*>();
		pila = new Pila<Aplicacion*>();
		cola = new Cola<Aplicacion*>();;
		objetoUsuario = new UsuarioRegular();
	};
	~Operaciones() {
		delete objetoListaDoblementeEnlazada;
		delete pila;
		delete cola;
		delete objetoUsuario;
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
		cout << "\t\t\tCalificacion: " << objetoListaDoblementeEnlazada->getNodoEnPosicion(i)->valor->getCalificacion() << " estrellas" << endl;
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
			cout << "\n\n\n\t\t\tLa lista de aplicaciones esta vacia o ingresaste mal el nombre";
		}
		else {
			for (int i = 0; i < objetoListaDoblementeEnlazada->getLongitud(); i++) {
				if (objetoListaDoblementeEnlazada->getNodoEnPosicion(i)->valor->getNombre() == nombre) {
					cout << endl; // 1
					cout << "\t\t\t*Coincidencias en la posicion " << i + 1 << "*" << endl;
					cout << "\t\t\tNombre: " << objetoListaDoblementeEnlazada->getNodoEnPosicion(i)->valor->getNombre() << endl;
					cout << "\t\t\tDescripcion: " << objetoListaDoblementeEnlazada->getNodoEnPosicion(i)->valor->getDescripcion() << endl;

					if (objetoListaDoblementeEnlazada->getNodoEnPosicion(i)->valor->getAplicacionDisponibleComprar() == 0)
						cout << "\t\t\tOpcion de compra: No dispoible, unicamente descarga" << endl;
					else cout << "\t\t\tOpcion de compra: Dispoible a $0.99" << endl;
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
		{
			cout << endl;
			cola->enqueue(new Aplicacion(*objetoListaDoblementeEnlazada->getNodoEnPosicion(posicion)->valor));
			pila->insertar(new Aplicacion(*objetoListaDoblementeEnlazada->getNodoEnPosicion(posicion)->valor));
			cout << "\n\n\n\n\t\t\tAPLICACION INSTALADA...";
			break;
		}
		case 2:
		{
			if (!cola->estaVacia()) {
				cout << endl;
				cola->dequeue();
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
			objetoListaDoblementeEnlazada->getNodoEnPosicion(posicion)->valor->setCalificacion(calificacion);
			break;
		}
		case 4:
		{
			string comentario;
			cout << "\n\n\n\n\t\t\tIngrese tu comentario: ";
			cin.ignore();
			getline(cin, comentario);
			objetoListaDoblementeEnlazada->getNodoEnPosicion(posicion)->valor->setComentario(comentario);
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
				cout << "\t\t\tLISTA ASCENDENTE:" << endl;
				odernarAscendentemente();
			}
			break;
		}
		case 6:
		{
			cout << "\n\n\n\n\t\t\tAPLICACIONES INSTALADAS ACTUALMENTE:" << endl;
			if (cola->estaVacia()) cout << "\t\t\tNo hay aplicaciones instaladas ahora mismo";
			else {
				for (int i = 0; i < cola->getLongitud(); i++)
					cout << "\t\t\tAplicacion " << i + 1 << ": " << cola->getNodoEnPosicion(i)->valor->getNombre() << endl;
			}
			break;
		}
		case 7:
		{
			//cout << "\n\n\n\n\t\t\tAPLICACIONES INSTALADAS ANTERIORMENTE:" << endl;
			//if (pila->estaVacia()) cout << "\t\t\tHistorial vacio";
			//else {
			//	for (int i = 0; i < pila->getLongitud(); i++)
			//		cout << "\t\t\tAplicacion " << i + 1 << ": " << pila->getNodoEnPosicion(i)->valor->getNombre() << endl;
			//}

			HashTable<int, string> objetoHashtable;
			objetoHashtable.insertar(HashEntidad<int, string>(0, "1000"));
			objetoHashtable.insertar(HashEntidad<int, string>(1, "1000"));
			objetoHashtable.insertar(HashEntidad<int, string>(2, "1000"));
			objetoHashtable.insertar(HashEntidad<int, string>(3, "1000"));
			objetoHashtable.insertar(HashEntidad<int, string>(4, "6"));
			objetoHashtable.insertar(HashEntidad<int, string>(5, "1000"));
			objetoHashtable.insertar(HashEntidad<int, string>(6, "1000"));
			objetoHashtable.insertar(HashEntidad<int, string>(7, "1000"));
			objetoHashtable.insertar(HashEntidad<int, string>(8, "25"));
			objetoHashtable.insertar(HashEntidad<int, string>(9, "1000"));
			objetoHashtable.insertar(HashEntidad<int, string>(10, "1000"));
			objetoHashtable.insertar(HashEntidad<int, string>(10, "1000"));
			objetoHashtable.insertar(HashEntidad<int, string>(12, "3"));
			objetoHashtable.insertar(HashEntidad<int, string>(14, "1000"));
			objetoHashtable.insertar(HashEntidad<int, string>(15, "1000"));
			objetoHashtable.insertar(HashEntidad<int, string>(16, "1000"));
			objetoHashtable.insertar(HashEntidad<int, string>(17, "1000"));

			objetoHashtable.mostrarHashtable();

			cout << "-------" << endl;
			cout << objetoHashtable.buscarKey("6");

			//hashtableObjeto.insertar(1, "one");
			//hashtableObjeto.insertar(11, "eleven");
			//hashtableObjeto.insertar(21, "twenty-one");
			//
			//cout << *hashtableObjeto.buscar(1) << endl;
			//cout << *hashtableObjeto.buscar(11) << endl;
			//cout << *hashtableObjeto.buscar(21) << endl;

			/*
			void imprimir(int elemento) {
			cout << elemento << " ";
			}

			int main() {
				ArbolBinario<int> *objetoArbolBinario = new ArbolBinario<int>(imprimir);
				objetoArbolBinario->insertar(10);
				objetoArbolBinario->insertar(4);
				objetoArbolBinario->insertar(15);
				objetoArbolBinario->insertar(2);
				objetoArbolBinario->insertar(5);

				cout << "Buscar 15: " << objetoArbolBinario->buscar(15) << " coincidencias" << endl;

				cout << "Arbol ordenado en-orden: ";
				objetoArbolBinario->ordenamientoEnOrden(); cout << endl;
				cout << "Arbol ordenado pre-orden: ";
				objetoArbolBinario->ordenamientoPreOrden(); cout << endl;
				cout << "Arbol ordenado post-orden: ";
				objetoArbolBinario->ordenamientoPostOrden(); cout << endl;

				cout << "El arbol esta vacio?: " << objetoArbolBinario->vacio(); cout << endl;
				cout << "Cantidad de elementos en el arbol: " << objetoArbolBinario->cantidad(); cout << endl;
				cout << "Altura del arbol: " << objetoArbolBinario->altura(); cout << endl;

				vector<int> vectorLista;
				for (int i = 0; i < objetoArbolBinario->cantidad(); i++) {
					vectorLista.push_back(5);
				}

				int respuesta = objetoArbolBinario->busquedaBinaria(vectorLista, 5);
				cout << "Se encuentra en el indice: " << respuesta << endl;

				cin.get();
				return 0;
			}
			*/

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
				cout << "\t\t\tLISTA ORDENADA:" << endl;
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

				string nombre, descripcion, comentario;
				bool disponibleParaComprar;
				int calificacion;

				string listaNombres[5] = { "Facebook", "Whatsapp", "Messenger", "X", "Telegram" };
				string listaDescripciones[2] = { "Aplicacion de entretenimiento" , "Red social" };
				string listaComentarios[5] = { "Muy buena aplicacion", "Aplicacion buena", "Estuvo el algo", "Mala aplicacion", "Pesima aplicacion" };

				Aplicacion* objetoAplicacion;

				for (int i = 0; i < numero; i++) {
					nombre = listaNombres[rand() % 5];
					descripcion = listaNombres[rand() % 2];
					disponibleParaComprar = rand() % 2;
					comentario = listaComentarios[rand() % 5];
					calificacion = rand() % 6;

					objetoAplicacion = new Aplicacion(nombre, descripcion, disponibleParaComprar, comentario, calificacion);
					objetoListaDoblementeEnlazada->insertarFinal(objetoAplicacion);
				}
				break;
			}
			else cout << "\t\t\tOpcion solo disponible para desarrolladores o staff de la app";
		}
		};
	}
};

#endif