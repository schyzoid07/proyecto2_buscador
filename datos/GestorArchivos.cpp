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

void GestorArchivos::exportarFavoritosHTML(const std::vector<std::pair<std::string, CarpetaFavoritos>> &favoritos) {
    std::ofstream archivo("favoritos.html");
    archivo << "<html><body><h1>Favoritos</h1>\n";
    for (const auto &carpeta : favoritos) {
        archivo << "<h2>Carpeta: " << carpeta.first << "</h2>\n<ul>\n";
        for (const auto &favorito : carpeta.second.getFavoritos()) {
            archivo << "<li><a href=\"" << favorito.getUrl() << "\">" << favorito.getUrl() << "</a></li>\n";
        }
        archivo << "</ul>\n";
    }
    archivo << "</body></html>\n";
    archivo.close();
}