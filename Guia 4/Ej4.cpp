#include <iostream>

using namespace std;

// . Dado un vector de 10 enteros inicializado con datos al definirlo, programe una función que
// permita encontrar la posición del valor máximo. Usarla para informar cuál es el máximo y en
// que posición del vector se encuentra. 

int buscarPosMax(int vec[], int dim){
    int posMax = 0, max = vec[0];

    for (int i = 1; i < dim; i++)
    {
        if(vec[i]>max){
            max = vec[i];
            posMax = i;
        }
    }

    return posMax;
    
}

int main(){
    const int dim = 10;
    int vectorNums[dim] = {23, 34, 12, 9, 234, 22, 123, 45, 4, 10};
    
    int posMax = buscarPosMax(vectorNums, dim);

    cout<< "El valor maximo es: " << vectorNums[posMax] << " y se encuentra en la posicion: " << posMax;
    return 0;
}