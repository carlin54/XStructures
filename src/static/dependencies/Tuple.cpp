/*
 * Tuple.cpp
 *
 *  Created on: Dec 27, 2015
 *      Author: carlin
 */

#include "Tuple.h"

template<class... t_args> Tuple<t_args...>::Tuple(const t_args&... args): value(args){

}

template<class... t_args> Tuple<t_args...>::~Tuple() {
	// TODO Auto-generated destructor stub
}

