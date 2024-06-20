#include "Navegacion.hpp"

void Navegacion::cargarArchivo(pagina historial) {}

void Navegacion::navegar(string &url) {
  historial.push(url);
  cout << "Navegando a: " << url << std::endl;
}

void Navegacion::navegarFavorito(string &nombre) {
  auto it = favoritos.find(nombre);
  if (it != favoritos.end()) {
    navegar(it->second.getUrl());
  } else {
    cout << "Favorito no encontrado.\n";
  }
}

void Navegacion::navegarAdelante() {
  if (!historialProximo.empty()) {
    string url = historialProximo.top();
    historialProximo.pop();
    historial.push(url);
    cout << "Navegando adelante a: " << url << std::endl;
  } else {
    cout << "No hay paginas hacia adelante.\n";
  }
}

void Navegacion::navegarAtras() {
  if (!historial.empty()) {
    historialProximo.push(historial.top());
    historial.pop();
    if (!historial.empty()) {
      std::cout << "Navegando atras a: " << historial.top() << std::endl;
    } else {
      std::cout << "No hay paginas anteriores.\n";
    }
  }
}

void Navegacion::guardarFavorito(string &url, string &nombre) {
  if (favoritos.find(nombre) == favoritos.end()) {
    favoritos[nombre] = Favorito(url, nombre);
    std::cout << "Favorito guardado: " << nombre << std::endl;
  } else {
    std::cout << "El nombre del favorito ya existe.\n";
  }
}

void Navegacion::eliminarFavorito(string &nombre) {
  auto it = favoritos.find(nombre);
  if (it != favoritos.end()) {
    Favorito eliminado = it->second;
    favoritosEliminados.push(eliminado);
    if (favoritosEliminados.size() > 5)
      favoritosEliminados.pop();
    favoritos.erase(it);
    std::cout << "Favorito eliminado: " << nombre << std::endl;
  } else {
    std::cout << "Favorito no encontrado.\n";
  }
}

void Navegacion::restaurarFavorito() {
  if (!favoritosEliminados.empty()) {
    Favorito restaurado = favoritosEliminados.front();
    favoritosEliminados.pop();
    favoritos[restaurado.getNombre()] = restaurado;
    std::cout << "Favorito restaurado: " << restaurado.getNombre() << std::endl;
  } else {
    std::cout << "No hay favoritos para restaurar.\n";
  }
}

void Navegacion::organizarFavoritos() {
  std::string nombreCarpeta;
  std::cout << "Ingrese el nombre de la carpeta: ";
  std::cin >> nombreCarpeta;
  carpetas[nombreCarpeta] = CarpetaFavoritos(nombreCarpeta);
  std::cout << "Favoritos organizados en carpeta: " << nombreCarpeta
            << std::endl;
}

void Navegacion::exportarFavoritosHTML(string &archivo) {
  std::ofstream html(archivo);
  html << "<html><head><title>Favoritos</title></head><body>\n";
  html << "<h1>Favoritos</h1><ul>\n";
  for (const auto &[nombre, favorito] : favoritos) {
    html << "<li><a href=\"" << favorito.getUrl() << "\">"
         << favorito.getNombre() << "</a></li>\n";
  }
  html << "</ul></body></html>\n";
  html.close();
  std::cout << "Favoritos exportados a: " << archivo << std::endl;
}

void Navegacion::mostrarFavoritos() {
  std::cout << "Favoritos:\n";
  for (const auto &[nombre, favorito] : favoritos) {
    std::cout << nombre << " (" << favorito.getUrl() << ")\n";
  }
}
