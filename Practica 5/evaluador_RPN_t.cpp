#include "evaluador_RPN_t.hpp"
using namespace std;

namespace AED {
	evaluador_RPN_t::evaluador_RPN_t(void):
	pila_ ()
	{}
	evaluador_RPN_t::~evaluador_RPN_t(void){}

	int evaluador_RPN_t::eval (char* expres){
	char* pch = NULL;
	pch = strtok (expres, " ");
	int left, right = 0;

	while (pch != NULL){

		if (es_operando(pch)){
			int aux = atoi (pch);
			pila_.push(aux);
		}

		else{
			right = pila_.pop();
			left = pila_.pop();
			switch (*pch){
				case '+':
				pila_.push(left+right);
				break;
				case '-':
				pila_.push(left-right);
				break;
				case '*':
				pila_.push(left*right);
				break;
				case '/':
				pila_.push(left/right);
				break;
				case '%':
				pila_.push(left%right);
				break;
			}
		}

		pch = strtok (NULL, " ");
	}

	return (pila_.pop());
}


bool evaluador_RPN_t::es_operando (char* expres){
	if (((expres[0])>='0')&&((expres[0])<='9')||((expres[1])>='0')&&((expres[1])<='9'))
		return true;
	else
		return false;
}

}