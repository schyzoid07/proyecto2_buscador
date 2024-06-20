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

void guardarFavoritos(const std::map<std::string, Favorito> &favoritos) {
    std::ofstream archivo("favoritos.txt");

    for (const auto &pair : favoritos) {
        const std::string &nombre = pair.first;
        const Favorito &favorito = pair.second;
        archivo << nombre << " " << favorito.getUrl() << "\n";
    }
}
