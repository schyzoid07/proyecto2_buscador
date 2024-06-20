#include "gui.hpp"
#include <iostream>


int Gui::getOpcion() { return opcion; }

void Gui::setOpcion(int op) { opcion = op; }

int Gui::menuPrincipal() {
  while (opcion != 0) {
    system("cls");
    std::cout << "        ¡Bienvenido usuario!" << std::endl;

    std::cout << "0. Salir" << std::endl;
    std::cout << "1. Navegar a una Pagina Web" << std::endl;
    std::cout << "2. Navegar a una Pagina Web de favoritos" << std::endl;
    std::cout
        << "3. Exportar Paginas Web de su lista de Favoritos a un archivo HTML"
        << std::endl;
    std::cout << "Por favor, introduzca el numero correspondiente a la opcion "
                 "que desee ejecutar:"
              << std::endl;
    std::cin >> opcion;

    switch (opcion) {
    case 0:
      system("cls");
      std::cout << "Hasta luego :)" << std::endl << std::endl;
      return 0;
    case 1: {
      system("cls");
      menuPaginasWeb();
      break;
    }
    case 2: {
      system("cls");
      menuPaginasWebFavorito();
      break;
    }
    case 3: {
      system("cls");
      cout << "Ingrese el nombre del archivo HTML a exportar: ";
      string archivo;
      cin >> archivo;
      navegador.exportarFavoritosHTML(archivo);
      break;
    }
    default:
      std::cout
          << "Opcion no valida. Por favor, introduzca un numero valido...";
      break;
    }
  }
  return 0;
}

void Gui::menuPaginasWeb() {
  opcion = -1;
  while (true) {

    system("cls");
    std::cout << "0. Salir" << std::endl;
    std::cout << "1. Navegar hacia adelante" << std::endl;
    std::cout << "2. Navegar hacia atras" << std::endl;
    std::cout << "3. Guardar pagina en la lista de Favoritos" << std::endl;
    std::cout << "4. Eliminar pagina en la lista de Favoritos" << std::endl;
    std::cout << "Por favor, introduzca el numero correspondiente a la opcion "
                 "que desee ejecutar:"
              << std::endl;
    std::cin >> opcion;

    switch (opcion) {
    case 0:
     
      std::cout << "Volviendo al Menu Principal..." << std::endl;
      opcion = -1;
      return;
      break;
    case 1:
      navegador.navegarAdelante();
      break;

    case 2:
      navegador.navegarAtras();
      break;

    case 3: {
      std::string url, nombre;
      std::cout << "Ingrese la URL del favorito: ";
      std::cin >> url;
      std::cout << "Ingrese el nombre del favorito: ";
      std::cin >> nombre;
      navegador.guardarFavorito(url, nombre);
    } break;
    case 4: {
      std::string nombre;
      std::cout << "Ingrese el nombre o URL del favorito a eliminar: ";
      std::cin.ignore();
      std::getline(std::cin, nombre);
      navegador.eliminarFavorito(nombre);
    } break;

    default:
      std::cout
          << "Opcion no valida. Por favor, introduzca un numero valido...";
      opcion = -1;
      system("pause");
      break;
    }
  }
}

void Gui::menuPaginasWebFavorito() {
 

  while (true) {
    system("cls");
    std::cout << "0. Salir" << std::endl;
    std::cout << "1. Navegar hacia adelante" << std::endl;
    std::cout << "2. Navegar hacia atras" << std::endl;
    std::cout << "3. Eliminar pagina en la lista de Favoritos" << std::endl;
    std::cout << "4. Restaurar Favoritos (los 5 ultimos eliminados)"
              << std::endl;
    std::cout << "5. Organizar Favoritos" << std::endl;
    std::cout << "Por favor, introduzca el numero correspondiente a la opcion "
                 "que desee ejecutar:"
              << std::endl;
    std::cin >> opcion;

    switch (opcion) {
    case 0:
      system("cls");
      std::cout << "Volviendo al Menu Principal..." << std::endl;
      opcion = -1;
      return;
    case 1:
      navegador.navegarAdelante();
      break;
    case 2:
      navegador.navegarAtras();
      break;
    case 3: {
      std::string nombre;
      std::cout << "Ingrese el nombre o URL del favorito a eliminar: ";
      std::cin.ignore();
      std::getline(std::cin, nombre);
      navegador.eliminarFavorito(nombre);
    } break;
    case 4:
      navegador.restaurarFavorito();
      break;
    case 5:
      navegador.organizarFavoritos();
      break;
    default:
      std::cout
          << "Opcion no valida. Por favor, introduzca un numero valido...";
      opcion = -1;
      system("pause");
      break;
    }
  }
}
