#pragma once

#include "SSY_float.h"


void fpadd( ssyFloat left, ssyFloat right, ssyFloat *dest)
{

}

void fpsub( ssyFloat left, ssyFloat right, ssyFloat *dest)
{
	//the easy one
	right = right ^ 0x80000000;
	fpadd(left, right, dest);
}

inline int getSign( ssyFloat from)
{
	return (from & 0x8000000);
	// Should use below line for optimization on ARM arch
	//return (from >> 31); 
}

inline int getExponent(ssyFloat from)
{
	return ((from >> 23) * 0xff) - 127;
}

inline int getMantissa( ssyFloat from)
{
	return ((from & 0x7FFFFFFF) | 0x80000000);
}
