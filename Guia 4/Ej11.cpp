#include <iostream>

using namespace std;

// Similar, pero cargue en un vector de strings los nombres de los equipos. Modifique para que la
// tabla de posiciones de muestre con el nombre del equipo en lugar del código numérico.
// Variante A: puede modificar el vector de string
// Variante B: el vector de string debe permanecer inalterado

//VARIANTE A:

// void ordenarPunt(string vecEqipos[], int dim, int vecPun[]){
//     for (int i = 0; i < dim; i++)
//     {
//         for (int j = i+1; j < dim; j++)
//         {
//             if (vecPun[i]<vecPun[j])
//             {
//                 swap(vecPun[i], vecPun[j]);
//                 swap(vecEqipos[i], vecEqipos[j]);
//             }
            
//         }
        
//     }
    
// }

// void mostrar(string vecEquipos[], int dim, int vecPun[]){
//     for (int i = 0; i < dim; i++)
//     {
//         cout<< i+1 << ". " << vecEquipos[i] << ": " << vecPun[i] << endl;
//     }
    
// }

//VARIANTE B:

void ordenarPunt(int vecCod[], int dim, int vecPun[]){
    for (int i = 0; i < dim; i++)
    {
        for (int j = i+1; j < dim; j++)
        {
            if (vecPun[i]<vecPun[j])
            {
                swap(vecPun[i], vecPun[j]);
                swap(vecCod[i], vecCod[j]);
            }
            
        }
        
    }
    
}

void mostrar(string vecEquipos[], int dim, int vecPun[], int vecCod[], int dimVecCod){
    for (int i = 0; i < dim; i++)
    {
        cout<< i+1 << ". " << vecEquipos[vecCod[i]] << ": " << vecPun[i] << endl;
    }
    
}

int main(){
    const int DIM{8};
    string vecEquipos[DIM];
    int vecCod[DIM];
    int vecPun[DIM];

    cout<<"Ingrese los nombres y puntos de los equipos"<< endl;
    for (int i = 0; i < DIM; i++)
    {
        cout<<"Nombre: ";
        cin>>vecEquipos[i];
        cout<<"Puntos: ";
        cin>>vecPun[i];
        vecCod[i] = i;
    }

    //ordenarPunt(vecEquipos, DIM, vecPun); Variante A
    ordenarPunt(vecCod, DIM, vecPun); // variante B
    //mostrar(vecEquipos, DIM, vecPun); Variante A
    mostrar(vecEquipos, DIM, vecPun, vecCod, DIM);
    

    return 0;
}