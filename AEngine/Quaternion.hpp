#pragma once
#ifndef __QUATERNION_HPP__
#define __QUATERNION_HPP__

#include"../Utility/onwind.h"
#include<DirectXMath.h>
#include"Vector.hpp"
#include<cmath>
using namespace DirectX;

namespace Math
{
	class Quaternion
	{
		XMFLOAT4 m_quaternion;
	public:
		Quaternion() = default;
		Quaternion(const Quaternion& q) :m_quaternion(q.m_quaternion)
		{
		}
		Quaternion(float x, float y, float z, float w) :m_quaternion(x, y, z, w)
		{
		}

		/////////////////////////////////////////////////////////////////////////
		__FasterFunc(float) X()
		{
			return m_quaternion.x;
		}

		__FasterFunc(void) X(float x)
		{
			m_quaternion.x = x;
		}

		__FasterFunc(float) Y()
		{
			return m_quaternion.y;
		}

		__FasterFunc(void) Y(float y)
		{
			m_quaternion.y = y;
		}

		__FasterFunc(float) Z()
		{
			return m_quaternion.z;
		}

		__FasterFunc(void) Z(float z)
		{
			m_quaternion.z = z;
		}

		__FasterFunc(float) W()
		{
			return m_quaternion.w;
		}

		__FasterFunc(void) W(float w)
		{
			m_quaternion.w = w;
		}

		////////////////////////////////////////////////////////////////////////////////////

		static Vector3&& Eular()
		{
			Vector3 temp;
			return std::move(temp);
		}

		static Quaternion&& Eular(const Vector3& v)
		{
			Quaternion temp;
			return std::move(temp);
		}
	};
}


#endif // !__QUATERNION_HPP__
