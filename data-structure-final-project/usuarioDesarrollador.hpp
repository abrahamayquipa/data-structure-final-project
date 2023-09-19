#pragma once
#include "usuario.hpp"

class UsuarioDesarrollador : public Usuario {
private:
	bool tienePenalizaciones;
public:
	UsuarioDesarrollador() : Usuario("desarrollador", "desarrollador") {
		this->tienePenalizaciones = 0;
	}

	bool getEstaUsuarioActivo() { return tienePenalizaciones; }
};