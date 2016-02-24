//Practica 2 AED
//Vector disperso
//Rafael Herrero Álvarez
//vector_t.hpp

#pragma once

#include <iostream>
using namespace std;

class vector_t{
  private:
    double* base_;
    int     n_;
  public:
    vector_t(void);
    vector_t(int n);
    vector_t(const vector_t& v);
    ~vector_t(void);
    
    void resize(int n);
    
    int get_n(void) const;
    double& get_val(int i);
    double get_val(int i) const;
    
    ostream& write(ostream& os) const;
    istream& read(istream& is);
    
    int ocurrencias(double d, double eps) const;
    double scalprod(const vector_t& v) const;
    
    
    double& operator[](int i);
    double operator[](int i) const;
    
  private:
    void crea_vector(int n);
    void destruye_vector(void);
    
};

double operator*(const vector_t& v, const vector_t& w);

ostream& operator<<(ostream& os, const vector_t& v);
istream& operator>>(istream& is, vector_t& v);