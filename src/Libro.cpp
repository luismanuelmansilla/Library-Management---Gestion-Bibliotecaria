#include "Libro.h"
#include <iostream>
#include <stdlib.h>

Libro::Libro(string titulo, string autor, string editora, int dia, int mes, int anio, string categoria)
{
    _titulo = titulo;
    _autor = autor;
    _editora = editora;
    _dia = dia;
    _mes = mes;
    _anio = anio;
    _categoria = categoria;
    _anterior = NULL;

}
void Libro::mostrarLibro(int cont)
{
    cout << cont << ". ";
    cout << "T\241tulo: ";
    cout << getTitulo() << "\n";
    cout << "   Autor: ";
    cout << getAutor() << "\n";
    cout << "   Editora: ";
    cout << getEditora() << "\n";
    cout << "   Fecha de Publicaci\242n: ";
    cout << getDia() << "/" << getMes() << "/" << getAnio() << "\n";
    cout << "   Categor\241a: ";
    cout << getCategoria()  << "\n" << endl;
}

string Libro::getTitulo()
{
    return _titulo;
}


string Libro::getAutor()
{
    return _autor;
}

string Libro::getEditora()
{
    return _editora;
}

int Libro::getDia()
{
    return _dia;
}

int Libro::getMes()
{
    return _mes;
}

int Libro::getAnio()
{
    return _anio;
}

string Libro::getCategoria()
{
    return _categoria;
}

Libro* Libro::getAnterior()
{
    return _anterior;
}
