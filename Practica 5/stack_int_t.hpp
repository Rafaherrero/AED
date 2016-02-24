#pragma once

#include "dll_t.hpp"

#include <iostream>
using namespace std;

namespace AED {

    class stack_int_t {
    private:
        dll_t list_;

    public:
        stack_int_t(void);
        virtual ~stack_int_t(void);

	    void push(int c);
	    int pop(void);
	    
	    bool empty(void);

        ostream& write(ostream& os);
    };

}