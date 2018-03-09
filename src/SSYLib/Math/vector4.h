#pragma once

#include <xmmintrin.h>
#include <smmintrin.h>
#include "..\Sys\SSY_float.h"
#include "..\Sys\SSYDefines.h"
#include "vector3.h"

class ssyVec4
{
public:
	float			x;
	float			y;
	float			z;
	float			w;

	explicit			ssyVec4();
	explicit			ssyVec4( const float xyz) {Set(xyz, xyz, xyz, xyz);}
						ssyVec4( const float in_x, float in_y, float in_z, float in_w){Set(in_x, in_y, in_z, in_w);}
	void 				Set( const float in_x, const float in_y, const float in_z, const float in_w );

	void				Zero();

	float				operator[]( const int index ) const;
	float &				operator[]( const int index );
	//ssyVec3			operator-() const;
	//ssyVec3 &			operator=( const ssyVec3 &a );		// required because of a msvc 6 & 7 bug
	//float				operator*( const ssyVec3 &a ) const;
	//ssyVec3			operator*( const float a ) const;
	//ssyVec3			operator/( const float a ) const;
	//ssyVec3			operator+( const ssyVec3 &a ) const;
	//ssyVec3			operator-( const ssyVec3 &a ) const;
	//ssyVec3 &			operator+=( const ssyVec3 &a );
	//ssyVec3 &			operator-=( const ssyVec3 &a );
	//ssyVec3 &			operator/=( const ssyVec3 &a );
	//ssyVec3 &			operator/=( const float a );
	//ssyVec3 &			operator*=( const float a );

	//friend ssyVec3		operator*( const float a, const ssyVec3 b );

	//bool				Compare( const ssyVec3 &a ) const;							// exact compare, no epsilon
	//bool				Compare( const ssyVec3 &a, const float epsilon ) const;		// compare with epsilon
	//bool				operator==(	const ssyVec3 &a ) const;						// exact compare, no epsilon
	//bool				operator!=(	const ssyVec3 &a ) const;						// exact compare, no epsilon

	//bool				FixDegenerateNormal();	// fix degenerate axial cases
	//bool				FixDenormals();			// change tiny numbers to zero

	//ssyVec3			Cross( const ssyVec3 &a ) const;
	//ssyVec3 &			Cross( const ssyVec3 &a, const ssyVec3 &b );
	//float				Length() const;
	//float				LengthSqr() const;
	//float				LengthFast() const;
	//float				Normalize();				// returns length
	//float				NormalizeFast();			// returns length
	//ssyVec3			Truncate( float length ) const;		// cap length
	//void				Clamp( const ssyVec3 &min, const ssyVec3 &max );
	//void				Snap();					// snap to closest integer value
	//void				SnapInt();				// snap towards integer (floor)

	//int				GetDimension() const;

	//float				ToYaw() const;
	//float				ToPitch() const;
	//idAngles			ToAngles() const;
	//idPolar3			ToPolar() const;
	//idMat3			ToMat3() const;		// vector should be normalized
	//const idVec2 &	ToVec2() const;
	//idVec2 &			ToVec2();
	//const float *		ToFloatPtr() const;
	//float *			ToFloatPtr();
	//const char *		ToString( int precision = 2 ) const;

	//void				NormalVectors( ssyVec3 &left, ssyVec3 &down ) const;	// vector should be normalized
	//void				OrthogonalBasis( ssyVec3 &left, ssyVec3 &up ) const;

	//void				ProjectOntoPlane( const ssyVec3 &normal, const float overBounce = 1.0f );
	//bool				ProjectAlongPlane( const ssyVec3 &normal, const float epsilon, const float overBounce = 1.0f );
	//void				ProjectSelfOntoSphere( const float radius );

	//void				Lerp( const ssyVec3 &v1, const ssyVec3 &v2, const float l );
	//void				SLerp( const ssyVec3 &v1, const ssyVec3 &v2, const float l );
};

inline void ssyVec4::Set( const float in_x, const float in_y, const float in_z, const float in_w ) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

extern ssyVec3 vec_origin;


inline void ssyVec4::Zero() {
	x = y = z = w = 0.0f;
}

inline float ssyVec4::operator[]( int index ) const {
	return ( &x )[ index ];
}

inline float& ssyVec4::operator[]( int index ) {
	return ( &x )[ index ];
}
