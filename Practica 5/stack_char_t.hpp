#pragma once

#include "dll_t.hpp"

#include <iostream>
using namespace std;

namespace AED {

    class stack_char_t {
    private:
        dll_t list_;

    public:
        stack_char_t(void);
        virtual ~stack_char_t(void);

	    void push(char c);
	    char pop(void);
	    
	    bool empty(void);

        ostream& write(ostream& os);
    };

}