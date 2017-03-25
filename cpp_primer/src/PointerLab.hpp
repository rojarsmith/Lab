/*
 * PointerLab.h
 *
 *  Created on: 2017年2月27日
 *      Author: rojar
 */

#ifndef POINTERLAB_HPP_
#define POINTERLAB_HPP_

class PointerLab {
public:
	PointerLab();
	virtual ~PointerLab();

	const double * func1(const double ar[], int n);
	const double * func2(const double[], int);
	const double * func3(const double *, int);
};

#endif /* POINTERLAB_HPP_ */
