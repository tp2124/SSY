#pragma once


#include "vector3.h"



class ssyQuat
{
public:
	float				x;
	float				y;
	float				z;
	float				w;

	explicit			ssyQuat();
	explicit			ssyQuat( const float in_x, const float in_y, const float in_z, const float in_w){Set(in_x, in_y, in_z, in_w);}

	void				Set(const float in_x, const float in_y, const float in_z, const float in_w);



	//float				operator[]( int index ) const;
	//float &			operator[]( int index );
	//ssyQuat			operator-() const;
	//ssyQuat &			operator=( const ssyQuat &a );
	//ssyQuat			operator+( const ssyQuat &a ) const;
	//ssyQuat &			operator+=( const ssyQuat &a );
	//ssyQuat			operator-( const ssyQuat &a ) const;
	//ssyQuat &			operator-=( const ssyQuat &a );
	//ssyQuat			operator*( const ssyQuat &a ) const;
	//ssyVec3			operator*( const ssyVec3 &a ) const;
	//ssyQuat			operator*( float a ) const;
	//ssyQuat &			operator*=( const ssyQuat &a );
	//ssyQuat &			operator*=( float a );

	//friend ssyQuat	operator*( const float a, const ssyQuat &b );
	//friend ssyVec3	operator*( const ssyVec3 &a, const ssyQuat &b );

	//bool				Compare( const ssyQuat &a ) const;						// exact compare, no epsilon
	//bool				Compare( const ssyQuat &a, const float epsilon ) const;	// compare with epsilon
	//bool				operator==(	const ssyQuat &a ) const;					// exact compare, no epsilon
	//bool				operator!=(	const ssyQuat &a ) const;					// exact compare, no epsilon

	//ssyQuat			Inverse() const;
	//float				Length() const;
	//ssyQuat &			Normalize();

	//float				CalcW() const;
	//int				GetDimension() const;

	//idAngles			ToAngles() const;
	//idRotation		ToRotation() const;
	//idMat3			ToMat3() const;
	//idMat4			ToMat4() const;
	//idCQuat			ToCQuat() const;
	//ssyVec3			ToAngularVelocity() const;
	//const float *		ToFloatPtr() const;
	//float *			ToFloatPtr();
	//const char *		ToString( int precision = 2 ) const;

	//ssyQuat &			Slerp( const ssyQuat &from, const ssyQuat &to, float t );
	//ssyQuat &			Lerp( const ssyQuat &from, const ssyQuat &to, const float t );
};


inline void ssyQuat::Set(const float in_x, const float in_y, const float in_z, const float in_w)
{
	this->x = in_x;
	this->y = in_y;
	this->z = in_z;
	this->w = in_w;
}