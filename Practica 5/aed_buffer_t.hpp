#pragma once

#include "queue_char_t.hpp"
#include <unistd.h>

using namespace std;

namespace AED {

	class aed_buffer_t{
	private:
		queue_char_t cola_;
		unsigned sz_;
		unsigned cnt_;
	public:
		aed_buffer_t(void);
		aed_buffer_t(unsigned size);
		virtual ~aed_buffer_t(void);

		void flush(void);
		void insert(char c);

		ostream& write(ostream& os);
	};
}