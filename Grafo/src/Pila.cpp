#include "Pila.h"

Pila::Pila()
{
    inicio=nullptr;
}
void Pila::inicializar()
{
    inicio=nullptr;
}
bool Pila::vacia()
{
    if(inicio==nullptr)
    {
        return true;
    }
    return false;
}

void Pila::apilar(Vertice* elemento)
{
    Nodo_vertice* nuevo=new Nodo_vertice();
    Nodo_vertice* aux;
    aux=inicio;
    nuevo->datos=elemento;
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

Vertice* Pila::desapilar()
{
    Nodo_vertice* aux;
    aux=inicio;
    Nodo_vertice* aux2;
    aux2=inicio;
    if(aux->next==nullptr)
    {
        inicio=nullptr;
        return aux->datos;
    }
    else
    {
        while(aux->next!=nullptr)
        {
            aux=aux->next;
        }
        while(aux2->next!=aux)
        {
            aux2=aux2->next;
        }
        aux2->next=nullptr;
        return aux->datos;
    }
}
