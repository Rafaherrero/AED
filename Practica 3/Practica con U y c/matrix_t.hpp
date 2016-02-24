#pragma once

#include <iostream>	
using namespace std;

namespace AED {

    class matrix_t {
    
    private:
    
    	double*	M_;	
    
    	int  	m_;	
    	int	    n_;
    
    public:
    
    	matrix_t(int m, int n);
    	matrix_t(const matrix_t& M);
    	matrix_t(void); 	
    	~matrix_t(void);
    
    	int get_m(void) const;
    	int get_n(void) const;
    	
    	void resize_matrix(int m, int n);
    	
    	double operator()(int i, int j) const;
    	double& operator()(int i, int j); 
        
        ostream&  to_stream(ostream& os) const;
        istream&  from_stream(istream& is);          
        
        void multiplica(const matrix_t& A, const matrix_t& B);
    
    private:
    	int pos(int i, int j) const;
    
    	void build_matrix(void); 
    	void destroy_matrix(void);
    	
    	double get_matrix_item(int i,int j) const;
    	double& get_set_matrix_item(int i, int j);   
        
        bool multiplicable(const matrix_t& A, const matrix_t& B);
        bool cuadrada(void);
    };

}

ostream&  operator<<(ostream& os, const AED::matrix_t& M);
istream&  operator>>(istream& is, AED::matrix_t& M);

