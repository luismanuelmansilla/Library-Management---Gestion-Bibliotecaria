#ifndef LIBRO_H
#define LIBRO_H
#include "string"
using namespace std;

class Libro
{
   public:
        Libro(string titulo, string autor, string editora, int dia, int mes, int anio, string categoria);
        string getTitulo();
        string getAutor();
        string getEditora();
        string getCategoria();
        int getDia();
        int getMes();
        int getAnio();
        Libro* getAnterior();
        void mostrarLibro(int cont);
    private:
        string _titulo;
        string _autor;
        string _editora;
        int _dia;
        int _mes;
        int _anio;
        string _categoria;
        Libro* _anterior;
    friend class Pila;
};

#endif // LIBRO_H
