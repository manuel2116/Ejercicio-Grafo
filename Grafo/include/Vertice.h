#ifndef VERTICE_H
#define VERTICE_H
#include <iostream>
#include "Arista.h"
using namespace std;

class Vertice
{
    public:
        Vertice();
        Vertice* siguiente;
        Arista* adj;
        void set_Nombre(string);
        string get_Nombre();

    protected:

    private:
        string nombre;
};

#endif // VERTICE_H
