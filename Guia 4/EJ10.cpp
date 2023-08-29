#include <iostream>

using namespace std;

// Se carga un vector con 8 elementos enteros. Estos valores representan el puntaje obtenido en un
// campeonato por los equipos que participan. En la posición de subíndice i se encuentra el
// puntaje del equipo al que se dio el código i. Informe la tabla de posiciones, ordenando de
// mayor a menor puntaje, e indicando a que equipo corresponde ese puntaje

void ordenarAsc(int vecPunt[], int dim, int vecCod[]){
    for (int i = 0; i < dim; i++)
    {
        for (int j = i+1; j < dim; j++)
        {
            if (vecPunt[i]<vecPunt[j])
            {
                swap(vecPunt[i], vecPunt[j]);
                swap(vecCod[i], vecCod[j]);
            }
            
        }
        
    }
    
}

void mostrar(int vecPunt[], int dim, int vecCod[]){
    for (int i = 0; i < dim; i++)
    {
        cout<< i+1 << ". Codigo del equipo " << vecCod[i] << " Puntos: " << vecPunt[i] << endl;
    }
    
}

int main(){
    const int DIM{8};
    int vecPunt[DIM];
    int vecCod[DIM];

    for (int i = 0; i < DIM; i++)
    {
        cout<<"Cargue el puntaje del equipo " << i << ": ";
        cin>>vecPunt[i];
        vecCod[i] = i;
    }
    
    ordenarAsc(vecPunt, DIM, vecCod);
    mostrar(vecPunt, DIM, vecCod);

    return 0;
}