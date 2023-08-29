#include <iostream>

using namespace std;

// Se pide ingresar por teclado 8 valores que se cargarán en un vector, pero se controlará que
// todos los valores sean distintos. Si el valor ingresado ya se encuentra en los cargados
// previamente, vuelva a solicitar el valor para esa posición.

bool incluido(int vec[], int dim, int valor){
    for (int i = 0; i < dim; i++)
    {
        if(vec[i] == valor) return true;
    }
    return false;
}

void cargarDatos(int vec[], int dim){
    int valorIngresar = 0;
    for (int i = 0; i < dim; i++)
    {
        cout<<"Ingrese el valor en la posicion " << i << ": ";
        cin>> valorIngresar;
        if(incluido(vec, dim, valorIngresar)){
            i--;
        }
        else {
            vec[i] = valorIngresar;
        }
    }
    
}

int main(){
    const int DIM{8};
    int vec[DIM];
    cargarDatos(vec, DIM);

    return 0;
}