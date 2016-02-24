#pragma once

#include "matrix_t.hpp"
#include <iostream>

using namespace std;

namespace AED {
    
    class equation_sys_t{
        private:
            matrix_t A_;
            matrix_t b_;
            matrix_t U_;
            matrix_t c_;
            
        public:
            equation_sys_t(void);
            ~equation_sys_t(void);

            ostream& to_stream(ostream& os) const;
            istream& from_stream(istream& is);            
            
            void solve(matrix_t& x);
            bool verifica(const matrix_t& x, double eps) const;
        private:
            
            void triangulariza(void);
            void despeja(matrix_t& x) const;
    };

}

ostream&  operator<<(ostream& os, const AED::equation_sys_t& M);
istream&  operator>>(istream& is, AED::equation_sys_t& M);