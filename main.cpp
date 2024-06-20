#include "gui/gui.hpp"
#include <iostream>
using namespace std;

int main() {

  

  Navegacion nav;
  GestorArchivos ges;

  string paginas[8] = {"Youtube", "shein", "StackOverflow", "GitHub", "Google", "Amazon", "Wikipedia"};

  for (int i = 0; i < 8; i ++){
    nav.agregarPagina(paginas[i]);
  }

  Gui gui(nav, ges);
  gui.menuPrincipal();

  return 0;
}
