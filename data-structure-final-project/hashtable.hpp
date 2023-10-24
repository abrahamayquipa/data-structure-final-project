#ifndef __ENTIDAD_ABIERTO_HPP__
#define __ENTIDAD_ABIERTO_HPP__

#include <iostream>
#include <cmath>
#include "hashEntidad.hpp"
using namespace std;

template<typename K, typename V>
class HashTable {
private:
    hashEntidad<K, V>* tabla;
    int tamanoTabla;
    int tamanoActual;

    int hashFunc(const K& key) const {
        return static_cast<int>(key) % tamanoTabla;
    }

    // Tipos de direccionamiento
    int pruebaCuadratica(const K& key, int attempt) const {
        return (hashFunc(key) + attempt + attempt * attempt) % tamanoTabla;
    }

public:
    HashTable(int size = 101) : tamanoActual(0), tamanoTabla(siguientePrimo(size * 2)) {
        tabla = new hashEntidad<K, V>[tamanoTabla];
    }

    ~HashTable() {
        delete[] tabla;
    }

    // Una simple función para verificar si un número es primo
    bool esPrimo(int numero) {
        if (numero == 2 || numero == 3)  return true;
        if (numero == 1 || numero % 2 == 0) return false;

        for (int i = 3; i * i <= numero; i += 2)
            if (numero % i == 0) return false;

        return true;
    }

    // Obtener el siguiente número primo
    int siguientePrimo(int numero) {
        while (!esPrimo(numero)) numero++;
        return numero;
    }

    void insertar(const K& key, const V& value) {
        if (tamanoActual > tamanoTabla / 2) {
            // Ampliar y rehash si necesario
            rehash();
        }

        int intento = 0;
        int indice = pruebaCuadratica(key, intento);

        while (tabla[indice].estaActivo) {
            intento++;
            indice = pruebaCuadratica(key, intento);
        }

        tabla[indice] = hashEntidad<K, V>(key, value);
        tamanoActual++;
    }

    void rehash() {
        hashEntidad<K, V>* tablaAntigua = tabla;
        int tamanoTablaAntigua = tamanoTabla;

        tamanoTabla = siguientePrimo(2 * tamanoTabla);
        tabla = new hashEntidad<K, V>[tamanoTabla];
        tamanoActual = 0;

        for (int i = 0; i < tamanoTablaAntigua; i++) {
            if (tablaAntigua[i].estaActivo) {
                insertar(tablaAntigua[i].key, tablaAntigua[i].value);
            }
        }
        delete[] tablaAntigua;
    }

    V* buscar(const K& key) {
        int intento = 0;
        int indice = pruebaCuadratica(key, intento);

        while (tabla[indice].estaActivo && tabla[indice].key != key) {
            intento++;
            indice = pruebaCuadratica(key, intento);
        }

        if (tabla[indice].estaActivo && tabla[indice].key == key) {
            return &tabla[indice].value;
        }
        else {
            return nullptr;
        }
    }
};

#endif