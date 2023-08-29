#include <iostream>

using namespace std;

// Se tiene un vector de 8 elementos enteros. Sus valores deben cargarse por consola en forma
// estrictamente creciente, verificando y volviendo a pedir un valor si no cumple la condición
// (Arme una función de carga con verificación). Programe una función que encuentre, cuál es la
// máxima diferencia entre dos elementos sucesivos. Informe el valor de la misma y entre que
// elementos se produce.
// Si los datos son: 2, 4, 8, 9, 35, 40, 50, 55 la máxima diferencia es 26 y se da entre los elementos
// 3 y 4 (tomados como subíndices del arreglo, no como ordinales).

void cargarDatos(int vec[], int dim){
    int i{0};
    for (int j = 0; j < dim; j++)
    {
        do{
            cout<<"Ingrese el valor de la posicion " << i << " : " ;
            cin>>vec[i];
            if (vec[i]>vec[i-1]){
                i++;
            }
        
        } while (vec[i]<vec[i-1]);
        cout<<"j es: " << j << endl;
    }
}

int maxDif(int vec[], int dim, int& posMaxDif){
    int i{1};
    int maxDif = vec[i] - vec[i-1];
    for (i=2; i < dim; i++)
    {
        if (maxDif < vec[i] - vec[i-1])
        {
            maxDif = vec[i] - vec[i-1];
            posMaxDif= i;
        }
    }
    
    return maxDif;
}

int main(){
    const int dim = 8;
    int vector[dim], posMaxDif;

    cout<<"Ingrese los numeros de forma creciente"<< endl;
    cargarDatos(vector, dim);
    int maxDifVec = maxDif(vector, dim, posMaxDif);

    cout<<"La maxima diferencia es: " << maxDifVec << " Y se produce entre los elementos " << vector[posMaxDif] << " y " << vector[posMaxDif-1];

    return 0;
}
