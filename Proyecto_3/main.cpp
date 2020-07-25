#include <iostream>
#include "Lista.h"
#include "Libro.h"
#include <windows.h>

using namespace std;

int main()
{
    int opc,res,numero;
    string nombre,autor,isbn,editorial,categoria;
    Lista l;
    do{
    system("cls");
    opc=l.menuPrincipal();
    switch(opc){
        case 1:{
            system("cls");
            cout<<"\t\tAGREGAR"<<endl;
            cout<<"_______________________________________"<<endl;
            cin.ignore();
            cout<<"Ingresa el Nombre: "<<endl;
            getline(cin,nombre);
            cout<<"Ingresa el Autor: "<<endl;
            getline(cin,autor);
            cout<<"Ingresa el ISBN: "<<endl;
            getline(cin,isbn);
            res=l.compararISBN(isbn);
            if(res!=-1){
                cout<<"ISBN YA EXISTENTE"<<endl;
                Sleep(1000);
                break;
            }
            else{
                cout<<"Ingresa la Categoria: "<<endl;
                getline(cin,categoria);
                cout<<"Ingresa el Editorial: "<<endl;
                getline(cin,editorial);
                cout<<"Ingresa la Exitencia: "<<endl;
                cin>>numero;
                Libro B(nombre,autor,isbn,categoria,editorial,numero);
                l.insertaFinal(B);
                cout<<"LIBRO AGREGADO CON EXITO"<<endl;
                Sleep(1000);
                break;
            }
        }
        case 2:{
            system("cls");
            cout<<"\t\tVACIA"<<endl;
            cout<<"_______________________________________"<<endl;
            res=l.Vacia();
            if(res==0){
                cout<<"LISTA VACIA"<<endl;
                Sleep(1000);
                break;
            }
            else{
                cout<<"LISTA NO VACIA"<<endl;
                Sleep(1000);
                break;
            }
        }
        case 3:{
            system("cls");
            cout<<"\t\tELIMINAR"<<endl;
            cout<<"_______________________________________"<<endl;
            if (l.Vacia()== 0) {
                cout<<"LISTA VACIA"<<endl;
                Sleep(1000);
                break;
            }
            else{
                cout<<"Escriba ISBN a Eliminar: "<<endl;
                cin>>isbn;
                l.elimina(l.localiza(isbn));
                Sleep(1000);
                break;
            }
        }
        case 4:{
            system("cls");
            cout<<"\tMOSTRAR EL PRIMER LIBRO"<<endl;
            cout<<"_______________________________________"<<endl;
            if (l.Vacia()== 0) {
                cout<<"LISTA VACIA"<<endl;
                Sleep(1000);
                break;
            }
            else{
                cout<<"Primer Libro: "<<l.Primer().toString()<<endl;
                Sleep(1000);
                break;
            }
        }
        case 5:{
            system("cls");
            cout<<"\tMOSTRAR EL ULTIMO LIBRO"<<endl;
            cout<<"_______________________________________"<<endl;
            if (l.Vacia()== 0) {
                cout<<"LISTA VACIA"<<endl;
                Sleep(1000);
                break;
            }
            else{
                cout<<"Ultimo Libro: "<<l.Ultimo().toString()<<endl;
                Sleep(1000);
                break;
            }
        }
        case 6:{
            int pos;
            system("cls");
            cout<<"\tMOSTRAR EL LIBRO ANTERIOR"<<endl;
            cout<<"_______________________________________"<<endl;
            if (l.Vacia()== 0) {
                cout<<"LISTA VACIA"<<endl;
                Sleep(1000);
                break;
            }
            else{
                cout<<"Escriba Pocision a Mostrar: "<<endl;
                cin>>pos;
                if(pos<=1||pos>l.getContador()){
                    cout<<"Valor No Valido"<<endl;
                    Sleep(1000);
                    break;
                }
                else{
                   cout<<"Libro Anterior: "<<l.Anterior(pos).toString()<<endl;
                    Sleep(1000);
                    break;
                }
            }
        }
        case 7:{
            int pos;
            system("cls");
            cout<<"\tMOSTRAR EL LIBRO SIGUIENTE"<<endl;
            cout<<"_______________________________________"<<endl;
            if (l.Vacia()== 0) {
                cout<<"LISTA VACIA"<<endl;
                Sleep(1000);
                break;
            }
            else{
                cout<<"Escriba Pocision a Mostrar: "<<endl;
                cin>>pos;
                if(pos<=0||pos>=l.getContador()){
                    cout<<"Valor No Valido"<<endl;
                    Sleep(1000);
                    break;
                }
                else{
                   cout<<"Libro Siguiente: "<<l.Siguiente(pos).toString()<<endl;
                    Sleep(1000);
                    break;
                }
            }
        }
        case 8:{
            system("cls");
            cout<<"\tMOSTRAR FICHA DE LIBRO"<<endl;
            cout<<"_______________________________________"<<endl;
            if (l.Vacia()== 0) {
                cout<<"LISTA VACIA"<<endl;
                Sleep(1000);
                break;
            }
            else{
                cout<<"Escriba ISBN a Mostrar: "<<endl;
                cin>>isbn;
                res=l.compararISBN(isbn);
                if(res==-1){
                    cout<<"ISBN Inexistente"<<endl;
                    Sleep(1000);
                    break;
                }
                else{
                    cout<<l.recupera(l.localiza(isbn)).toString()<<endl;
                    Sleep(1000);
                    break;
                }
            }
        }
        case 9:{
            system("cls");
            cout<<"\t\tCATALOGO"<<endl;
            cout<<"_______________________________________"<<endl;
            l.mostrarTodos();
            system("pause");
            break;
        }
        case 10:{
            system("cls");
            cout<<"\t\tBorrar Todo"<<endl;
            cout<<"_______________________________________"<<endl;
            l.Borra();
            break;
        }
        case 0:{
            system("cls");
            cout<<"\t\tCERRANDO"<<endl;
            cout<<"_______________________________________"<<endl;
            break;
        }
    }
    }while(opc!=0);

    return 0;
}
