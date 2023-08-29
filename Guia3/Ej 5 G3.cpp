#include <iostream>
#include <fstream>

using namespace std;

// Crear un programa que permita generar un archivo de texto a partir de palabras ingresadas por
// teclado, donde haya como máximo 80 caracteres por renglón. Pero deberá evitarse cortar
// palabras.
// Nota: para averiguar cuantos caracteres tiene un string, puede usarse la función size, por
// ejemplo, si declaré string cadena; luego puedo obtener el largo con cadena.size();

int main(){
    string cadena;
    ofstream arcesc;
    arcesc.open("05salida.txt");

    if(!arcesc){
        cout<<"Error al intentar abrir el archivo salida.txt";
        return 1;
    }

    const int maxLinea = 80;
    
    cout << "Ingrese un texto y termine con EOF: ";
    if(cin >> cadena){
        arcesc << cadena;
        int linea = cadena.size();
        while (cin >> cadena)
        {
            if(linea + cadena.size() < maxLinea){
                arcesc << " " << cadena;
                linea += cadena.size() + 1;
            }
            else {
                arcesc << endl << cadena;
                linea = cadena.size();
            }
        }
        
    }
    
    arcesc.close();

    return 0;
}