#include <iostream>
#include<stdio.h>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include "Menu.h"
#include "Pila.h"
using namespace std;

Pila* pila = new Pila();

Menu::Menu()
{
    //ctor
}

void Menu::menuPrincipal()
{
    char opcionMenu;
    do {
        cout << "\n\n\tGesti\242n Bibliotecaria\n\n";
        cout << "1. Listar libros.\n";
        cout << "2. Insertar libro.\n";
        cout << "3. Solicitar \243ltimo libro de la pila.\n";
        cout << "4. Buscar libro por categor\241a.\n";
        cout << "5. Salir.\n";
        cout << "\nElija una opci\242n => ";
        opcionMenu=_getch();
        cin.clear();
        fflush(stdin);
        cout << "\n";

        switch (opcionMenu) {
            case '1': menuListar();
            break;
            case '2': menuInsertar();
            break;
            case '3': menuSolicitar();
            break;
            case '4': menuBuscar();
            break;
            case '5':
                system("cls");
                cout << "\n\n\nGracias por usar el programa, hasta la pr\242xima!\n";
                break;
            default: cout << "\n" <<"\nOpci\242n Invalida! Presione cualquier tecla para continuar...\n";
        }
        system("PAUSE>null");
        system("cls");
    }while(opcionMenu != '5');

}

void Menu::menuListar()
{
    system("cls");
    cout << "\n\n\tListado de Libros\n\n";
    pila->listarLibros();
    cout << "\n--Presione Cualquier tecla para regresar al men\243 principal --\n";
}

void Menu::menuInsertar()
{
    system("cls");
    string titulo, autor, editora, categoria;
    int dia, mes, anio;
    char a, b;
    cin.clear();
    fflush(stdin);

    cout << "\n\n\tInsertar Libro\n\n" << endl;

    do{
        cout << "Introduzca el t\241tulo del libro: ";
        getline(cin, titulo);
    }while (titulo.empty());
    do{
        cout << "Introduza el autor del libro: ";
        getline(cin, autor);
    }while (autor.empty());
    do{
        cout << "Introduzca la editora del libro: ";
        getline(cin, editora);
    }while (editora.empty());
    do{
        cout << "Introduzca la fecha de publicaci\242n del libro (DD/MM/AAAA): ";
        cin >> dia >> a >> mes >> b >> anio;
        if(!verificarFecha(dia,a,mes,b,anio)){
            cout << "\tIncorrecto el formato: DD/MM/AAAA\n";
        }
    }while(!verificarFecha(dia,a,mes,b,anio));
    do{
        cin.ignore();
        cout << "Introduzca la categor\241a del libro: ";
        getline(cin, categoria);
    }while(categoria.empty());

    pila -> agregar(new Libro(titulo, autor, editora, dia, mes, anio, categoria));
    pila -> size++;
    cout << "\n--Libro Agregado. Presione cualquier tecla para regresar al men\243 principal--\n";

}

void Menu::menuSolicitar()
{
    system("cls");
    cout << "\n\n\tSolicitar \243ltimo libro de la pila\n\n";
    if(pila -> estaVacia()){
        cout << "\nNo hay libros agregados!!\n";
        cout << "\n--Presione cualquier tecla para regresar al men\243 principal--\n";
    }else{
        Libro* i = pila -> extraer();
        cout << "Ultimo libro: \n";
        cout << "\n";
        i -> mostrarLibro(1);
        pila -> size--;
        cout << "\n--Presione Cualquier tecla para regresar el men\243 principal --\n";
    }
}

void Menu::menuBuscar()
{
    system("cls");
    string categoria;

    cout << "\n\n\tBuscar libro por categor\241a.\n\n";
    if(pila -> estaVacia()){
        cout << "\nNo hay libros agregados!!\n";
        cout << "\n--Presione cualquier tecla para regresar al men\243 principal--\n";
    }else{
        cout << "Seleccione la categor\241a de que desea buscar: ";
        do{
           getline(cin, categoria);
        }while (categoria.empty());

        pila->buscarCategoria(categoria);

        cout << "\n--Presione cualquier tecla para regresar al men\243 principal--\n";
    }
}

bool Menu::verificarFecha(int dia, char a, int mes,char b, int anio)
{
    char caract = 47;
    if ((dia>0 && dia< 32 && a == caract && mes >0 && mes < 13 && b == caract && anio>0 && anio<2101)){
        return true;
    }
    return false;

}

