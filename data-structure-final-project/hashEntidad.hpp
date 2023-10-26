#ifndef __ENTIDADHASH_HPP__
#define __ENTIDADHASH_HPP__

template <typename K, typename V>
class HashEntidad {
private:
	K key;
	V value;
public:
	HashEntidad() {
		this->key = 0;
		this->value = "";
	}
	HashEntidad(K key, V value) {
		this->key = key;
		this->value = value;
	}

	K getKey() const { return key; }
	V getValue() const { return value; }
};

#endif