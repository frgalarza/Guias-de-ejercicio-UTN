#include <iostream>
#include <fstream>

using namespace std;

// Una empresa fabrica y distribuye sus productos mediante su flota de vehículos. Cada vehículo
// tiene asignado un código que es un número entero y los posibles valores van de 15 a 24. Se
// tiene un archivo en el cual, por cada entrega realizada, se anota el código del vehículo que hizo.
// Se pide hacer un programa que con los datos del archivo informe que vehículo (código) hizo la
// mayor cantidad de entregas.
// Nota: Usando el archivo datosG04E14.txt el resultado es: vehículo 17 con 15 entregas

int posMayor(int vec[], int dim){
    int mayor = vec[0];
    int posMayor{0};
    for (int i = 1; i < dim; i++)
    {
        if (mayor<vec[i])
        {
            mayor = vec[i];
            posMayor = i;
        }
        
    }
    return posMayor;
}

int main(){
    const int DVEH{10};
    int vecVeh[DVEH] = {15, 16, 17, 18, 19, 20, 21, 22, 23, 24}, vecContEntreVeh[DVEH] = {0};
    int entrega{0};

    ifstream archilec;
    archilec.open("G04Datos/datosG04E14.txt");
    if (!archilec)
    {
        cout<<"Ocurrio un error al abrir el archivo de lectura";
        return 1;
    }

    while (archilec >> entrega)
    {
        vecContEntreVeh[entrega - 15] += 1;
    }
    
    int posMay = posMayor(vecContEntreVeh, DVEH);

    cout<<"El vehiculo con mayor entregas es el " << vecVeh[posMay] << " con un total de " << vecContEntreVeh[posMay] << " entregas";

    archilec.close();
    
    return 0;
}