#include "CarpetaFavoritos.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Navegacion {

private:
  struct pagina {
    string nombre = ".txt";
    string URL = "https://.com";
  };
  stack<string> historial;
  stack<string> historialProximo;
  map<string, Favorito> favoritos;
  queue<Favorito> favoritosEliminados;
  map<string, CarpetaFavoritos> carpetas;

public:
  void navegar(string &url);
  void navegarFavorito(string &url);
  void navegarAdelante();
  void navegarAtras();
  void guardarFavorito(string &url, string &nombre);
  void eliminarFavorito(string &url);
  void restaurarFavorito();
  void organizarFavoritos();
  void exportarFavoritosHTML(string &archivo);
  void mostrarFavoritos();

  void cargarArchivo(pagina historial);
};
