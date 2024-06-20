#pragma once
#include "Favorito.hpp"
#include <string>
#include <vector>

class CarpetaFavoritos {
public:
  
  CarpetaFavoritos() : nombre("") {}
  CarpetaFavoritos(const std::string &nombre) : nombre(nombre) {}

  void agregarFavorito(const Favorito &favorito) {
    favoritos.push_back(favorito);
  }

private:
  std::string nombre;
  std::vector<Favorito> favoritos;
};
