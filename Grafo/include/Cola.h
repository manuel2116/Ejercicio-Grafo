#ifndef COLA_H
#define COLA_H
#include "Visitados.h"
#include <iostream>
#include "Nodo_vertice.h"
using namespace std;
class Lista;
class Cola
{
    public:
        Cola();
        Nodo_vertice* inicio;
        void inicializar();
        void encolar(Vertice*);
        Vertice* desencolar();
        bool vacia();

    protected:

    private:

};

#endif // COLA_H
