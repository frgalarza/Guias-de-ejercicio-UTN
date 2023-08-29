#include <iostream>
#include <fstream>

using namespace std;

// Dado un archivo que contienen una serie de números enteros, obtener a partir de él dos
// archivos. En el primero solo habrá números pares, y en el segundo solo impares
int main(){
    int nro;
    ifstream archilec;

    archilec.open("Guia03-Datos/03entrada.txt");

    if(!archilec) {
        cout<<"No se pudo abrir el archivo";
        return 1;
    }

    ofstream arpar;
    arpar.open("pares.txt");
    if(!arpar){
        cout<<"No se pudo abrir el archivo pares.txt";
        archilec.close();
        return 1;
    }

    ofstream arimpar;
    arimpar.open("impares.txt");
    if(!arimpar){
        cout<< "No se pudo abrir el archivo impares.txt";
        archilec.close();
        arpar.close();
        return 1;
    }

    while(archilec >> nro){
        if(nro % 2 == 0) {
            arpar << nro << endl;
        }
        else{
            arimpar << nro << endl;
        }
    }

    archilec.close();
    arimpar.close();
    arpar.close();

    return 0;
}