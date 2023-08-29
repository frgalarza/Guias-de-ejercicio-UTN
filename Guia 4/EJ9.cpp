#include <iostream>

using namespace std;

// ingrese en un vector 10 enteros. Muéstrelos en el orden ingresado. Ordénelos en forma
// ascendente y muéstrelos ordenados.

void mostrar(int vec[], int dim){
    for (int i = 0; i < dim; i++)
    {
        cout<<"Posicion " << i << ": " << vec[i] << endl;
    } 
}

void ordenarAsc(int vec[], int dim){
    //int aux{0};
    for (int i = 0; i < dim; i++)
    {
        for (int j = i+1; j < dim; j++)
        {
            if(vec[i]>vec[j]){
                // aux = vec[j];
                // vec[j] = vec[i];
                // vec[i] = aux;
                swap(vec[j], vec[i]);
            }
        }
        
    }
    
}

int main(){
    const int DIM{10};
    int vec[DIM];

    cout<<"Ingrese los datos en el arreglo" <<endl;
    for (int i = 0; i < DIM; i++)
    {
        cout<<"Ingrese el valor en la posicion " << i << ": ";
        cin>>vec[i];
    }

    mostrar(vec, DIM);
    ordenarAsc(vec, DIM);
    mostrar(vec, DIM);
    

    return 0;
}