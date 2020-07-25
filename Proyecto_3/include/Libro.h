#ifndef LIBRO_H
#define LIBRO_H
#include <string>

using namespace std;

class Libro
{
private:
    string nombre;
    string autor;
    string editorial;
    string categoria;
    string isbn;
    int existencia;

public:
    Libro();
    Libro(string nombre, string autor, string isbn, string categoria, string editorial, int existencia);
    string getNombre() ;
    void setNombre(string);
    string getAutor() ;
    void setAutor(string);
    string getEditorial() ;
    void setEditorial(string);
    string getCategoria() ;
    void setCategoria(string);
    string getIsbn() ;
    void setIsbn(string);
    int getExistencia() ;
    void setExistencia(int value);
    string toString();
};

#endif // LIBRO_H
