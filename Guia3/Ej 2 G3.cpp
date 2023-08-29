#include <iostream>
#include <fstream>

using namespace std;

//  Arme un programa que lea cantidades reales de un archivo. Informe por pantalla cual es el
// menor valor y en que orden se encontraba (ordinal del valor en la secuencia)

int main(){
    float nro;
    int cant{1};
    int posMin{1};
    ifstream archilec;

    archilec.open("Guia03-Datos/02entrada.txt");

    if(!archilec){
        cout<<"No se pudo abrir el archivo";
        return -1;
    }

    float min;

    if(archilec >> nro){//Debo usar condicional por si el archivo esta vacio
        min = nro;//inicializo el minimo con el primer numero leido
        while (archilec >> nro)//En esta linea ya lee el segundo valor
    {   
        cout<<"numero actual: "<< nro << endl;
        cant++;
        if(nro<min) {
            min = nro;
            posMin=cant;
        }
    }}

    archilec.close();
    
    cout<< "El menor es: "<< min << " y estaba en la posicion: " << posMin << endl;

    return 0;
}