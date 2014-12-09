//***************************************************************************************
// MathHelper.cpp Frank Luna (C) 2011 Wszelkie prawa zastrze¿one.
//***************************************************************************************

#include "MathHelper.h"
#include <float.h>
#include <cmath>

const float MathHelper::Infinity = FLT_MAX;
const float MathHelper::Pi       = 3.1415926535f;

float MathHelper::AngleFromXY(float x, float y)
{
	float theta = 0.0f;
 
	if(x >= 0.0f) 
	{
		theta = atanf(y / x); // in [-pi/2, +pi/2]

		if(theta < 0.0f)
			theta += 2.0f*Pi; // in [0, 2*pi).
	}

	else      
		theta = atanf(y/x) + Pi; // in [0, 2*pi).

	return theta;
}