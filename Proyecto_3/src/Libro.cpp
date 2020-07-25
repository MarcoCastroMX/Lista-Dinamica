#include "Libro.h"
#include <string.h>
#include <sstream>

using namespace std;

Libro::Libro()
{
    //ctor
}

Libro::Libro(string nombre, string autor, string isbn, string categoria, string editorial, int existencia)
{
    this->nombre=nombre;
    this->autor=autor;
    this->isbn=isbn;
    this->existencia=existencia;
    this->categoria=categoria;
    this->editorial=editorial;
}

string Libro::getNombre()
{
    return nombre;
}

void Libro::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Libro::getCategoria()
{
    return categoria;
}

void Libro::setCategoria(string categoria)
{
    this->categoria = categoria;
}

string Libro::getIsbn()
{
    return isbn;
}

void Libro::setIsbn(string isbn)
{
    this->isbn = isbn;
}

int Libro::getExistencia()
{
    return existencia;
}

void Libro::setExistencia(int existencia)
{
    this->existencia = existencia;
}

void Libro::setEditorial(string editorial){
    this->editorial=editorial;
}

string Libro::getEditorial(){
    return editorial;
}

void Libro::setAutor(string autor){
    this->autor=autor;
}

string Libro::getAutor(){
    return autor;
}
string Libro::toString(){
    stringstream ss;
    ss<<existencia;
    string s = "";
    s = nombre+" "+autor+" "+isbn+" "+categoria+" "+editorial+" "+ss.str();
    return s;
}
