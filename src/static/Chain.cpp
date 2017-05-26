/*
 * Chain.cpp
 *
 *  Created on: Dec 26, 2015
 *      Author: carlin
 */

#ifndef CHAIN_H_
#define CHAIN_H_

#include "Chain.h"

template<class t_type> Link<t_type>* Chain<t_type>::pStart = nullptr;
template<class t_type> Link<t_type>* Chain<t_type>::pEnd = nullptr;

template<class t_type> void Chain<t_type>::Assert(){
	static_assert(std::is_class<t_type>::value, "Template is not a class");
	static_assert(std::is_object<t_type>::value, "Template is not an object");
	static_assert(std::is_base_of<Chain<t_type>, t_type>::value, "Template is not base of");
	static_assert(std::is_compound<t_type>::value, "Template is primitive");
}
template<class t_type> Chain<t_type>::Chain() {

	Assert();

	if (pStart == nullptr || pEnd == nullptr) {
		assert(pEnd == nullptr);
		assert((this->Chain<t_type>::pLeft == nullptr));
		assert((this->Chain<t_type>::pRight == nullptr));
		pStart = (Link<t_type>*)this;
		pEnd = (Link<t_type>*)this;
	} else {
		//assert(pEnd != nullptr);
		this->Chain<t_type>::pLeft = pEnd;
		this->Link<t_type>::pRight = pEnd->Link<t_type>::pRight;
		pEnd->Link<t_type>::pRight = (Link<t_type>*)this;
		pEnd = (Link<t_type>*)this;
	}

};

template<class t_type> Chain<t_type>::~Chain() {

	Assert();

	if (this == pStart || this == pEnd) {
		//Only one in the list
		if (this == pStart && this == pEnd) {
			assert((this->Chain<t_type>::pLeft == nullptr));
			assert((this->Chain<t_type>::pRight == nullptr));
			pStart = nullptr;
			pEnd = nullptr;
		//The first one in the list
		} else if(this == pStart && this != pEnd) {
			assert((this->Chain<t_type>::pLeft == nullptr));
			assert((this->Chain<t_type>::pRight != nullptr));
			this->Link<t_type>::pRight->Link<t_type>::pLeft = this->Link<t_type>::pLeft;
			pStart = this->Chain<t_type>::pRight;
		//The last one in the list
		} else if(this != pStart && this == pEnd) {
			assert((this->Chain<t_type>::pLeft != nullptr));
			assert((this->Chain<t_type>::pRight == nullptr));
			this->Link<t_type>::pLeft->Link<t_type>::pRight = this->Link<t_type>::pRight;
			pEnd = (Link<t_type>*)this->Link<t_type>::pLeft;
		}
	//We are in the middle
	} else {
		this->Link<t_type>::pRight->Link<t_type>::pLeft = this->Link<t_type>::pLeft;
		this->Link<t_type>::pLeft->Link<t_type>::pRight = this->Link<t_type>::pRight;
	}
	this->Chain<t_type>::pLeft = nullptr;
	this->Chain<t_type>::pRight = nullptr;

};

#endif //CHAIN_H
