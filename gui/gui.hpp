#include "../datos/GestorArchivos.hpp"

class Gui {
private:
  // Variable con la que el usuario eligira la opcion del menu

  int opcion = -1;
  Navegacion &navegador;
  GestorArchivos &gestor;

public:
  Gui();
  Gui(Navegacion &nav, GestorArchivos &gestor)
      : navegador(nav), gestor(gestor){};

  // Getters y Setters
  int getOpcion();
  void setOpcion(int);
  int menuPrincipal();
  void menuPaginasWeb();
  void menuPaginasWebFavorito();
};
