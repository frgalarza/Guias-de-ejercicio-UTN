#include <iostream>

using namespace std;

// Defina y de valores a una matriz de enteros de 5 filas y 4 columnas. Llame a una función que
// acepte matrices de tipo entero con 4 columnas (cantidad de filas a pasar como parámetro) y
// devuelva en que fila y columna se encuentra el menor elemento de la matriz.

int posMenor(int mat[5][4], int& posMenorCol){
    const int FILAS{5}, COL{4};
    int menor = mat[0][0];
    int posMenorFila{0};
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (menor>mat[i][j])
            {
                menor = mat[i][j];
                posMenorFila = i;
                posMenorCol = j;
            }
            
        }
        
    }
    return posMenorFila;
}

int main(){
    const int FILAS{5}, COL{4};
    int mat[FILAS][COL] = {{768, 656, 234, 546},
                            {567, 634, 334, 623},
                            {467, 67, 78, 626},
                            {98, 546, 234, 435},
                            {78, 689, 567, 567},
    };
    int posMenorCol{0};
    int posMenorFila = posMenor(mat, posMenorCol);

    cout<<"El menor de los enteros dentro de la matriz es: " << mat[posMenorFila][posMenorCol] << endl << "Se encuentra en la fila " << posMenorFila << " y columna " <<  posMenorCol;

    return 0;
}