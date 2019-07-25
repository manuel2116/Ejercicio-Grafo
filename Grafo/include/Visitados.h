#ifndef VISITADOS_H
#define VISITADOS_H
#include "Nodo_vertice.h"

class Visitados
{
    public:
        Visitados();
        Nodo_vertice* inicio;
        void agregar(Vertice*);
        void inicializar();
        bool buscar(Vertice*);

    protected:

    private:
};

#endif // VISITADOS_H
