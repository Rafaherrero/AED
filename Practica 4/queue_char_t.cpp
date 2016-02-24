#include "queue_char_t.hpp"

namespace AED{

	queue_char_t::queue_char_t (void):
	list_ ()
	{}

	queue_char_t::~queue_char_t(void)
	{}

	void queue_char_t::put(char c)
	{
		list_.insert_end (new dll_char_node_t(c));
	}

	char queue_char_t::get (void)
	{
		dll_char_node_t* n_aux = (dll_char_node_t*)(list_.extract_end());
		return n_aux -> get_data();
	}

	bool queue_char_t::empty (void){
		return (list_.empty());
	}

	ostream& queue_char_t::write (ostream& os){
		if (!list_.empty())
			list_.write(cout);

		else if (list_.empty())
			cout << "La cola está vacía. " << endl;

		return os;
	}
}