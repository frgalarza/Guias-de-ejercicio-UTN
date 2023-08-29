#include <iostream>
#include <fstream>

using namespace std;
// Arme un programa que lea las cantidades enteras guardadas en un archivo. Informe por
// pantalla la cantidad de datos leídos, su sumatoria y el promedio (con decimales).

int main(){
    int nro, leidos{0}, sum{0};
    ifstream archilec;

    archilec.open("Guia03-Datos/01entrada.txt");
    if(!archilec){
        cout<< "No se pudo abrir el archivo";
        return -1;
    }

    cout<< "Los datos leidos son: "<< endl;
    while(archilec >> nro){
        cout<< "Leido: " << nro << endl;

        leidos++;
        sum+=nro;
    }

    archilec.close();

    float prom = leidos > 0 ? float(sum)/leidos : 0;

    cout<< "Datos leidos: " << leidos << endl;
    cout<< "La sumatoria de los numeros leidos es: " << sum << endl;
    cout<< "El promedio de los datos leidos es: " << prom << endl;

    return 0;
}