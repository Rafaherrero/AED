#pragma once

#include "stack_int_t.hpp"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

namespace AED {

    class evaluador_RPN_t {
    private:
    	stack_int_t pila_;
    public:
    	evaluador_RPN_t(void);
    	virtual ~evaluador_RPN_t(void);

    	int eval (char* expres);
    	bool es_operando (char* expres);
    };
}