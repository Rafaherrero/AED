//Practica 2 AED
//Vector disperso
//Rafael Herrero Álvarez
//main.cpp

#include <iostream>
using namespace std;

#include "vector_t.hpp"
#include "sparse_vector_t.hpp"

int main(void)
{
    // vector_t v(10);

    // v[0] = 10.0;
    // v[1] = 0.01;
    // v[2] = 0.001;
    // v[3] = 0.0001;
    // v[4] = 0.1;
    // v[5] = 0.001;
    // v[6] = 0.0001;
    // v[7] = 10.0;
    // v[8] = 5.6;
    // v[9] = 0.0001;

    // sparse_vector_t s_v(v, 0.01);
    // sparse_vector_t s_w(v, 0.001);
    // sparse_vector_t s_x(v, 0.0001);
    
//Modificacion

	vector_t v(6);
	
	v[0] = 0;
    v[1] = 0;
    v[2] = 5;
    v[3] = 6;
    v[4] = 0;
    v[5] = 4;

    vector_t x(6);

    x[0] = 8;
    x[1] = 1;
    x[2] = 3;
    x[3] = 5;
    x[4] = 4;
    x[5] = 3;

    sparse_vector_t s_v(v, 0);

    sparse_vector_t s_x(x, 0);

	cout << endl << "Vector original: " << endl;
    v.write(cout);
    
    cout << endl << "Vector con precisión 0:" << endl;
    s_v.write(cout);
    // cout << endl << "Vector con precisión 0.001:" << endl;
    // s_w.write(cout);
    // cout << endl << "Vector con precisión 0.0001:" << endl;
    // s_x.write(cout);
    // cout << endl;

    s_x.salidaformateada(cout);
    
    cout << endl << "El producto escalar de los vectores es: " << s_v.scalprod(x) << endl;
    cout << endl << "El índice del mayor elemento de v es: " << s_v.mayor_elemento() << endl;
    cout << endl << "La multiplicación de todos los elementos del vector v es: " << s_v.producto_todos() << endl;
}
