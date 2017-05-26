/*
 * Chain.h
 *
 *  Created on: Dec 26, 2015
 *      Author: carlin
 */

#ifndef CHAIN_H_
#define CHAIN_H_

#include "../misc/precision.h"
#include "dependencies/Link.h"

template<class t_type>
class Chain :
	public Link<t_type>
{

	inline static void Assert();

private:
	static Link<t_type>* pStart;
	static Link<t_type>* pEnd;

protected:
	Chain();
	virtual ~Chain();

public:


};

#endif /* DOUBLYLINKEDLIST_H_ */
