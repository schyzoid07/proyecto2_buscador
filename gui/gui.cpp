#include <iostream>
#include "Gui.hpp"

int Gui::getOpcion() {
    return opcion;
}

void Gui::setOpcion(int op) {
    opcion=op;
}

int Gui::menuPrincipal() {
    system("cls");
    std::cout<<"        ¡Bienvenido usuario!"<<std::endl;
    
    while (opcion=-1) {
    
    std::cout<<"0. Salir"<<std::endl;
    std::cout<<"1. Navegar a una Pagina Web"<<std::endl;
    std::cout<<"2. Navegar a una Pagina Web de favoritos"<<std::endl;
    std::cout<<"3. Exportar Paginas Web de su lista de Favoritos a un archivo HTML"<<std::endl;
    std::cout<<"Por favor, introduzca el numero correspondiente a la opcion que desee ejecutar:"<<std::endl;
    std::cin>>opcion;

    switch (opcion)
        {
        case 0:
            system("cls");
            std::cout<<"Hasta luego :)"<<std::endl;
            break;
        case 1:
            system("cls");
            menuPaginasWeb();
            break;
        case 2:
            system("cls");
            menuPaginasWebFavorito();
            break;
        default:
            std::cout<<"Opcion no valida";
            opcion=-1;
            break;
        }
    }
}
 

int Gui::menuPaginasWeb() {
    system("cls");    
    std::cout<<"0. Salir"<<std::endl;
    std::cout<<"1. Navegar hacia adelante"<<std::endl;
    std::cout<<"2. Navegar hacia atras"<<std::endl;
    std::cout<<"3. Guardar pagina en la lista de Favoritos"<<std::endl;
    std::cout<<"4. Eliminar pagina en la lista de Favoritos"<<std::endl;
    std::cout<<"Por favor, introduzca el numero correspondiente a la opcion que desee ejecutar:"<<std::endl;
    std::cin>>opcion;
}



int Gui::menuPaginasWebFavorito() {
    system("cls");    
    std::cout<<"0. Salir"<<std::endl;
    std::cout<<"1. Navegar hacia adelante"<<std::endl;
    std::cout<<"2. Navegar hacia atras"<<std::endl;
    std::cout<<"3. Eliminar pagina en la lista de Favoritos"<<std::endl;
    std::cout<<"4. Restaurar Favoritos (los 5 ultimos eliminados)"<<std::endl;
    std::cout<<"5. Organizar Favoritos"<<std::endl;
    std::cout<<"Por favor, introduzca el numero correspondiente a la opcion que desee ejecutar:"<<std::endl;
    std::cin>>opcion;
}