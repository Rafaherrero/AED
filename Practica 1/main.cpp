//Practica 1 AED
//Multiplicacion matrices
//Rafael Herrero Álvarez
//main.cpp

#include "matriz_t.hpp"

int main(void)
{
//Creamos nuestras matrices
	matrix_t A(2,3);
	matrix_t B(3,3);
	matrix_t C;

//Comprobamos si A es cuadrada y la mostramos
	if (A.cuadrado())
	std::cout << "¡Soy cuadrada!" << std::endl;
	A.mostrarMatriz();	
//Comprobamos si B es cuadrada y la mostramos
	if (B.cuadrado())
	std::cout << "¡Soy cuadrada!" << std::endl;
	B.mostrarMatriz();
//Comprobamos si ambas matrices son multiplicables 	
	if (A.multiplicables(A,B))
	std::cout << "¡Somos multiplicables!" << std::endl;
//Multiplicamos
	A.multiplicacion(A,B);
	//A.mostrarMatriz();
	
	std::cout << B.sumadiagonal() << std::endl;
}