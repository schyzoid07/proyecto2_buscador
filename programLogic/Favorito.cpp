#include "Favorito.hpp"

Favorito::Favorito(string &urlEnviado, string &nombreEnviado) {

  url = urlEnviado;
  nombre = nombreEnviado;
}

string Favorito::getUrl() const { return url; }
string Favorito::getNombre() const { return nombre; }
