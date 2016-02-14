#ifndef PILA_H
#define PILA_H
#include "Libro.h"
using namespace std;

class Pila
{
    public:
        Pila();
        void agregar(Libro* libro);//enqueue
        Libro* extraer();//dequeue
        void listarLibros();
        void buscarCategoria(string categoria);
        bool estaVacia();
    private:
        Libro* _ultimo;
        int size;
    friend class Menu;
};

#endif // PILA_H
