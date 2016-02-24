#pragma once

#include <iostream>
using namespace std;

namespace AED {

    class dll_node_t {
    private:
        dll_node_t* next_;
        dll_node_t* prev_;

    public:
        dll_node_t(void);
        virtual ~dll_node_t(void);

	    void set_next(dll_node_t* next);
	    dll_node_t* get_next(void) const;
	    
	    void set_prev(dll_node_t* prev);
	    dll_node_t* get_prev(void) const;	    

        virtual ostream& write(ostream& os) const = 0;
    };

}