#include <iostream>
#include <fstream>
#include "listasutil.hpp"
#include "listasord.hpp"
#include "rwstring.hpp"

using namespace std;

const int lcliente { 8 };

struct Deuda{
    string cliente;
    int mes;
    int cantdeud;
};

ostream& operator << (ostream &os, const Deuda& deuda)
{  
	os << deuda.cliente << " - mes: " << deuda.mes
	   << " - cant: " << deuda.cantdeud;
	return os;
}

fstream& operator >> (fstream &fs, Deuda &deuda){
    deuda.cliente = readstring(fs, lcliente);
    fs.read(reinterpret_cast<char *>(&deuda.mes), sizeof(deuda.mes));
    fs.read(reinterpret_cast<char *>(&deuda.cantdeud), sizeof(deuda.cantdeud));
    return fs;
}

int crit_cliente(Deuda a, Deuda b){
    if(a.cliente == b.cliente) return a.mes - b.mes;
    else return a.cliente > b.cliente ? 1 : -1;
}

template <typename T> void borrarsig(Nodo<T>*& lista){
    Nodo<T>* aux;

    aux = lista->sig->sig;
    delete lista->sig;
    lista->sig = aux;
}

void consolidar(Nodo<Deuda>* actual){
    while (actual)
    {
        while (actual->sig && crit_cliente(actual->dato, actual->sig->dato) == 0)
        {
        actual->dato.cantdeud += actual->sig->dato.cantdeud;
        borrarsig(actual);
        }
        actual = actual->sig;
    }
}

int main(){
    Nodo<Deuda>* lista = nullptr;
    Deuda deuda;

    fstream archivo;
    archivo.open("G06-Datos/G06E03.bin", ios::binary | ios::in);
    if(!archivo){
        cout<<"Error al abrir G06E03.bin";
        return EXIT_FAILURE;
    }

    while (archivo >> deuda)
    {
        insertar(deuda, lista, crit_cliente);
    }

    archivo.close();

    cout<<"\nLista al leer el archivo: " << endl;
    mostrar(lista);

    consolidar(lista);

    cout<< endl << endl << "Lista consolidada: " << endl;
    mostrar(lista);

    return 0;
}

