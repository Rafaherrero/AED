#include "dll_int_node_t.hpp"

#include <iostream>

using namespace std;

namespace AED {
    
        dll_int_node_t::dll_int_node_t(int c):
        dll_node_t(),
        c_(c) {}
        
        dll_int_node_t::~dll_int_node_t(void)
        {}

        ostream& dll_int_node_t::write(ostream& os) const
        {
            os << c_;
            return os;
        }
    
        int dll_int_node_t::get_data(void)
        {
            return c_;
        }
}