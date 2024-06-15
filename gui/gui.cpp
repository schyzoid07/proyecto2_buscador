#include <iostream>
#include "Gui.hpp"

int Gui::getOpcion() {
    return opcion;
}

void Gui::setOpcion(int op) {
    opcion=op;
}

int Gui::menuPrincipal() {
    while (opcion==-1) {
        system("cls");
        std::cout<<"        ¡Bienvenido usuario!"<<std::endl;
        
        
        
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
                std::cout<<"Hasta luego :)"<<std::endl<<std::endl;
                system("pause");
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
                std::cout<<"Opcion no valida. Por favor, introduzca un numero valido...";
                opcion=-1;
                break;
        }
    }
}
 

int Gui::menuPaginasWeb() {
    opcion=-1;
    while (opcion==-1) {

        system("cls");    
        std::cout<<"0. Salir"<<std::endl;
        std::cout<<"1. Navegar hacia adelante"<<std::endl;
        std::cout<<"2. Navegar hacia atras"<<std::endl;
        std::cout<<"3. Guardar pagina en la lista de Favoritos"<<std::endl;
        std::cout<<"4. Eliminar pagina en la lista de Favoritos"<<std::endl;
        std::cout<<"Por favor, introduzca el numero correspondiente a la opcion que desee ejecutar:"<<std::endl;
        std::cin>>opcion;
        
        switch (opcion)
        {
        case 0:
            system("cls");    
            std::cout<<"Volviendo al Menu Principal..."<<std::endl;
            system("pause");
            menuPrincipal();
            break;
        case 1:
            //Funcion para navegar hacia adelante
        break;

        case 2:
            //Funcion para navegar hacia atras
        break;
        
        case 3:
            //Funcion para guardar una pagina en la lista de Favs
        break;
        
        case 4:
            //Funcion para eliminar una pagina de la lista de Favs
        break;
        
        default:
            std::cout<<"Opcion no valida. Por favor, introduzca un numero valido...";
            opcion=-1;
            system("pause");
                break;
        break;
        }
    }
}



int Gui::menuPaginasWebFavorito() {
    opcion=-1;
    
    while (opcion==-1) {
        system("cls");    
        std::cout<<"0. Salir"<<std::endl;
        std::cout<<"1. Navegar hacia adelante"<<std::endl;
        std::cout<<"2. Navegar hacia atras"<<std::endl;
        std::cout<<"3. Eliminar pagina en la lista de Favoritos"<<std::endl;
        std::cout<<"4. Restaurar Favoritos (los 5 ultimos eliminados)"<<std::endl;
        std::cout<<"5. Organizar Favoritos"<<std::endl;
        std::cout<<"Por favor, introduzca el numero correspondiente a la opcion que desee ejecutar:"<<std::endl;
        std::cin>>opcion;

        switch (opcion)
        {
        case 0:
        system("cls");    
            std::cout<<"Volviendo al Menu Principal..."<<std::endl;
            system("pause");
            menuPrincipal();
        break;
        case 1:
            //Funcion para navegar hacia adelante
        break;

        case 2:
            //Funcion para navegar hacia atras
        break;
        
        case 3:
            //Funcion para eliminar pagina en la lista de Favoritos
        break;
        
        case 4:
            //Funcion para restaurar los ultimos 5 Favoritos eliminados
        break; 
        
        default:
            std::cout<<"Opcion no valida. Por favor, introduzca un numero valido...";
            opcion=-1;
            system("pause");
        break;
        }
    }
}