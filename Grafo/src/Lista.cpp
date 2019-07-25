#include "Lista.h"
#include <iostream>
using namespace std;

Lista::Lista()
{
    ancla=nullptr;
    tope=nullptr;
    ultimo=0;
}

void Lista::agregar(string name)
{
    Vertice* nuevo=new Vertice();
    Vertice* aux;
    nuevo->set_Nombre(name);
    if(ancla==nullptr)
    {
        nuevo->siguiente=nullptr;
        nuevo->adj=nullptr;
        ancla=nuevo;
        tope=nuevo;
    }
    else
    {
        aux=ancla;
        while(aux->siguiente!=nullptr)
        {
            aux=aux->siguiente;
        }
        aux->siguiente=nuevo;
        nuevo->siguiente=nullptr;
        nuevo->adj=nullptr;
        tope=nuevo;
    }
    ultimo++;
}

string Lista::mostrar(int n)
{
    Vertice* aux;
    aux=ancla;
    int i=0;
    while(i<n)
    {
        aux=aux->siguiente;
        i++;
    }
    return aux->get_Nombre();
}


void Lista::borrar(int n)
{
    Vertice* aux;
    aux=ancla;
    int i=0;
    while(i<n)
    {
        aux=aux->siguiente;
        i++;
    }
    if(aux==ancla && aux==tope)
    {
        ancla=nullptr;
        tope=nullptr;
    }
    else if(aux==ancla)
    {
        ancla=aux->siguiente;
    }
    else if(aux==tope)
    {
        i=0;
        while(i<n-1)
        {
            aux=aux->siguiente;

        }
        aux->siguiente=nullptr;
        tope=aux;
    }
    else
    {
        Vertice* aux2;
        aux=ancla;
        aux2=ancla;
        i=0;
        cout<<"1"<<endl;
        while(i<n-1)
        {
            cout<<"2"<<endl;
            aux=aux->siguiente;
            i++;
        }
        i=0;
        while(i<n+1)
        {
            cout<<"3"<<endl;
            aux2=aux2->siguiente;
            i++;
        }
        aux->siguiente=aux2;


    }

    ultimo --;
}

string Lista::buscar(string name)
{
    Vertice* aux;
    aux=ancla;
    for(int i=0; i<ultimo; i++)
    {
        if(aux->get_Nombre()==name)
        {
            return name;
        }
        aux=aux->siguiente;
    }
    return "no";
}


void Lista::agregar_Arista(string n, string m, int valor)
{
    Vertice* origen;
    Vertice* destino;
    origen=ancla;
    destino=ancla;
    int i=0;
    while(origen->siguiente!=nullptr)
    {
        if(origen->get_Nombre()==n)
        {
            break;
        }
        origen=origen->siguiente;
    }
    while(destino->siguiente!=nullptr)
    {
        if(destino->get_Nombre()==m)
        {
            break;
        }
        destino=destino->siguiente;
    }
    Arista* nuevo=new Arista();
    Arista* aux;
    aux=origen->adj;
    if(aux==nullptr)
    {
        origen->adj=nuevo;
        nuevo->sig=nullptr;
        nuevo->direccion=destino;
    }
    else
    {
        while(aux->sig!=nullptr)
        {
            aux=aux->sig;
        }
        aux->sig=nuevo;
        nuevo->sig=nullptr;
        nuevo->direccion=destino;
    }
    nuevo->set_Costo(valor);


}

int Lista::mostrar_Aristas(int n)
{
    Vertice* aux_Vertice;
    aux_Vertice=ancla;
    Arista* aux_Arista;
    aux_Arista=aux_Vertice->adj;
    int contador=0;
    int i=0;
    while(i<n)
    {
        aux_Vertice=aux_Vertice->siguiente;
        i++;
    }
    if(aux_Arista==nullptr)
    {
        return 0;
    }
    else
    {
        while(aux_Arista!=nullptr)
        {
            aux_Arista=aux_Arista->sig;
            contador++;
        }
        return contador;
    }
}

string Lista::direccion_Arista(int n, int m)
{
    Vertice* aux_Vertice;
    aux_Vertice=ancla;
    Arista* aux_Arista;
    int i=0;
    while(i<n)
    {
        aux_Vertice=aux_Vertice->siguiente;
        i++;
    }
    i=0;
    aux_Arista=aux_Vertice->adj;
    while(i<m)
    {
        aux_Arista=aux_Arista->sig;
    }
    aux_Vertice=aux_Arista->direccion;
    return aux_Vertice->get_Nombre();

}


int Lista::retornar_Ultimo()
{
    return ultimo;
}



void Lista::recorrer_Cola(string name)
{
    cola.inicializar();
    visitados.inicializar();
    Vertice* origen;
    origen=ancla;
    bool band=false;
    for(int i=0; i<ultimo; i++)
    {
        if(name==origen->get_Nombre())
        {
            band=true;
            break;
        }
        else
        {
            origen=origen->siguiente;
        }
    }
    if (band)
    {
        Vertice* aux;
        Arista* aux_A;
        aux=origen;
        cola.encolar(origen);
        while(cola.vacia()==false)
        {
            aux=cola.desencolar();
            aux_A=aux->adj;
            if(visitados.buscar(aux)==false)
            {
                cout<<aux->get_Nombre()<<", "<<endl;
                visitados.agregar(aux);
            }
            while(aux_A!=nullptr)
            {
                if(visitados.buscar(aux_A->direccion)==false)
                {
                    cola.encolar(aux_A->direccion);
                }
                aux_A=aux_A->sig;

            }

        }

    }
    else
    {
        cout<<"No existe el vertice"<<endl;
    }

}


void Lista::recorrer_Pila(string name)
{
    pila.inicializar();
    visitados.inicializar();
    Vertice* origen;
    origen=ancla;
    Vertice* aux;
    Arista* aux_A;
    while(origen->siguiente!=nullptr)
    {
        if(origen->get_Nombre()==name)
        {
            break;
        }
        origen=origen->siguiente;
    }
    pila.apilar(origen);
    while(pila.vacia()==false)
    {
        aux=pila.desapilar();
        aux_A=aux->adj;
        if(visitados.buscar(aux)==false)
        {
            cout<<aux->get_Nombre()<<", "<<endl;
            visitados.agregar(aux);
        }
        while(aux_A->sig!=nullptr)
        {
            if(visitados.buscar(aux_A->direccion)==false)
            {
                pila.apilar(aux_A->direccion);
            }
            aux_A=aux_A->sig;
        }
    }
}
