#include <iostream>

using namespace std;


// Armar un vector con 10 valores enteros en la inicialización. Hallar la sumatoria de los valores.
// Si prueba con los pares comenzando en 2, la suma debe dar 110.
int main(){
    const int dim = 10;
    int vec[dim] = {2, 4, 6 ,8, 10 ,12, 14, 16, 18, 20};
    int suma{};

    for (int i = 0; i < dim; i++)
    {
        suma += vec[i];
    }
    
    cout<<"La sumatoria total es: " << suma;
    return 0;
}