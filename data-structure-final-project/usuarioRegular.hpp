#pragma once
#include "usuario.hpp"

class UsuarioRegular : public Usuario {
private:
	bool estaUsuarioActivo;
public:
	UsuarioRegular() : Usuario("regular", "regular") {
		this->estaUsuarioActivo = 1;
	}

	bool getEstaUsuarioActivo() { return estaUsuarioActivo; }
};