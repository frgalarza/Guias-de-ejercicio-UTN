#include <iostream>
#include <fstream>

using namespace std;

// Una empresa fabrica 6 productos diferentes y cada uno de ellos puede terminarse en 3 colores
// distintos. Se Tienen dos archivos de texto. El primero tiene los nombres de los productos,
// seguido inmediatamente por los nombres de los colores. El otro archivo contiene información
// de los lotes de producción terminados en la semana. Por cada lote de producción se guarda una
// línea con: el código del producto (entero con valores entre 0 y 5), el código del color (entero
// entre 0 y 2) y la cantidad producida. Dentro de la línea, los valores se separan mediante un
// tabulador.
// Se pide armar un programa que a partir de la información en los archivos informe:
// 1. De cual combinación producto-color se produjo la mayor cantidad de unidades. Informar
// usando los nombres, no los códigos, y la cantidad producida para esa combinación.
// 2. Nombre del producto del cual se produjo la menor cantidad de unidades, y cuantas fueron.
// 3. Que combinación producto-color tuvo el mayor promedio de unidades por lote. Informar
// usando los nombres y el promedio correspondiente.
// Nota: Usando los archivos datosG04E15nombres.txt y datosG04E15producc.txt los
// resultados son:
// 1. cantimplora en color azul con 588 unidades producidas
// 2. mochila con 705 unidades
// 3. cantimplora en color verde con un promedio de 108 unidades por lote

int mayor(int unidadesPord[6][3], int& codCol){
    const int DPRODUCTO{6}, DCOLOR{3};
    int mayor = unidadesPord[0][0];
    int codProd{0};

    for (int i = 0; i < DPRODUCTO; i++)
    {
        for (int j = 0; j < DCOLOR; j++)
        {
            if (mayor<unidadesPord[i][j])
            {
                mayor = unidadesPord[i][j];
                codProd = i;
                codCol = j;
            }
            
        }
        
    }
    
    return codProd;
}

int main(){
    const int DPRODUCTO{6}, DCOLOR{3};
    string vecProdNombre[DPRODUCTO], vecColorNombre[DCOLOR];
    int codProd, codCol, cant;
    int lotes[DPRODUCTO][DCOLOR] {}, unidadesProd[DPRODUCTO][DCOLOR] {};

    ifstream archilec;

    archilec.open("G04Datos/datosG04E15nombres.txt");
    if (!archilec)
    {
        cout<<"Error al abrir el archivo datosG04E15nombres.txt";
        return 1;
    }

    for (int i = 0; i < DPRODUCTO && archilec >> vecProdNombre[i] ; i++);
    for (int j = 0; j < DCOLOR && archilec >> vecProdNombre[j]; j++);

    archilec.close();
    
    archilec.open("G04Datos/datosG04E15producc.txt");
    if (!archilec)
    {
        cout<<"Error al abrir el archivo datosG04E15preoducc.txt";
        return 1;
    }

    while (archilec >> codProd >> codCol >> cant)
    {
        unidadesProd[codProd][codCol] += cant;
        lotes[codProd][codCol]++;
    }
    
    archilec.close();

    //Punto 1

    int codColMayor{0};
    int codProdMayor = mayor(unidadesProd, codColMayor);

    cout<<"El producto que mas se vendio fue el " << vecProdNombre[codProdMayor] << " en color " << vecColorNombre[codColMayor] << " con un total de " << unidadesProd[codProdMayor][codColMayor] << " unidades" << endl;

    return 0;
}