#include "ex_singleton.h"
#include "logout.h"

namespace hukusuke
{

ex_singleton*	ex_singleton::instance_	= NULL;
mutex			ex_singleton::mtx_;

/*  Constructor  */
ex_singleton::ex_singleton()
{
	LOG_OUTPUT("Constructor");
}

/* Destructor.  */
ex_singleton::~ex_singleton()
{
	LOG_OUTPUT("Destructor");
}

/* Get singleton instance. */
ex_singleton& ex_singleton::get_instance()
{
	if ( !instance_ ){
		lock_guard<std::mutex> grd(mtx_); // Double-Checked Locking
		if ( !instance_ ){
			ex_singleton*	obj	= new ex_singleton();
			instance_ = obj;
		} else {}

	} else {}
	
	return *instance_;
}

/* Start function. */	
void ex_singleton::start(){
	LOG_OUTPUT("Start");
}

}  // namespace hukusuke.