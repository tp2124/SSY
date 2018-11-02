#pragma once

#include "..\Sys\SSY_float.h"


class ssyVec3
{
public:
	float				x;
	float				y;
	float				z;
						ssyVec3();
						explicit ssyVec3( const float xyz ) { Set( xyz, xyz, xyz ); }
						explicit ssyVec3( const float x, const float y, const float z ){Set(x, y, z);}

	void 				Set( const float x, const float y, const float z );
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

	//friend ssyVec3	operator*( const float a, const ssyVec3 b );

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
	//const float *		TofloatPtr() const;
	//float *			TofloatPtr();
	//const char *		ToString( int precision = 2 ) const;

	//void				NormalVectors( ssyVec3 &left, ssyVec3 &down ) const;	// vector should be normalized
	//void				OrthogonalBasis( ssyVec3 &left, ssyVec3 &up ) const;

	//void				ProjectOntoPlane( const ssyVec3 &normal, const float overBounce = 1.0f );
	//bool				ProjectAlongPlane( const ssyVec3 &normal, const float epsilon, const float overBounce = 1.0f );
	//void				ProjectSelfOntoSphere( const float radius );

	//void				Lerp( const ssyVec3 &v1, const ssyVec3 &v2, const float l );
	//void				SLerp( const ssyVec3 &v1, const ssyVec3 &v2, const float l );
	
};

inline void ssyVec3::Set( const float in_x, const float in_y, const float in_z)
{
	this->x = in_x;
	this->y = in_y;
	this->z = in_z; 
}


inline void ssyVec3::Zero()
{
	x = y = z = 0.0f;
}