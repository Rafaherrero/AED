//Practica 5 de AED
//Rafael Herrero Alvarez
//Compilar con: g++ -g main.cpp dll_t.cpp dll_node_t.cpp dll_char_node_t.cpp dll_int_node_t.cpp stack_int_t.cpp queue_char_t.cpp aed_buffer_t.cpp evaluador_RPN_t.cpp -o prueba

#include <iostream>

#include "aed_buffer_t.hpp"
#include "evaluador_RPN_t.hpp"

using namespace std;

int main(void)
{   
    system ("clear");

    char cadena[] = "En un lugar de la Mancha de cuyo nombre no quiero acordarme, no ha mucho tiempo que vivía un hidalgo de los de lanza en astillero, adarga antigua, rocín flaco y galgo corredor.";

    AED::aed_buffer_t buffer(10);

    for (int i = 0; i < sizeof(cadena)-1; i++)
        buffer.insert(cadena[i]);
    
    buffer.flush();
    cout << endl;

    char operacion[] = "10 10 + 5 * 10 - 9 / 4 %";

    AED::evaluador_RPN_t oper;

    cout << "La operacion introducida es: " << operacion << endl;
    cout << "El resultado de la operacion en polaca inversa es: " << oper.eval(operacion) << endl;
}