#include "Navegacion.hpp"

Navegacion::Navegacion() : paginaActual(-1){}



void Navegacion::cargarArchivo(pagina historial) {}

void Navegacion::agregarPagina(string& pagina) {
    paginas.push_back(pagina);
}

void Navegacion::navegar() {
    std::cout << "Páginas disponibles:\n";
    for (size_t i = 0; i < paginas.size(); ++i) {
        std::cout << i << ". " << paginas[i] << "\n";
    }
    std::cout << "Ingrese el número de la página a la que desea navegar: ";
    int opcion;
    std::cin >> opcion;
    if (opcion >= 0 && opcion < paginas.size()) {
        paginaActual = opcion;
        historial.push_back(paginas[opcion]);
        std::cout << "Navegando a " << paginas[opcion] << "\n";
    } else {
        std::cout << "Opción no válida.\n";
    }
}

void Navegacion::navegarFavorito(string &nombre) {
  auto it = favoritos.find(nombre);
  if (it != favoritos.end()) {
    // navegar(it->second.getUrl());
  } else {
    cout << "Favorito no encontrado.\n";
  }
}

void Navegacion::navegarAdelante() {
    if (paginaActual + 1 < paginas.size()) {
        paginaActual++;
        historial.push_back(paginas[paginaActual]);
        std::cout << "Navegando a " << paginas[paginaActual] << "\n";
    } else {
        std::cout << "No hay más páginas hacia adelante.\n";
    }
}

void Navegacion::navegarAtras() {
    if (paginaActual > 0) {
        paginaActual--;
        historial.push_back(paginas[paginaActual]);
        std::cout << "Navegando a " << paginas[paginaActual] << "\n";
    } else {
        std::cout << "No hay más páginas hacia atrás.\n";
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

void Navegacion::eliminarPaginaFavoritos() {
    std::cout << "Ingrese el nombre de la carpeta de donde desea eliminar una página favorita: ";
    std::string nombreCarpeta;
    std::cin >> nombreCarpeta;

    auto it = find_if(carpetasFavoritos.begin(), carpetasFavoritos.end(), [&](const std::pair<std::string, CarpetaFavoritos>& carpeta) {
        return carpeta.first == nombreCarpeta;
    });

    if (it != carpetasFavoritos.end()) {
        std::cout << "Ingrese el nombre de la página que desea eliminar: ";
        std::string nombrePagina;
        std::cin >> nombrePagina;

        bool eliminado = it->second.eliminarFavorito(nombrePagina);
        if (eliminado) {
            favoritosEliminados.push(nombrePagina);
            std::cout << "Página eliminada de la carpeta " << nombreCarpeta << ".\n";
        } else {
            std::cout << "No se encontró la página en la carpeta " << nombreCarpeta << ".\n";
        }
    } else {
        std::cout << "No se encontró la carpeta " << nombreCarpeta << ".\n";
    }
}


void Navegacion::eliminarFavorito(string& nombre) {
    auto it = std::find_if(favoritos.begin(), favoritos.end(), [&](const std::pair<std::string, Favorito>& par) {
        return par.first == nombre;
    });

    if (it != favoritos.end()) {
        Favorito eliminado = it->second;
        favoritosEliminados.push(eliminado.getUrl());
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
        std::string paginaRestaurada = favoritosEliminados.front();
        favoritosEliminados.pop();
        std::cout << "Ingrese el nombre de la carpeta a la que desea restaurar la página: ";
        std::string nombreCarpeta;
        std::cin >> nombreCarpeta;

        auto it = std::find_if(carpetasFavoritos.begin(), carpetasFavoritos.end(), [&](const std::pair<std::string, CarpetaFavoritos>& carpeta) {
            return carpeta.first == nombreCarpeta;
        });

        if (it != carpetasFavoritos.end()) {
            it->second.agregarFavorito(Favorito(paginaRestaurada, paginaRestaurada));
            std::cout << "Página restaurada en la carpeta " << nombreCarpeta << ".\n";
        } else {
            std::cout << "No se encontró la carpeta " << nombreCarpeta << ".\n";
        }
    } else {
        std::cout << "No hay páginas para restaurar.\n";
    }
}



void Navegacion::organizarFavoritos() {
    std::string nombreCarpeta;
    std::cout << "Ingrese el nombre de la carpeta: ";
    std::cin >> nombreCarpeta;
    carpetasFavoritos.push_back(std::make_pair(nombreCarpeta, CarpetaFavoritos(nombreCarpeta)));
    std::cout << "Favoritos organizados en carpeta: " << nombreCarpeta << std::endl;
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

const std::vector<std::pair<std::string, CarpetaFavoritos>>& Navegacion::getFavoritos() const {
    return carpetasFavoritos;
}