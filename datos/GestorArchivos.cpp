#include "GestorArchivos.hpp"

void GestorArchivos::cargarFavoritos(map<string, Favorito> &favoritos) {
  ifstream archivo("favoritos.txt");
  if (archivo.is_open()) {
    string nombre, url;
    while (archivo >> nombre >> url) {
      favoritos[nombre] = Favorito(url, nombre);
    }
    archivo.close();
  }
}

void guardarFavoritos(map<string, Favorito> &favoritos) {
  ofstream archivo("favoritos.txt");
  if (archivo.is_open()) {
    for (const auto &[nombre, favorito] : favoritos) {
      archivo << nombre << " " << favoritos.getURL() << "\n";
    }
    archivo.close();
  }
}
