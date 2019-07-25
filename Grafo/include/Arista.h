#ifndef ARISTA_H
#define ARISTA_H
#include <iostream>
using namespace std;

class Vertice;
class Arista
{
    public:
        Arista();
        Arista* sig;
        Vertice* direccion;
        void set_Costo(int);
        int get_Costo();

    protected:

    private:
        int costo;
};

#endif // ARISTA_H
