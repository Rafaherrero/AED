#include "queue_char_t.hpp"
#include "dll_char_node_t.hpp"

#include <iostream>
#include <cstdio>

using namespace std;

namespace AED {

    queue_char_t::queue_char_t(void):
    list_()
    {}
    
    queue_char_t::~queue_char_t(void)
    {}

    void queue_char_t::put(char c)
    {
        list_.insert_beginning(new dll_char_node_t(c));
    }
    
    char queue_char_t::get(void)
    {
        dll_char_node_t* n_aux = (dll_char_node_t*)(list_.extract_end());
        
        char aux = n_aux->get_data();
        
        delete n_aux;
        
        return aux;
    }
    
    bool queue_char_t::empty(void)
    {
        return list_.empty();
    }

    ostream& queue_char_t::write(ostream& os)
    {
        list_.write(os);
        
        return os;
    }
}