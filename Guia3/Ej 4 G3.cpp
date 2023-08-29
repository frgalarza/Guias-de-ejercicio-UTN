#include <iostream>
#include <fstream>

using namespace std;

// Crear un programa que permita concatenar dos archivos de texto.
// Variantes: puede hacerlo de modo de tal de crear un archivo nuevo con la concatenación y no
// alterar los archivos originales, o bien hacerlo de modo tal que al segundo archivo se lo
// modifique concatenándole los contenidos del primero
int main(){
    string cad;
    ifstream archilec1, archilec2;
    ofstream arconcat;

    archilec1.open("Guia03-Datos/04uno.txt");
    if(!archilec1){
        cout<< "No se pudo abrir el archivo 1";
        return 1;
    }

    archilec2.open("Guia03-Datos/04dos.txt");
    if(!archilec2){
        cout<< "No se pudo abrir el archivo 2";
        archilec1.close();
        return 1;
    }

    arconcat.open("concat.txt");
    if(!arconcat){
        cout<< "No se pudo abrir el concat.txt";
        archilec1.close();
        archilec2.close();
        return 1;
    }

    while (getline(archilec1, cad))
    {
        arconcat << cad << endl;
    }

    while (getline(archilec2, cad))
    {
        arconcat << cad << endl;
    }
    
    archilec1.close();
    archilec2.close();
    arconcat.close();

    return 0;
}