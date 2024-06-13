#include "Favorito.hpp"
#include <fstream>
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
  stack<pagina> historial;
  stack<pagina> historialProximo;
  map<string, Favorito> favoritos;
  queue<Favorito> favoritosEliminados;
  map<string, CarpetaFavorito> carpetas;

public:
  void cargarArchivo(pagina historial);
};
