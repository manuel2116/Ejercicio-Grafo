#include <iostream>
#include "Lista.h"
#include <windows.h>
#include <ctype.h>
#include "Cola.h"
using namespace std;

int main()
{
    Lista dao;
    int opc, resp, cost;
    string name, origen, destino;
    do
    {
        cout<<"Ingresar una opcion valida\n(1)agregar vertice\n(2)Mostrar los vertices\n(3)borrar vertice\n(4)buscar vertice\n(5)agregar arista"<<endl;
        cout<<"(6)Mostrar las aristas de un vertice\n(7)Mostar origen y destino de un arista\n(8)recorrer por anchura\n(9)Recorrer en profundidad\n(10)salir"<<endl;
        cin>>opc;
        switch (opc)
        {
        case 1:
            cout<<"Ingresa el nombre del nuevo vertice"<<endl;
            cin>>name;
            dao.agregar(name);
            break;
        case 2:
            if (dao.retornar_Ultimo()<1)
            {
                cout<<"NO hay vertices que mostrar"<<endl;

            }
            else
            {
                for(int i=0; i<dao.retornar_Ultimo(); i++)
                {
                    cout<<"vertice "<<i+1<<": "<<dao.mostrar(i)<<endl;
                }
            }
            break;
        case 3:
            cout<<"ingrese el vertice a borrar"<<endl;
            cin>>resp;
            if(resp<1 || resp>dao.retornar_Ultimo())
            {
                cout<<"NO existe el vertice"<<endl;
            }
            else
            {
                name=dao.mostrar(resp-1);
                dao.borrar(resp-1);
                cout<<"Se ha borrado el vertice: "<<name<<endl;
            }
        case 4:
            if(dao.retornar_Ultimo()<1)
            {
                cout<<"NO existen vertices"<<endl;
            }
            else
            {
                cout<<"Ingresa el nombre del vertice para buscarlo"<<endl;
                cin>>name;
                if(dao.buscar(name)=="no")
                {
                    cout<<"No existe ese vertice"<<endl;
                }
                else
                {
                    cout<<"Vertice encontrado : "<<dao.buscar(name)<<endl;
                }

            }
            break;
        case 5:
            if(dao.retornar_Ultimo()<1)
            {
                cout<<"NO existen vertices para agregar una arista"<<endl;
            }
            else if(dao.retornar_Ultimo()==1)
            {
                cout<<"Solo existe un vertice y no se permiten lazos"<<endl;
            }
            else
            {
                cout<<"Ingresa el vertice de origen"<<endl;
                cin>>origen;
                if(dao.buscar(origen)=="no")
                {
                    cout<<"NO existe ese vertice"<<endl;
                }
                else
                {
                    cout<<"Ingresa el vertice destino"<<endl;
                    cin>>destino;
                    if(dao.buscar(destino)=="no")
                    {
                        cout<<"NO existe ese vertice"<<endl;
                    }
                    else if(origen==destino)
                    {
                        cout<<"No se permiten lazos"<<endl;
                    }
                    else
                    {
                        cout<<"Ingresa el costo"<<endl;
                        cin>>cost;
                        dao.agregar_Arista(origen, destino, cost);
                        cout<<"Se agrego una arista del vertice "<<origen<<" hacia el vertice "<<destino<<" con un costo de "<<cost<<endl;
                    }
                }
            }
            break;
        case 6:
            if(dao.retornar_Ultimo()<1)
            {
                cout<<"NO hay vertices por lo que no se pueden mostar sus aristas"<<endl;

            }
            else
            {
                cout<<"Ingresa el vertice"<<endl;
                cin>>resp;
                if(resp<1 || resp>dao.retornar_Ultimo())
                {
                    cout<<"NO existe ese vertice"<<endl;
                }
                else
                {
                    cout<<"El vertice "<<resp<<" tiene "<<dao.mostrar_Aristas(resp-1)<<" aristas"<<endl;

                }
            }
            break;
        case 7:
            if(dao.retornar_Ultimo()<1)
            {
                cout<<"NO existen vertices"<<endl;
            }
            else
            {
                cout<<"Ingresa el vertice donde se encuentra la arista"<<endl;
                cin>>cost;
                if(cost<1 || cost>dao.retornar_Ultimo())
                {
                    cout<<"No existe ese vertice"<<endl;
                }
                else
                {
                    cout<<"El vertice "<<cost<<" tiene "<<dao.mostrar_Aristas(cost-1)<<" aristas"<<endl;
                    cout<<"Ingresa el numero de arista"<<endl;
                    cin>>resp;
                    if(resp<1 || resp>dao.mostrar_Aristas(cost-1))
                    {
                        cout<<"No existe esa arista"<<endl;
                    }
                    else
                    {
                        cout<<"la arista "<<resp<<" apunta al verice "<<dao.direccion_Arista(cost-1, resp-1)<<endl;
                    }
                }
            }
            break;
        case 8:
            if(dao.retornar_Ultimo()<2)
            {
                cout<<"no hay vertices o hay solo uno"<<endl;
            }
            else
            {
                cout<<"Ingresa el vertice origen"<<endl;
                cin>>name;
                if(dao.buscar(name)=="no")
                {
                    cout<<"No existe ese vertice"<<endl;
                }
                else
                {
                    cout<<"1"<<endl;
                    dao.recorrer_Cola(name);

                }


            }
            break;
        case 9:
            if(dao.retornar_Ultimo()<2)
            {
                cout<<"no existen vertices o solo hay uno"<<endl;
            }
            else
            {
                cout<<"Ingresa el vertice"<<endl;
                cin>>name;
                if(dao.buscar(name)=="no")
                {
                    cout<<"NO existe ese vertice"<<endl;
                }
                else
                {
                    dao.recorrer_Pila(name);
                }
            }
            break;
        case 10:
            cout<<"Hasta pronto"<<endl;

        break;
        default:
            cout<<"Opcion invalida"<<endl;
        }
        system("pause");
        system("cls");
    }while(opc!=10);

    return 0;
}
