#include "CarpetaFavoritos.hpp"
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class Navegacion {

private:
  struct pagina {
    string nombre = ".txt";
    string URL = "https://.com";
  };
  vector<string> paginas;
  vector<string> historial;
  vector<string> historialProximo;
  map<string, Favorito> favoritos;
  queue<string> favoritosEliminados;
  vector<pair<string, CarpetaFavoritos>> carpetasFavoritos;
  int paginaActual;

public:
  Navegacion();
  void navegar();
  void navegarFavorito(string &url);
  void navegarAdelante();
  void navegarAtras();
  void guardarFavorito(string &url, string &nombre);
  void eliminarFavorito(string &nombre);
  void eliminarPaginaFavoritos();
  void restaurarFavorito();
  void organizarFavoritos();
  void exportarFavoritosHTML(string &archivo);
  void mostrarFavoritos();
  void agregarPagina(string& pagina);
  const std::vector<std::pair<std::string, CarpetaFavoritos>>&getFavoritos() const;

  void cargarArchivo(pagina historial);
};
