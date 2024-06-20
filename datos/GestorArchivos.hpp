#include "../programLogic/Navegacion.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class GestorArchivos {
public:
  void cargarFavoritos(map<string, Favorito> &favoritos);
  void guardarFavoritos(map<string, Favorito> &favoritos);
};
