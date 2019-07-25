#ifndef PILA_H
#define PILA_H
#include <iostream>
#include "Nodo_vertice.h"
using namespace std;

class Lista;
class Pila
{
    public:
        Pila();
        Nodo_vertice* inicio;
        void inicializar();
        void apilar(Vertice*);
        Vertice* desapilar();
        bool vacia();

    protected:

    private:
};

#endif // PILA_H
