#include "stack_int_t.hpp"
#include "dll_int_node_t.hpp"

#include <iostream>
#include <cstdio>

using namespace std;

namespace AED {

    stack_int_t::stack_int_t(void):
    list_()
    {}
    
    stack_int_t::~stack_int_t(void)
    {}

    void stack_int_t::push(int c)
    {
        list_.insert_beginning(new dll_int_node_t(c));
    }
    
    int stack_int_t::pop(void)
    {
        dll_int_node_t* n_aux = (dll_int_node_t*)(list_.extract_beginning());
        
        int aux = n_aux->get_data();
        
        delete n_aux;
        
        return aux;
    }
    
    bool stack_int_t::empty(void)
    {
        return list_.empty();
    }

    ostream& stack_int_t::write(ostream& os)
    {
        list_.write(os);
        
        return os;
    }
}