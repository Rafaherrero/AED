//Practica 2 AED
//Vector disperso
//Rafael Herrero Álvarez
//sparse_vector_t.hpp

#pragma once

#include "vector_t.hpp"

class sparse_vector_t{

private:
	int* inx_;
	double* val_;
	int nz_;
	int n_;

public:

sparse_vector_t (const vector_t& v, double eps);
sparse_vector_t (void);
~sparse_vector_t(void);
ostream& write (ostream& os) const;
ostream& salidaformateada (ostream& os) const;
double scalprod (vector_t& v);
sparse_vector_t (const sparse_vector_t& vc);
int mayor_elemento (void);
double producto_todos (void);

};
