#include "Arista.h"

Arista::Arista()
{
    sig=nullptr;
    direccion=nullptr;
}

void Arista::set_Costo(int costo)
{
    this->costo=costo;
}
int Arista::get_Costo()
{
    return costo;
}
