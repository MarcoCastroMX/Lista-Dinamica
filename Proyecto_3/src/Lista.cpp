#include "Lista.h"
#include <iostream>
#include "Libro.h"

using namespace std;

Lista::Lista(){
    primero = nullptr;
    contador = 0;
}
Nodo::Nodo(){
    sig = nullptr;
}
Nodo::Nodo(Libro& B){
    this->B = B;
    sig = nullptr;
}
Nodo *Nodo::getSig(){
    return sig;
}
void Nodo::setSig(Nodo *direccion){
    sig = direccion;
}
Libro Nodo::getLibro(){
    return B;
}
void Nodo::setLibro(Libro B){
    this->B = B;
}
int Lista::menuPrincipal(){
    int respuesta;
    cout<<"\t\tLIBRERIA\n_______________________________________"<<endl;
    cout<<"[1] Agregar Nuevo\n[2] Lista Vacia?\n[3] Eliminar Libro\n[4] Mostrar Primer Libro\n[5] Mostrar Ultimo Libro\n[6] Mostrar Libro Anterior\n[7] Mostrar Libro Siguiente\n[8] Mostrar Ficha de Libro\n[9] Imprimir Catalogo\n[10] Borrar Todo\n[0] Salir"<<endl;
    cout<<"Opcion: ";
    cin>>respuesta;
    return respuesta;
}
void Lista::insertaFinal(Libro B){
    Nodo* nuevoNodo = new Nodo(B);
    if (contador == 0){
        primero = nuevoNodo;
    }
    else{
        Nodo* aux;
        aux = primero;
        while(aux->getSig()!=nullptr){
            aux = aux->getSig();
        }
        aux->setSig(nuevoNodo);
    }
    contador++;
}
int Lista::Vacia(){
    return contador;
}
void Lista::mostrarTodos()
{
    Nodo* aux;
    aux = primero;

    while(aux!=nullptr){
        cout<<aux->getLibro().toString()<<endl;
        aux = aux->getSig();
    }
}
Nodo* Lista::localiza(string _isbn){

    Nodo* aux;
    aux = primero;
    while(aux!=nullptr){
        if(_isbn == aux->getLibro().getIsbn()){
            return aux;
        }
        aux = aux->getSig();
    }
    return nullptr;
}
void Lista::elimina(Nodo *elim){
    Nodo* ant = primero;
    if(ant==elim){
        ant->setSig(elim->getSig());
        delete(elim);
        contador--;
        if(contador==0)
            primero=nullptr;
    }
    else{
        while(ant->getSig() != elim){
            ant = ant->getSig();
        }
        ant->setSig(elim->getSig());
        delete(elim);
        contador--;
        if(contador==0)
            primero=nullptr;
    }
}
Libro Lista::recupera(Nodo* B){
    return B->getLibro();
}
Libro Lista::Primer(){
    Nodo* aux;
    aux = primero;
    return aux->getLibro();
}
Libro Lista::Ultimo(){
    Nodo* aux;
    aux = primero;
    while(aux->getSig()!=nullptr){
        aux = aux->getSig();
    }
    return aux->getLibro();
}
Libro Lista::Anterior(int pos){
    Nodo* aux;
    aux = primero;
    int i=2;
    while(aux!=nullptr){
        if(pos == i){
            return aux->getLibro();
        }
        aux = aux->getSig();
        i++;
    }
}
Libro Lista::Siguiente(int pos){
Nodo* aux;
    aux = primero;
    int i=0;
    while(aux!=nullptr){
        if(pos == i){
            return aux->getLibro();
        }
        aux = aux->getSig();
        i++;
    }
}
void Lista::Borra(){
    primero=nullptr;
    contador=0;
}
void Lista::setContador(int numero){
    contador=numero;
}
int Lista::getContador(){
    return contador;
}
int Lista::compararISBN(string _isbn){
    Nodo* aux;
    aux = primero;
    while(aux!=nullptr){
        if(aux->getLibro().getIsbn()==_isbn)
            return 0;
        aux = aux->getSig();
    }
    return -1;
}

