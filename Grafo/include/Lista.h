#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "Arista.h"
#include "Vertice.h"
#include "Visitados.h"
#include "Cola.h"
#include "Pila.h"
using namespace std;


class Lista
{
    public:
        Lista();
        Vertice* ancla;
        Vertice* tope;
        void agregar(string);
        string mostrar(int);
        int retornar_Ultimo();
        void borrar(int);
        string buscar(string);
        void agregar_Arista(string, string, int);
        int mostrar_Aristas(int);
        string direccion_Arista(int, int);
        void recorrer_Cola(string);
        Cola cola;
        Visitados visitados;
        Pila pila;
        void recorrer_Pila(string);
    protected:

    private:
        int ultimo;
};

#endif // LISTA_H
