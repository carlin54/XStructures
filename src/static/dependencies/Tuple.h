/*
 * Tuple.h
 *
 *  Created on: Dec 27, 2015
 *      Author: carlin
 */

#ifndef TUPLE_H_
#define TUPLE_H_

template<class... t_args>
class Tuple
{


public:
	//t_args... value;
	Tuple(const t_args&... args);
	virtual ~Tuple();

};

#endif /* TUPLE_H_ */
