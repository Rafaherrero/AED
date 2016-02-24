//Practica 2 AED
//Vector disperso
//Rafael Herrero Álvarez
//vector_t.cpp


#include "vector_t.hpp"

#include <cstdio>
#include <cmath>
#include <iomanip>

vector_t::vector_t(void):
base_(NULL),
n_(0)
{}

vector_t::vector_t(int n):
base_(NULL),
n_(n)
{
    crea_vector(n_);
}

vector_t::vector_t(const vector_t& v):
base_(NULL),
n_(v.get_n())
{
    crea_vector(n_);
    
    for(int i = 0; i < n_; i++)
        base_[i] = v.get_val(i);
}

vector_t::~vector_t(void)
{
    destruye_vector();
}

void vector_t::resize(int n)
{
    destruye_vector();
    n_ = n;
    crea_vector(n);
}

int vector_t::get_n(void) const
{
    return n_;
}

double& vector_t::get_val(int i)
{
    return base_[i];
}
double vector_t::get_val(int i) const
{
    return base_[i];
}

ostream& vector_t::write(ostream& os) const
{
    os << setw(8) << n_ << endl;
    
    for(int i = 0; i < n_; i++)
        os << setw(8) << fixed << setprecision(4) << base_[i] << " ";
        
    os << endl;
    return os;
}

istream& vector_t::read(istream& is)
{
    is >> n_;
    
    resize(n_);
    
    for(int i = 0; i < n_; i++)
        is >> base_[i];
    return is;
}

int vector_t::ocurrencias(double d, double eps) const
{
    int cnt = 0;
    
    for(int i = 0; i < n_; i++)
        if (fabs(base_[i] - d) < eps)
            cnt ++;
            
    return cnt;
}

double vector_t::scalprod(const vector_t& v) const
{
    double prod = 0.0;
    
    for(int i = 0; i < n_; i++)
        prod += base_[i] * v.get_val(i);
        
    return prod;
}


double& vector_t::operator[](int i)
{
    return get_val(i);
}

double vector_t::operator[](int i) const
{
    return get_val(i);
}


void vector_t::crea_vector(int n)
{
    base_ = new double [n];
}

void vector_t::destruye_vector(void)
{
    if (base_ != NULL){
        delete [] base_;
        base_ = NULL;
    }
}

double operator*(const vector_t& v, const vector_t& w)
{
    return v.scalprod(w);
}

ostream& operator<<(ostream& os, const vector_t& v)
{
    return v.write(os);
}

istream& operator>>(istream& is, vector_t& v)
{
    return v.read(is);
}