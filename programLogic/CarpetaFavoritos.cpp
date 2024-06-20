#include "CarpetaFavoritos.hpp"
#include <algorithm> // para std::find_if

CarpetaFavoritos::CarpetaFavoritos() : nombre("") {}

CarpetaFavoritos::CarpetaFavoritos(const std::string& nombre) : nombre(nombre) {}

void CarpetaFavoritos::agregarFavorito(const Favorito& favorito) {
    favoritos.push_back(favorito);
}

bool CarpetaFavoritos::eliminarFavorito(const std::string& nombre) {
    auto it = std::remove_if(favoritos.begin(), favoritos.end(), [&](const Favorito& f) {
        return f.getNombre() == nombre;
    });

    if (it != favoritos.end()) {
        favoritos.erase(it, favoritos.end());
        return true;
    }
    return false;
}

const std::vector<Favorito>& CarpetaFavoritos::getFavoritos() const {
    return favoritos;
}
