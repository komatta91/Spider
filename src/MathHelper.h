#ifndef MATHHELPER_H
#define MATHHELPER_H

#include <Windows.h>

class MathHelper
{
public:
	static float RandF()
	{
		return (float)(rand()) / (float)RAND_MAX;
	}

	static float RandF(float a, float b)
	{
		return a + RandF()*(b-a);
	}

	template<typename T>
	static T Min(const T& a, const T& b)
	{
		return a < b ? a : b;
	}

	template<typename T>
	static T Max(const T& a, const T& b)
	{
		return a > b ? a : b;
	}
	 
	template<typename T>
	static T Lerp(const T& a, const T& b, float t)
	{
		return a + (b-a)*t;
	}

	template<typename T>
	static T Clamp(const T& x, const T& low, const T& high)
	{
		return x < low ? low : (x > high ? high : x); 
	}

	static float AngleFromXY(float x, float y);
		static const float Infinity;
	static const float Pi;
};

#endif // MATHHELPER_H