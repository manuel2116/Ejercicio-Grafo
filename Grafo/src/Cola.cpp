#include "Cola.h"
#include <iostream>
using namespace std;
Cola::Cola()
{
    inicio=nullptr;
}

void Cola::inicializar()
{
    inicio=nullptr;
}

void Cola::encolar(Vertice* elemento)
{
    Nodo_vertice* nuevo=new Nodo_vertice();
    Nodo_vertice* aux;
    nuevo->datos=elemento;
    aux=inicio;
    if(aux==nullptr)
    {
        nuevo->next=nullptr;
        inicio=nuevo;

    }
    else
    {
        while(aux->next!=nullptr)
        {
            aux=aux->next;
        }
        aux->next=nuevo;
        nuevo->next=nullptr;
    }
}


Vertice* Cola::desencolar()
{
    if(inicio==nullptr)
    {
        cout<<"No se puede desencolar"<<endl;
        return nullptr;
    }
    else
    {
        Nodo_vertice* aux;
        aux=inicio;
        if(inicio->next!=nullptr)
        {
            inicio=inicio->next;
            return aux->datos;
        }
        else
        {
            inicio=nullptr;
            return aux->datos;
        }
    }
}

bool Cola::vacia()
{
    if(inicio==nullptr)
    {
        return true;
    }
    return false;
}
