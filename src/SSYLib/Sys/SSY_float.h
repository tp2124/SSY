/*
Allow custom float functionality behind the compilers back

Main point is to allow bitwise operations on floats in order to have faster
checks and clear up the float ALU
*/


#pragma once

typedef long unsigned ssyFloat;

#define asSSYfloat(x) (*((float *) &x))

void fpadd( ssyFloat left, ssyFloat right, ssyFloat *dest);
void fpsub( ssyFloat left, ssyFloat right, ssyFloat *dest);
