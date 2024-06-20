#include "gui/gui.hpp"
#include <iostream>
using namespace std;

int main() {

  Navegacion nav;
  GestorArchivos ges;
  Gui gui(nav, ges);
  gui.menuPrincipal();

  return 0;
}
