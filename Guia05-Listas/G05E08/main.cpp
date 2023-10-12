#include <iostream>
#include "listas.hpp"

using namespace std;

int mayorvalor(Nodo<int>* lista)
{
	int mayor;

	if (lista == nullptr) {
		return 0;
	} else {
		mayor = lista->dato;
		lista = lista->sig;
	}

	while (lista != nullptr) {
		if (lista->dato > mayor)
			mayor = lista->dato;
		lista = lista->sig;
	}

	return mayor;
}

Nodo<int>* mayorptr(Nodo<int>* lista)
{
	Nodo<int>* mayor = lista;

	while (lista != nullptr) {
		if (lista->dato > mayor->dato)
			mayor = lista;
		lista = lista->sig;
	}

	return mayor;
}

int main()
{
	Nodo<int> *lista = nullptr;

	// pongo datos
	agregar(lista, 1);
	agregar(lista, 3);
	agregar(lista, 12);
	agregar(lista, 5);

	cout << "Muestro Lista:" << endl;
	mostrar(lista);
	cout << "---Fin" << endl;

	cout << "El mayor valor es: " << mayorvalor(lista) << endl;
	//En la línea siguiente el riesgo es que mayorptr(lista) == nullptr
	//cout << "El mayor valor por puntero es: " << mayorptr(lista)->dato << endl;
	//Por eso y para no llamar a la función 2 veces
	Nodo<int> *maxptr = mayorptr(lista);
	cout << "El mayor valor por puntero es: " << (maxptr != nullptr ? maxptr->dato : 0) << endl;

	//libero memoria antes de finalizar
	while (lista != nullptr)
		pop(lista);
	return 0;
}
