#ifndef __ENTIDADHASH_HPP__
#define __ENTIDADHASH_HPP__

template<typename K, typename V>
class hashEntidad {
public: 
	K key;
	V value;
	bool estaActivo;  // Indica si la entrada está activa o ha sido borrada previamente
	
	hashEntidad() : estaActivo(false) {}
	hashEntidad(K k, V v) : key(k), value(v), estaActivo(true) {}
};

#endif