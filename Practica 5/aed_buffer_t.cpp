#include "aed_buffer_t.hpp"

using namespace std;

namespace AED {

	aed_buffer_t::aed_buffer_t(void):
	cola_(),
	sz_ (0),
	cnt_(0)
	{}

	aed_buffer_t::aed_buffer_t(unsigned size):
	cola_(),
	sz_ (size),
	cnt_ (0)
	{}

	aed_buffer_t::~aed_buffer_t (void)
	{
		flush();
	}

	void aed_buffer_t::flush (void){
		while (!cola_.empty())
			cout << cola_.get();
		
		cout.flush();
		cnt_ = 0;
	}

	void aed_buffer_t::insert (char c){
		if (cnt_ == sz_){
			flush();
			usleep(500000);
	}
			
			cola_.put (c);
			cnt_++;
		

	}

	ostream& aed_buffer_t::write(ostream& os){
		cola_.write(os);
		return os;
	}
}