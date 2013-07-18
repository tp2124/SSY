#pragma once

#include <xmmintrin.h>
#include <smmintrin.h>
#include "..\Sys\SSY_float.h"
#include "vector4.h"
#include "..\Sys\SSYDefines.h"
//#include <cmath>

//#ifndef D3DMATRIX_DEFINED
//typedef struct _D3DMATRIX {
//	union {
//		struct {
//			float        _11, _12, _13, _14;
//			float        _21, _22, _23, _24;
//			float        _31, _32, _33, _34;
//			float        _41, _42, _43, _44;
//
//		};
//		float m[4][4];
//	};
//} D3DMATRIX;
//#define D3DMATRIX_DEFINED
//#endif

#define MATRIX_TRANSPOSE(row0, row1, row2, row3) {					\
	__m128 tmp3, tmp2, tmp1, tmp0;										\
																		\
	tmp0   = _mm_shuffle_ps((row0), (row1), _MM_SHUFFLE(1, 0, 1, 0));	\
	tmp2   = _mm_shuffle_ps((row0), (row1), _MM_SHUFFLE(3, 2, 3, 2));	\
	tmp1   = _mm_shuffle_ps((row2), (row3), _MM_SHUFFLE(1, 0, 1, 0));	\
	tmp3   = _mm_shuffle_ps((row2), (row3), _MM_SHUFFLE(3, 2, 3, 2));	\
																		\
	(row0) = _mm_shuffle_ps(tmp3, tmp2, _MM_SHUFFLE(1, 3, 1, 3));		\
	(row1) = _mm_shuffle_ps(tmp3, tmp2, _MM_SHUFFLE(0, 2, 0, 2));		\
	(row2) = _mm_shuffle_ps(tmp1, tmp0, _MM_SHUFFLE(1, 3, 1, 3));		\
	(row3) = _mm_shuffle_ps(tmp1, tmp0, _MM_SHUFFLE(0, 2, 0, 2));		\
	}

class Matrix4
{
public:
	//Keep is slow for now
	ssyFloat		f00, f01, f02, f03,\
					f10, f11, f12, f13,\
					f20, f21, f22, f23,\
					f30, f31, f32, f33;

	/*
	__m128		r0,\
				r1,\
				r2,\
				r3;
	*/
				Matrix4();
				Matrix4(ssyFloat in_f00, ssyFloat in_f01, ssyFloat in_f02, ssyFloat f_03,\
						ssyFloat in_f10, ssyFloat in_f11, ssyFloat in_f12, ssyFloat f_13,\
						ssyFloat in_f20, ssyFloat in_f21, ssyFloat in_f22, ssyFloat f_23,\
						ssyFloat in_f30, ssyFloat in_f31, ssyFloat in_f32, ssyFloat f_33
						);
				Matrix4(ssyVec4 in_r0,\
						ssyVec4 in_r1,\
						ssyVec4 in_r2,\
						ssyVec4 in_r3
						);
}