#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Libro.h"

class Nodo{
private:
    Libro B;
    Nodo* sig;
public:
    Nodo();
    Nodo(Libro& B);
    Libro getLibro();
    void setLibro(Libro);
    Nodo *getSig();
    void setSig(Nodo *valor);
};

class Lista
{
private:
    Nodo* primero;
    int contador;
public:
    Lista();
    int menuPrincipal();
    void insertaFinal(Libro);
    int Vacia();
    void mostrarTodos();
    Nodo* localiza(string);
    Libro recupera(Nodo*);
    void elimina(Nodo*);
    int compararISBN(string);
    int getContador();
    void setContador(int);
    Libro Primer();
    Libro Ultimo();
    void Borra();
    Libro Anterior(int);
    Libro Siguiente(int);
};
#endif // LISTA_H
