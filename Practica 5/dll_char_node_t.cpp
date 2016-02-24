#include "dll_char_node_t.hpp"

#include <iostream>

using namespace std;

namespace AED {
    
        dll_char_node_t::dll_char_node_t(char c):
        dll_node_t(),
        c_(c) {}
        
        dll_char_node_t::~dll_char_node_t(void)
        {}

        ostream& dll_char_node_t::write(ostream& os) const
        {
            os << c_;
            return os;
        }
    
        char dll_char_node_t::get_data(void)
        {
            return c_;
        }
}