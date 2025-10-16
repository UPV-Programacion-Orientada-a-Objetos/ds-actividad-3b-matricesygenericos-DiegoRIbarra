#include <iostream>
#include "MatrizDinamica.h"

int main() {
    int fls, colmns;
    //matriz A
    std::cout<<" Prueba de Matriz ENTERA (Matriz A)"<<"\n";
    std::cout<<" Ingrese el numero de filas: ";
    std::cin>>fls;
    std::cout<<" Ingrese el numero de columnas: ";
    std::cin>>colmns;
    std::cout<<" Creando Matriz (Tipo INT) A de "<<fls<<" filas y "<<colmns<<" columnas."<<"\n";
    MatrizDinamica<int> A(fls, colmns);
    std::cout<<" Llenando Matriz (Tipo INT) A con valores."<<"\n";
    A.llenarMatriz();

    //redimensionado de la matriz A
    std::cout<<" Redimensionando Matriz (Tipo INT) A."<<"\n";
    std::cout<<" Ingrese el nuevo numero de filas: ";
    std::cin>>fls;
    std::cout<<" Ingrese el nuevo numero de columnas: ";
    std::cin>>colmns;
    A.redimensionarMatriz(fls, colmns);
    std::cout<<" Matriz (Tipo INT) A redimensionada a "<<fls<<" filas y "<<colmns<<" columnas."<<"\n";
    A.imprimirMatriz();

    //matriz B
    std::cout<<" Prueba de Matriz Float (Matriz B)"<<"\n";
    std::cout<<" Ingrese el numero de filas: ";
    std::cin>>fls;
    std::cout<<" Ingrese el numero de columnas: ";
    std::cin>>colmns;
    std::cout<<" Creando Matriz (Tipo FLOAT) B de "<<fls<<" filas y "<<colmns<<" columnas."<<"\n";
    MatrizDinamica<float> B(fls, colmns);
    std::cout<<" Llenando Matriz (Tipo FLOAT) B con valores."<<"\n";
    B.llenarMatriz();

    //conversion de la matriz A a float
    MatrizDinamica<float> A_float = MatrizDinamica<int>::conversion<float>(A);
    //multiplicacion y creacion de la matriz C
    std::cout<<" Multiplicando Matriz (Tipo INT) A y B para crear Matriz C."<<"\n";
    MatrizDinamica<float> C = MatrizDinamica<float>::multiplicar(A_float, B);
    std::cout<<" Matriz (Tipo FLOAT) C resultante de la multiplicacion:"<<"\n";
    C.imprimirMatriz();

    return 0;
}