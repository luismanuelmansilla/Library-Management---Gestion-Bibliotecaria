#include "Pila.h"
#include <iostream>
#include <stdlib.h>
#include<string>

using namespace std;

Pila::Pila(): _ultimo(NULL), size(NULL)
{

}

void Pila::agregar(Libro* libro)
{
    Libro* tempLibro = libro;
    tempLibro ->_anterior =_ultimo;
    _ultimo = tempLibro;
    size++;
}

Libro* Pila::extraer()
{
    if(estaVacia()){
        return 0;
    }
    Libro* retorno = _ultimo;
    _ultimo = _ultimo -> _anterior;
    size--;
    return retorno;
}

void Pila::listarLibros()
{
    if(estaVacia()){
        cout << "\nNo hay libros agregados!!\n";
        return;
    }

    Pila* pila=new Pila();
    int cont=1;
    while(_ultimo){
        _ultimo->mostrarLibro(cont);
        pila->agregar(extraer());
        cont++;
    }
    while(pila->_ultimo)
        agregar(pila->extraer());
}


void Pila::buscarCategoria(string categoria)
{
    Pila* pila = new Pila();
    while(_ultimo)
    {
        if(_ultimo -> _categoria == categoria)
        {
            cout<<"\nSe ha removido el libro: " << _ultimo-> getTitulo() << ". Cumple con el criterio de b\243squeda.\n";
            break;
        }
        cout<<"\nSe ha removido el libro: " <<_ultimo -> getTitulo()<< ". No cumple con el criterio de b\243squeda.";
        pila -> agregar(extraer());
        if(estaVacia())
            cout << "\n\n    !No hay libros que cumplan con la categoria: " << categoria;
    }
    while(pila->_ultimo){
        agregar(pila -> extraer());
    }

}

bool Pila::estaVacia()
{
    return !size;
}
