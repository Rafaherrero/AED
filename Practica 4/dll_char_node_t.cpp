#include "dll_char_node_t.hpp"

namespace AED {

dll_char_node_t::dll_char_node_t(char c):
	dll_node_t(),
	c_(c)
{}

dll_char_node_t::~dll_char_node_t(void){}

char dll_char_node_t::get_data(void){
	return c_;
}

ostream& dll_char_node_t::write(ostream& os) const{
	os << c_;
	return os;
}

}