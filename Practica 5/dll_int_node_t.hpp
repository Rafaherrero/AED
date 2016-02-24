#pragma once

#include <iostream>
using namespace std;

#include "dll_node_t.hpp"

namespace AED {

    class dll_int_node_t: public dll_node_t {
    private:
        int c_;

    public:
        dll_int_node_t(int c);
        virtual ~dll_int_node_t(void);

        virtual ostream& write(ostream& os) const;
        
        int get_data(void);
    };    
    
}