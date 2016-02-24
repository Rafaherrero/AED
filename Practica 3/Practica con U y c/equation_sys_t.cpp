#include "equation_sys_t.hpp"

#include <iomanip>
#include <cmath>

namespace AED {

    equation_sys_t::equation_sys_t(void):
    A_(),
    b_(),
    U_(),
    c_()
    {}
    
    equation_sys_t::~equation_sys_t(void)
    {}
    
    void equation_sys_t::solve(matrix_t& x)
    {
        triangulariza();
        despeja(x);
    }
    
    bool equation_sys_t::verifica(const matrix_t& x, double eps) const
    {
        matrix_t Ax;
        
        Ax.multiplica(A_, x);
        
        bool iguales = true;
        for(int i = 1; (i <= Ax.get_m()) && iguales; i++){
            
            if (fabs(Ax(i, 1)- b_(i, 1)) > eps)
                iguales = false;
        }
        
        return iguales;
    }
    
    ostream& equation_sys_t::to_stream(ostream& os) const
    {
        for(int i = 1; i <= A_.get_m(); i ++){
            for(int j = 1; j <= A_.get_n(); j++)
                os << setw(10) << fixed << setprecision(4) << A_(i,j)<< " "; 
            os << " | " << setw(10) << fixed << setprecision(4) << b_(i,1)<< endl; 
        }
        return os;    
    }
    
    istream& equation_sys_t::from_stream(istream& is)
    {
        is >> A_ >> b_;

        return is;
    }
    
    void equation_sys_t::triangulariza(void)
    {

    #ifdef _DEPURANDO_   
        clog << endl;
        clog << "--- TRIANGULARIZACIÓN de la matriz ---"<< endl;
        to_stream(clog);
        clog << endl;
        clog << "--- COMIENZO ---" << endl;
    #endif        
        
    double aux = 0.0;

    U_.resize_matrix(A_.get_m(), A_.get_n());
    c_.resize_matrix(b_.get_m(), b_.get_n());


    for(int i = 1; i <= A_.get_m(); i ++)
            for(int j = 1; j <= A_.get_n(); j++)
                U_(i,j) = A_(i,j);


    for(int i = 1; i <= b_.get_m(); i ++)
            for(int j = 1; j <= b_.get_n(); j++)
                c_(i,j) = b_(i,j);


    for (int i = 1; i <= U_.get_n(); i++){

        if (U_(i,i)==0){
            clog << "Existe un pivote nulo. Por favor, permute filas" << endl;
        }
            
        else{
            for (int k = i+1; k <= U_.get_m(); k++){

                aux = -(U_(k,i)/U_(i,i));

                    for (int j = i; j <= U_.get_n(); j++){
                        U_(k,j) = (U_(i,j)*aux)+(U_(k,j));
                    }

                c_(k,1) = (c_(i,1)*aux)+(c_(k,1));
                
            }
        }


    // for (int i = 1; i <= A_.get_n(); i++){

    //     if (A_(i,i)==0){
    //         clog << "Existe un pivote nulo. Por favor, permute filas" << endl;
    //     }
            
    //     else{
    //         for (int k = i+1; k <= A_.get_m(); k++){

    //             aux = -(A_(k,i)/A_(i,i));

    //                 for (int j = i; j <= A_.get_n(); j++){
    //                     A_(k,j) = (A_(i,j)*aux)+(A_(k,j));
    //                 }

    //             b_(k,1) = (b_(i,1)*aux)+(b_(k,1));
                
        //     }
        // }

    #ifdef _DEPURANDO_            
            clog << "Triangulizando. Etapa "<< i << " -> "<< endl;
            to_stream(clog);
            clog << endl;
    #endif
    
    }

#ifdef _DEPURANDO_            
        clog << "--- FIN ---" << endl;
#endif          

    }
    
void equation_sys_t::despeja(matrix_t& x) const
{

    x.resize_matrix(b_.get_m(),b_.get_n());
    double aux = 0.0;

    for (int i = U_.get_m(); i >= 1; i--){
        if (i == U_.get_m()){
            x(i,1) = c_(i,1)/U_(U_.get_m(),U_.get_n());
        }
        else{
            for (int j = U_.get_m(); j >= i+1; j--){
                aux += (U_(i,j)*x(j,1));
            }
            x(i,1) = ((c_(i,1))-aux)/U_(i,i);
            aux = 0.0;
        }
    }
}

}

ostream&  operator<<(ostream& os, const AED::equation_sys_t& M) 
{
    return M.to_stream(os);
}

istream&  operator>>(istream& is, AED::equation_sys_t& M)
{
    return M.from_stream(is);
}