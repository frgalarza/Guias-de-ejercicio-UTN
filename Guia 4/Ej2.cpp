#include <iostream>
#include <fstream>

using namespace std;

double calcPromCondicion(double vec[], int dim, int condicion){
    double suma = 0, cantCumple = 0;

    for (int i = 0; i < dim; i++)
    {
        if (vec[i]>condicion)
        {
            suma+=vec[i];
            cantCumple++;
        }
        
    }

    double prom = (cantCumple > 0) ? suma/cantCumple : 0;
    return prom;
    
}

int main(){
    const int TAM_AR = 7;

    double vector[TAM_AR];
    ifstream archilec;
    archilec.open("G04Datos/datosG04E02.txt");
    
    if (!archilec) {
        cout << "No se pudo abrir el archivo" << endl;
        return 1;
    }

    int i = 0;
    
    while (archilec >> vector[i])
    {
        i++;
    }

    archilec.close();

    cout<< "El promedio de aquellos que superan el 0: " << calcPromCondicion(vector, TAM_AR, 0) << endl;
    cout<< "El promedio de aquellos que superan el 6: " << calcPromCondicion(vector, TAM_AR, 6) << endl;
    cout<< "El promedio de aquellos que superan el 9: " << calcPromCondicion(vector, TAM_AR, 9) << endl;
    cout<< "El promedio de aquellos que superan el 15: " << calcPromCondicion(vector, TAM_AR, 15);
    

    return 0;
}