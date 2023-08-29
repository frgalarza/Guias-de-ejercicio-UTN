#include <iostream>
#include <fstream>

using namespace std;

// Cargar un vector con los promedios anuales (pueden tener decimales) de las notas de 10
// alumnos. Informe el promedio de todas esas notas (calculado por una función) y cuantos
// alumnos estuvieron por encima del promedio (calculado por otra función). Si lee del archivo
// datosG04E03.txt el promedio es 7,792 y la cantidad de alumnos que superan el promedio es 5

double promNotas(double vec[], int dim){
    double suma{0};

    for (int i = 0; i < dim; i++)
    {
        suma+=vec[i];
    }

    double prom = suma/dim;

    return prom;
    
}

int alumnosSup(double vec[], int dim, double prom){
    int cant{0};

    for (int i = 0; i < dim; i++)
    {
        if(vec[i]>prom) cant++;
    }
    
    return cant;
}

int main(){
    const int dim = 10;
    double vecNotas[dim];
    ifstream archilec;
    archilec.open("G04Datos/datosG04E03.txt");

    if(!archilec){
        cout<<"Error al abrir el archivo de datos";
        return 1;
    }

    int i{0};

    while(archilec >> vecNotas[i]){
        i++;
    }

    archilec.close();

    double prom = promNotas(vecNotas, dim);

    cout<<"El promedio de las notas es: " << prom << endl << "Y la cantidad de alumnos que supera el promedio es: "<< alumnosSup(vecNotas, dim, prom);

    return 0;
}