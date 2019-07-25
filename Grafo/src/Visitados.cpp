#include "Visitados.h"

Visitados::Visitados()
{
    inicio=nullptr;
}

void Visitados::inicializar()
{
    inicio=nullptr;
}


void Visitados::agregar(Vertice* elemento)
{
    Nodo_vertice* nuevo=new Nodo_vertice();
    Nodo_vertice* aux;
    nuevo->datos=elemento;
    aux=inicio;
    if(aux==nullptr)
    {
        inicio=nuevo;
        nuevo->next=nullptr;
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


bool Visitados::buscar(Vertice* elemento)
{
    Nodo_vertice* aux;
    aux=inicio;
    bool bandera=false;
    if(aux==nullptr)
    {
        return bandera;
    }
    else
    {
        while(aux->next!=nullptr)
        {
            if(aux->datos==elemento)
            {
                bandera=true;
            }
            aux=aux->next;
        }
        return bandera;
    }
}
