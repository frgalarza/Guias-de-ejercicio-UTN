#include <iostream>
#include <fstream>
#include "listasutil.hpp"
#include "listasord.hpp"
#include "rwstring.hpp"

using namespace std;

const int lcli {8}, lprod {10};

struct Ordencomp
{
    int id;
    string cliente;
    string producto;
    int cant;
};

// template <typename T>
// struct Nodo
// {
//     T dato;
//     Nodo<T>* sig;
// };

string readstring(fstream &fs, int largo)
{
    char *buffer = new char[largo + 1];
    buffer[largo] = '\0';
    fs.read(buffer, largo);
    string str(buffer);
    delete[] buffer;
    return str;
}

void writestring(fstream &fs, string str, int largo)
{
	str.resize(largo);
	fs.write(str.data(), largo);
}

ostream& operator << (ostream &os, const Ordencomp& ord)
{
	os << "id: " << ord.id << " - " << ord.cliente << " - " << ord.producto
	   << " - cant " << ord.cant;
	return os;
}

fstream& operator << (fstream &fs, const Ordencomp& ord)
{
	fs.write(reinterpret_cast<const char *>(&ord.id), sizeof(ord.id));
	writestring(fs, ord.cliente, lclie);
	writestring(fs, ord.producto, lprod);
	fs.write(reinterpret_cast<const char *>(&ord.cant), sizeof(ord.cant));
	return fs;
}

fstream& operator >> (fstream &fs, Ordencomp& ord)
{
	fs.read(reinterpret_cast<char *>(&ord.id), sizeof(ord.id));
	ord.cliente = readstring(fs, lclie);
	ord.producto = readstring(fs, lprod);
	fs.read(reinterpret_cast<char *>(&ord.cant), sizeof(ord.cant));
	return fs;
}

int criterio_id(Ordencomp a, Ordencomp b){
    return a.id - b.id;
}

int critclieprod (Ordencomp a, Ordencomp b)
{
	if (a.cliente == b.cliente)
		return a.producto.compare(b.producto);
	else
		return a.cliente > b.cliente ? 1 : -1;
}

int main(){
    Nodo<Ordencomp> *listaid = nullptr;
    Nodo<Ordencomp> *listaord = nullptr;
    Ordencomp orden;

    fstream archivo;
    archivo.open("G06-Datos/G06E02.bin", ios::binary | ios::int);
    if(!archivo){
        cout<< "Error al abrir archivo de datos binarios";
        return 1;
    }

    while (archi >> orden) {
		insertar(orden, listaid, critid);
		insertar(orden, listaord, critclieprod);
	}

    int id;
    cout<<"Ingrese el id de la orden de compra que busca: ";
    Nodo<Ordencomp>* pord; 
    cin>>orden.id;
    while (orden.id > 0)
    {
        pord = buscar(orden, listaid, criterio_id);
        if(!pord){
            cout<<"No existe orden con el id: " << orden.id;
        }
        else mostrar(pord);
        cout<<"\nIngrese el id de la orden de compra que busca: ";
        cin>>orden.id;
    }

    cout<<"Ingrese el nombre del cliente a eliminar: ";
    cin>>orden.cliente;
    cout<<"Ingrese el nombre del producto a eliminar: ";
    cin>>orden.producto;
    Nodo<Ordencomp>* pord2;
    
    while (pord2 != extraer(orden, listaord, critclieprod))
    {
        orden.id = pord->dato.id;
        delete pord;
        if(!borrar())
    }
    
    
}

