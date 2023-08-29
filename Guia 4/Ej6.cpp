#include <iostream>
#include <fstream>

using namespace std;

// En un vector con 10 elementos enteros que tiene valores repetidos encuentre:
// 1. La posición del primer valor mínimo (recuerde: puede haber más de uno).
// 2. La posición del último valor mínimo.
// 3. Cuantas veces se repite el valor mínimo.
// Si usa el archivo datosG04E06.txt las respuestas son 2, 7 y 3. Si usa el archivo
// datosG04E06-dos.txt 5, 6 y 2 y con datosG04E06-uno.txt 6, 6 y 1

int posPrimerMinimo(int vec[], int dim, int& posUltMinimo, int& cantMinimo){
    int posPrimerMinimo{0};
    for (int i = 1; i < dim; i++)
    {
        if(vec[i]<vec[posPrimerMinimo]){
            posPrimerMinimo = i;
            posUltMinimo = i;
            cantMinimo = 1;
        }
        else if(vec[i]==vec[posPrimerMinimo]){
            posUltMinimo = i;
            cantMinimo++;
        }
    }
    return posPrimerMinimo;
}

int main(){
    const int DIM{10};
    int vec[DIM];
    int i{0};

    ifstream archilec;
    archilec.open("G04Datos/datosG04E06-uno.txt");
    if(!archilec){
        cout<<"Error al abrir archivo de lectura";
        return 1;
    }

    while (archilec >> vec[i])
    {
        i++;
    }
    

    int posUltMinimo{0}, cantMinimo{1};
    int posPrimMinimo = posPrimerMinimo(vec, DIM, posUltMinimo, cantMinimo);

    cout<<"La posicion de primer minimo es " << posPrimMinimo << endl << "La posicion del ultimo minimo es: " << posUltMinimo << endl << "Y el minimo se repite " << cantMinimo << " veces" << endl;

    archilec.close();

    return 0;
}