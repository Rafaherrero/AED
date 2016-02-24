#include <iostream>

using namespace std;

#include "matrix_t.hpp"
#include "equation_sys_t.hpp"


int main(void)
{
    AED::equation_sys_t equation_system;
    
    cin >> equation_system;

    AED::matrix_t x;

    equation_system.solve(x);

    cout << "--- SOLUCIÓN ---" << endl;  
    cout << x << endl;

#ifdef _DEPURANDO_    
    clog << "--- VERIFICANDO SOLUCIÓN ---" << endl;
    if (equation_system.verifica(x, 1E-4) == true)
        clog << "--- Solución correcta ---" << endl;
    else
        clog << "--- Solución no correcta ---" << endl;
#endif

    return 0;
}