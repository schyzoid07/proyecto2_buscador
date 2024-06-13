#include "Favorito.hpp"

Favorito::Favorito(string &urlEnviado, string &nombreEnviado) {

  url = urlEnviado;
  nombre = nombreEnviado;
}

string Favorito::getUrl() { return url; }
string Favorito::getNombre() { return nombre; }
