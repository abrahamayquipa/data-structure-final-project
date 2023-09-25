#pragma once
#include "usuario.hpp"

class UsuarioStaff : public Usuario {
public:
	UsuarioStaff() : Usuario(3) { }
};