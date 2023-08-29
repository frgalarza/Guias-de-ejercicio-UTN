#include <iostream>
#include <cassert>

using namespace std;

// En un vector de 10 elementos encontrar los dos valores máximos, o sea el más grande y el que
// le siga. Cargue el vector en la declaración. Si inicializa con los datos: 6, 1, 3, 7, 9, 4, 10, 2, 8, 5
// el máximo es 10 en la posición 6 y el segundo es 9 en la posición 4
// 1. Piense que haría si fuesen 100.000 elementos y quiere los 15 más grandes (no para
// programarlo, pero si para discutir la estrategia en clase)

int posMayor(int vec[], int dim, int& posSegundo){
    int mayor{1};
    assert(dim>=2);
    if(vec[mayor]<vec[posSegundo]){
        swap(mayor, posSegundo);
    }
    for (int i = 2; i < dim; i++)
    {
        if(vec[mayor]<vec[i]){
            posSegundo = mayor;
            mayor = i;
        }
        else if(vec[posSegundo]<vec[i]){
            posSegundo = i;
        }
    }
    return mayor;
}

int main(){
    const int DIM{10};
    int vec[DIM] = {20, 21, 15, 7, 9, 4, 10, 2, 8, 5};
    int posSegundo{0};
    int posMay = posMayor(vec, DIM, posSegundo);

    cout<<"El numero mayor es: " << vec[posMay] << endl << "El segundo mayor es: " << vec[posSegundo];

    return 0;
}