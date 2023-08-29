#include <iostream>

using namespace std;

// Defina y de valores a una matriz de doubles de 4 filas y 3 columnas. Llame a una función que
// acepte matrices de tipo double y con exactamente 4 filas y 3 columnas, que devuelva el
// promedio de los elementos en la matriz.

double promedio(double vec[][3], int filas){
    const int col{3};
    double sum{0};
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += vec[i][j];
        }
        
    }
    double promedio = (sum != 0) ? sum/double(filas*col) : 0;
    
    return promedio;
}

int main(){
    const int FILAS{4}, COL{3};
    double vec[FILAS][COL] = {
                                {2.5, 3.3, 5},
                                {6.7, 8.9, 10},
                                {2.3, 7.2, 8.1},
                                {1.2, 5.2, 2.1}
    };

    cout<<"El promedio de los elementos de la matriz es: " << promedio(vec, FILAS);

    return 0;
}