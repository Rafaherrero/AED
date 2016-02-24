#include "stack_char_t.hpp"
#include "dll_char_node_t.hpp"

#include <iostream>
#include <cstdio>

using namespace std;

namespace AED {

    stack_char_t::stack_char_t(void):
    list_()
    {}
    
    stack_char_t::~stack_char_t(void)
    {}

    void stack_char_t::push(char c)
    {
        list_.insert_beginning(new dll_char_node_t(c));
    }
    
    char stack_char_t::pop(void)
    {
        dll_char_node_t* n_aux = (dll_char_node_t*)(list_.extract_beginning());
        
        char aux = n_aux->get_data();
        
        delete n_aux;
        
        return aux;
    }
    
    bool stack_char_t::empty(void)
    {
        return list_.empty();
    }

    ostream& stack_char_t::write(ostream& os)
    {
        list_.write(os);
        
        return os;
    }
}