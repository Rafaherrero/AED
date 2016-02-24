#include "stack_char_t.hpp"

namespace AED{

	stack_char_t::stack_char_t (void):
	list_ ()
	{}

	stack_char_t::~stack_char_t(void)
	{}

	void stack_char_t::push(char c)
	{
		list_.insert_beginning (new dll_char_node_t(c));
	}

	char stack_char_t::pop (void)
	{
		dll_char_node_t* n_aux = (dll_char_node_t*)(list_.extract_beginning());
		return n_aux -> get_data();
	}

	bool stack_char_t::empty (void){
		return (list_.empty());
	}

	ostream& stack_char_t::write (ostream& os){
		if (!list_.empty())
			list_.write(cout);

		else if (list_.empty())
			cout << "La pila está vacía. " << endl;

		return os;
	}
}