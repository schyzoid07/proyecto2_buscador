#pragma once
#include "Favorito.hpp"
#include <string>
#include <vector>

class CarpetaFavoritos {
public:
  
   CarpetaFavoritos();
    CarpetaFavoritos(const std::string& nombre);
    void agregarFavorito(const Favorito& favorito);
  bool eliminarFavorito(const std::string& nombre);
    const std::vector<Favorito>& getFavoritos() const;

private:
  std::string nombre;
  std::vector<Favorito> favoritos;
};
