#ifndef _GUI_HPP
#define _GUI_HPP

class Gui
{
private:
//Variable ocn la que el usuario eligira la opcion del menu
    int opcion=-1;
    //0.    Salir
    //1.    
    //
    //
    //
public:
//Getters y Setters
int getOpcion();
void setOpcion(int);
int menuPrincipal();
int menuPaginasWeb();
int menuPaginasWebFavorito();
};


#endif