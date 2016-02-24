//Practica 1 AED
//Multiplicacion matrices
//Rafael Herrero Álvarez
//matriz_t.hpp

#pragma once

#include <stdio.h>		
#include <iostream>		
#include <cmath>		

using namespace std;

typedef double 		matrix_item_t;	
typedef unsigned short int 	matrix_inx_t;	
typedef unsigned short int 	vector_inx_t;	

class matrix_t {
private:

	matrix_item_t*	M_;	

	matrix_inx_t  	m_;	
	matrix_inx_t	n_;	

public:

	matrix_t(matrix_inx_t m,matrix_inx_t n); 
	matrix_t(void); 	
	~matrix_t(void);
	void  mostrarMatriz(void);
	matrix_item_t get_matrix_item(matrix_inx_t i,matrix_inx_t j);
	void set_matrix_item(matrix_inx_t i,matrix_inx_t j,matrix_item_t it);
	matrix_inx_t get_m(void);
	matrix_inx_t get_n(void);
// 	istream& read(istream& is);
// 	ostream& write(ostream& os);
	bool cuadrado (void);
	bool multiplicables (matrix_t& M1, matrix_t& M2);
	matrix_t& multiplicacion(matrix_t& M1, matrix_t& M2);
	matrix_inx_t sumacolumna (matrix_inx_t j);
	matrix_inx_t sumadiagonal (void);
	
private:

	vector_inx_t pos(matrix_inx_t i,matrix_inx_t j);
	void crearMatriz(void); 
	void destruirMatriz(void);
	void redimensiona(matrix_inx_t m,matrix_inx_t n);
	
	void rellenaMatriz(void);
	
};


