#include <iostream>
#include "gui.hpp"

int gui::getOpcion() {
    return opcion;
}

void gui::setOpcion(int op) {
    opcion=op;
}

int gui::menuPrincipal() {
    system("cls");
    std::cout<<"        ¡Bienvenido usuario!"<<std::endl;
    
    while (opcion=-1) {
        std::cout<<"Por favor, introduzca la opcion que desee ejecutar:"<<std::endl;
    std::cout<<"0. Salir"<<std::endl;
    std::cout<<"1. Navegar a una Pagina Web"<<std::endl;
    std::cout<<"2. Navegar a una Pagina Web de favoritos"<<std::endl;
    std::cin>>opcion;

    switch (opcion)
        {
        case 0:
            system("cls");
            std::cout<<"Hasta luego :)"<<std::endl;
            break;
        case 1:
            
            break;
        case 2:
            
            break;
        default:
            std::cout<<"Opcion no valida";
            opcion=-1;
            break;
        }
    }
}
 