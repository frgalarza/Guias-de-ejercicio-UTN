#include <iostream>

using namespace std;

// Se tiene un vector de 8 elementos enteros. Sus valores deben cargarse por consola en forma
// estrictamente creciente, verificando y volviendo a pedir un valor si no cumple la condición
// (Arme una función de carga con verificación). Programe una función que encuentre, cuál es la
// máxima diferencia entre dos elementos sucesivos. Informe el valor de la misma y entre que
// elementos se produce.
// Si los datos son: 2, 4, 8, 9, 35, 40, 50, 55 la máxima diferencia es 26 y se da entre los elementos
// 3 y 4 (tomados como subíndices del arreglo, no como ordinales).

void cargaDatos(int vec[], int dim){
    cout<< "Ingrese 8 numeros enteros de forma creciente"<< endl;
    cout<< "Ingrese el entero en la posicion 0: ";
    cin>>vec[0];
    for (int i = 1; i < dim; i++)
    {
        cout<<"Ingrese el entero en la posicion "<< i << ": ";
        cin>>vec[i];
        if(vec[i]<vec[i-1]){
            i--;
        }
        
    }
}

int posMayorDif(int vec[], int dim){
    int maxDif = vec[1] - vec[0];
    int posMax = 0;
    for (int i = 1; i < dim-1; i++)
    {
        if(vec[i+1]-vec[i]>maxDif){
            maxDif = vec[i+1]-vec[i];
            posMax = i;
        }
    }
    return posMax;
}

int main(){
    const int DIM = 8;
    int vec[DIM];
    cargaDatos(vec, DIM);
    int indexMaxDif = posMayorDif(vec, DIM);

    cout<<"La mayor diferencia es de " << vec[indexMaxDif+1] - vec[indexMaxDif] << " y se da entre " << vec[indexMaxDif+1] << " y " << vec[indexMaxDif];

    return 0;
}