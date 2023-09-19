#pragma once
#include "usuario.hpp"

class UsuarioStaff : public Usuario {
private:
	bool estaUsuarioActivo;
public:
	UsuarioStaff() : Usuario("staff", "staff") {
		this->estaUsuarioActivo = 1;
	}

	bool getEstaUsuarioActivo() { return estaUsuarioActivo; }
};