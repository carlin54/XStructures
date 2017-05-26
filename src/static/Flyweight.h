/*
 * Flyweight.h
 *
 *  Created on: Dec 26, 2015
 *      Author: carlin
 */

#ifndef FLYWEIGHT_H_
#define FLYWEIGHT_H_

#include "dependencies/Tuple.h"

template<class t_type, class... t_args>
class Flyweight
{


public:
	Flyweight(const t_args&... args);
	virtual ~Flyweight();

};

#include "Flyweight.cpp"

#endif /* FLYWEIGHT_H_ */
