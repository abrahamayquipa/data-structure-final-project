#include "HashEntidad.hpp"
#include <string>
#include <vector>
#include <list>

template<typename K, typename V>
class HashTable {
private:
    vector<HashEntidad<K, V>> tabla;
    int tamanoTabla;
    int tamanoActual;

    /*
    * Fuente 1: stackoverflow
    * https://stackoverflow.com/questions/7666509/hash-function-for-string
    * 
    * Fuente 2: stackoverflow
    * https://cp-algorithms.com/string/string-hashing.html
    */

    /*
    int funcionHash(const K& key) const {
        int hashVal = 0;
        for (char ch : to_string(key)) hashVal = 37 * hashVal + ch;
        return hashVal % tamanoTabla;
    }*/

    size_t funcionHash(const K& key) const {
        hash<K> hashFunction;
        size_t hashVal = hashFunction(key);

        for (char ch : to_string(key)) {
            hashVal = (hashVal << 5) ^ (hashVal >> 27) ^ ch;
        }

        return (hashVal % tamanoTabla + tamanoTabla) % tamanoTabla;
    }

    //int pruebaCuadratica(const K& key, int attempt) const {
    //    return (funcionHash(key) + attempt + attempt * attempt) % tamanoTabla;
    //}

    int pruebaCuadratica(const K& key, int intento) const {
        auto prueba = [this, &key, &intento]() {
            return (funcionHash(key) + intento + intento * intento) % tamanoTabla;
        };
        return prueba();
    }

    //bool esPrimo(int n) const {
    //    if (n == 2 || n == 3) return true;
    //    if (n == 1 || n % 2 == 0) return false;
    //    for (int i = 3; i * i <= n; i += 2)
    //        if (n % i == 0) return false;
    //    return true;
    //}

    bool esPrimo(int n) const {
        auto lambda = [](int n) {
            if (n == 2 || n == 3) return true;
            if (n == 1 || n % 2 == 0) return false;
            for (int i = 3; i * i <= n; i += 2)
                if (n % i == 0) return false;
            return true;
        };
        return lambda(n);
    }

    int siguientePrimo(int n) const {
        if (n % 2 == 0) ++n;
        for (; !esPrimo(n); n += 2) ;
        return n;
    }

public:
    HashTable(int size = 20) : tamanoTabla(size), tamanoActual(0) {
        auto lambda = [this]() {
            tabla.resize(tamanoTabla);
            };
        lambda();
    }

    void rehash() {
        vector<HashEntidad<K, V>> oldTabla = tabla;
        tamanoTabla = siguientePrimo(2 * this->tamanoTabla);
        tabla.resize(tamanoTabla);

        for (auto& item : tabla) { item = HashEntidad<K, V>(); }

        tamanoActual = 0;
        for (auto& oldItem : oldTabla) {
            if (oldItem.getKey() != K()) insertar(oldItem);
        }
    }

    void insertar(const HashEntidad<K, V>& entidad) {
        int indice = funcionHash(entidad.getKey());
        int intentos = 0;

        while (tabla[indice].getKey() != K() && intentos < tamanoTabla) {
            indice = pruebaCuadratica(entidad.getKey(), intentos);
            intentos++;
        }

        if (intentos == tamanoTabla) {
            rehash();
            insertar(entidad);
            return;
        }

        tabla[indice] = entidad;
        tamanoActual++;
    }

    void eliminar(const K& key) {
        int indice = funcionHash(key);
        int intentos = 0;

        while (tabla[indice].getKey() != K() && intentos < tamanoTabla) {
            if (tabla[indice].getKey() == key) {
                // Encuentra la clave y la elimina
                tabla[indice] = HashEntidad<K, V>();
                tamanoActual--;
                return;
            }
            indice = pruebaCuadratica(key, intentos);
            intentos++;
        }
    }


    bool estaVacio() const { return tamanoActual == 0; }
    int longitudActual() const {  return tamanoActual; }

    int buscarKey(const V& value) const {
        int valor;
        for (int i = 0; i < tamanoActual; i++) {
            if (tabla[i].getValue() == value) {
                return valor = tabla[i].getKey();
            }
        }
    }

    void mostrarHashtable() const {
        for (int i = 0; i < tamanoTabla; i++) {
            cout << "Posicion " << i + 1 << ": ";
            if (tabla[i].getKey() != K()) {  // Si hay una entidad almacenada en la posición
                cout << "(" << tabla[i].getKey() << ", " << tabla[i].getValue() << ")";
            }
            else cout << "vacio";
            cout << endl;
        }
    }

    void mostrar() {
        for (int i = 0; i < tamanoTabla; i++) {
            if (tabla[i].getKey() != K()) cout << tabla[i].getValue() << endl;
        }
    }
};