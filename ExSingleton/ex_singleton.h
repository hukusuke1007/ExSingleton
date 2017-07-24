#ifndef _EX_SINGLETON_H_
#define _EX_SINGLETON_H_

#include "stdafx.h"
#include <mutex>

using namespace std;
namespace hukusuke {

/* ex_singleton class*/
class ex_singleton {
	/*--------------------------------*/
	/*  Public method.                */
	/*--------------------------------*/
	public:
		// Get singleton instance.
		// @return not NULL on instance, NULL on error.
		static ex_singleton&	get_instance();
		void   					start();
	/*--------------------------------*/
	/* Private method.                */
	/*--------------------------------*/
	private:
		//  Constructor.
		ex_singleton();
		ex_singleton( const ex_singleton& );			// default.
		ex_singleton& operator=( const ex_singleton& );	// default.
		
		// Destructor.
		~ex_singleton();
		
	/*--------------------------------*/
	/* Private member.                */
	/*--------------------------------*/
	private:
		static	ex_singleton*		instance_;
		static  mutex				mtx_;
};

}

#endif /* _EX_SINGLETON_H_ */

