#include "Web.hpp"
#include <iostream>


/**
 * @brief 
 *  Estos metodos asignan los valores de URL y nombre
 * @param urlSetted 
 */
void Web::setUrl( string urlSetted) 
{
     url=urlSetted;
}

void Web::setNombre( string nombreSetted) 
{
      nombre=nombreSetted;
}

/**
 * @brief 
 * Estos metodo retorna el valor de URL y NOMBRE
 * @return string 
 */
string Web::getUrl()
 {
    return url;
}

string Web::getNombre() 
{
    return nombre;
}