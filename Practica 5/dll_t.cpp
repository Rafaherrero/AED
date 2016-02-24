#include "dll_t.hpp"
#include "dll_node_t.hpp"

#include <iostream>
#include <cstdio>

using namespace std;

namespace AED {

    dll_t::dll_t(void) :
    beginning_(NULL),
    end_(NULL){}

    dll_t::~dll_t(void) {

        while (beginning_ != NULL) {
            
            dll_node_t* aux = beginning_;
            beginning_ = beginning_->get_next();
            delete aux;
        }
    }
	
    bool dll_t::empty(void) const {
        return (beginning_ == NULL);
    }


    void dll_t::insert_beginning(dll_node_t* n)
    {
    	n->set_next(beginning_);
    	n->set_prev(NULL);
    	
    	if(end_ == NULL)
    	    end_ = n;
    	else
    	    beginning_->set_prev(n);
    	    
    	beginning_ = n;
    }

    dll_node_t* dll_t::extract_beginning(void) {

        dll_node_t* aux = beginning_;
        beginning_ = beginning_->get_next();
        
        aux->set_next(NULL);
        aux->set_prev(NULL);
        
        if (beginning_ == NULL)
            end_ = NULL;

        return aux;
    }

    void dll_t::insert_end(dll_node_t* n)
    {
        n->set_prev(end_);
    	n->set_next(NULL);
    	
    	if (end_ != NULL)
    	    end_->set_next(n);
    	else
    	    beginning_ = n;
    	    
    	 end_ = n;
    }

    dll_node_t* dll_t::extract_end(void) {

        dll_node_t* aux = end_;
        
        end_ = end_->get_prev();
        
        aux->set_next(NULL);
        aux->set_prev(NULL);
        
        if (end_ == NULL)
            beginning_ = NULL;
        else
            end_->set_next(NULL);

        return aux;
    } 


    ostream& dll_t::write(ostream& os) const {
		
        dll_node_t* aux = beginning_;

        while (aux != NULL) {
            aux->write(os);
            aux = aux->get_next();
        }
    }

}