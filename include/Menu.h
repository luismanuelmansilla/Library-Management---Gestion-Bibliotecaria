#ifndef MENU_H
#define MENU_H
#include "Pila.h"
#include "Libro.h"
#include "Menu.h"

class Menu
{
    public:
        Menu();
        void menuPrincipal();
        void menuListar();
        void menuInsertar();
        void menuSolicitar();
        void menuBuscar();
        bool verificarFecha(int dia, char a, int mes,char b, int anio);
    friend class Pila;
};

#endif // MENU_H
