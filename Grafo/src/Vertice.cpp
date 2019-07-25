#include "Vertice.h"

Vertice::Vertice()
{
    siguiente= nullptr;
    adj=nullptr;
}

void Vertice::set_Nombre(string nombre)
{
    this->nombre=nombre;
}
string Vertice::get_Nombre()
{
    return nombre;
}
