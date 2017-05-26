/*
 * Node.h
 *
 *  Created on: Oct 16, 2015
 *      Author: carlin
 */

#ifndef LINK_H_
#define LINK_H_

template<class t_type> struct Link {
public:
	Link<t_type>* pLeft;
	Link<t_type>* pRight;

	Link();
	Link(void* pLeft, void* pRight = nullptr);
	~Link();

};

#include "Link.cpp"

#endif /* LINK_H_ */
