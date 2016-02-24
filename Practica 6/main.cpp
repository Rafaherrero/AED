#include "matriz_t.hpp"

#include <fstream>
#include <cstdlib>
int main (int argc, char** argv){
if (argc != 3){
cerr << "Número de argumento incorrecto. " << endl;
exit (1);
}
else{
ifstream if1;
ifstream if2;
if1.open (argv[1]);
if2.open (argv[2]);
matrix_t A, B, C, D;
A.read (if1);
B.read (if2);
if1.close();
if2.close();


cout << "Matriz 1: " << endl;
A.mostrarMatriz();

cout << "Matriz 2: " << endl;
B.mostrarMatriz();

cout << "Determinante:" << A.determinante() << endl;
cout << "Obtener menor:" << endl;
A.adjunta(D,1,1);
D.mostrarMatriz();

//C.inversa(A);
C.ecuacion(A,B);
}
}