//Practica 2 AED
//Vector disperso
//Rafael Herrero Álvarez
//sparse_vector_t.cpp

#include "sparse_vector_t.hpp"

#include <cmath>

#include <iostream>
#include <iomanip>
using namespace std;

sparse_vector_t::sparse_vector_t (const vector_t& v, double eps):
	inx_ (NULL),
	val_ (NULL),
	nz_ (0),
	n_ (v.get_n())
	{
		for (int i=0; i < v.get_n(); i++){
			if (fabs(v[i]) > eps){
				nz_++;
			}
		}
		inx_ = new int [nz_];
		val_ = new double [nz_];

		int aux = 0;
		for (int i = 0; i < v.get_n(); i++){
			if (fabs (v[i]) > eps){
				inx_ [aux] = i;
				val_ [aux] = v[i];
				aux++;
			}
		}

	}

sparse_vector_t::sparse_vector_t (void):
	inx_ (NULL),
	val_ (NULL),
	nz_ (0),
	n_ (0)
{
}

sparse_vector_t::~sparse_vector_t(void)
{
	if (inx_ != NULL){
		delete[] inx_;
		inx_ = NULL;
	}
	if (val_ != NULL){
		delete[] val_;
		val_ = NULL;
	}
}

double sparse_vector_t::scalprod (vector_t& v)
{
	double aux = 0.0;

	for (int i = 0; i < nz_; i++)
		aux += v[inx_[i]]*val_[i];
		
	return aux;
}

ostream& sparse_vector_t::salidaformateada (ostream& os) const
{
	os << setw(47) << "El número de elementos del vector original es: " << setw(9) << n_ << endl;
	os << setw(52) << "El número de elementos del vector con precisión es: " << setw(4) << nz_ << endl;
	os << setw(70) << "Valores del vector con precisión y su posición en el vector original: " << endl;

	for(int i = 0; i < nz_; i++)
        os << setw(8) << fixed << setprecision(4) << val_[i] << " ";

    os << endl;

    for(int i = 0; i < nz_; i++)
        os << setw(7) << "^" << inx_[i] << " ";

    os << endl;

	return os;
}


ostream& sparse_vector_t::write(ostream& os) const
{
    os << setw(8) << n_ << endl;
    os << setw(8) << nz_ << endl;
    
    for(int i = 0; i < nz_; i++)
        os << setw(8) << fixed << setprecision(4) << val_[i] << " ";
        
    os << endl;
        
    for(int i = 0; i < nz_; i++)
        os << setw(8) << inx_[i] << " ";    
    
    os << endl;
    
    return os;
}

sparse_vector_t::sparse_vector_t (const sparse_vector_t& vc):
	inx_ (vc.inx_),
	val_ (vc.val_),
	nz_ (vc.nz_),
	n_ (vc.n_)
{
}

int sparse_vector_t::mayor_elemento (void)
{
	int aux = 0;
	int indice = 0;
	for (int i=0; i < nz_; i++){
		if (val_[i] > aux){
			aux = val_[i];
			indice = i;
		}
	}
	return inx_ [indice];
}

double sparse_vector_t::producto_todos (void)
{
	double aux = 0.0;
	double aux_mult = 1;
	for (int i=0; i < nz_; i++){
			aux_mult = aux_mult * val_ [i];
		}
	return aux_mult;
}