// Alessandro Pegoraro, 2022

#pragma once

#include <cmath>
#include "Scalar.h"

namespace APRaycaster
{
	struct Vector final
	{
		Scalar x, y, z;

		inline Vector() : x(0.f), y(0.f), z(0.f) { }
		inline Vector(const Scalar _value) : x(_value), y(_value), z(_value) { }
		inline Vector(const Scalar _x, const Scalar _y, const Scalar _z)
			: x(_x), y(_y), z(_z) { }

		inline Vector(const Vector& InVectorToCopy)
			: x(InVectorToCopy.x), y(InVectorToCopy.y), z(InVectorToCopy.z) { }


		// Operators overload
		inline Vector& operator= (const Vector& InVectorToCopy)
		{
			x = InVectorToCopy.x;
			y = InVectorToCopy.y;
			z = InVectorToCopy.z;

			return *this;
		}

		inline Vector operator-() const
		{
			return Vector(-x, -y, -z);
		}

		inline Vector& operator+= (const Vector& InB)
		{
			x += InB.x;
			y += InB.y;
			z += InB.z;

			return *this;
		}

		inline Vector& operator-= (const Vector& InB)
		{
			x -= InB.x;
			y -= InB.y;
			z -= InB.z;

			return *this;
		}

		inline Vector& operator*= (const Scalar K)
		{
			x *= K;
			y *= K;
			z += K;

			return *this;
		}

		inline Vector& operator/= (const Scalar K)
		{
			x /= K;
			y /= K;
			z /= K;

			return *this;
		}

		friend Vector operator+ (Vector A, const Vector& InB);
		friend Vector operator- (Vector A, const Vector& InB);
		friend Vector operator* (Vector A, const Scalar K);
		friend Vector operator* (const Scalar K, Vector A);
		friend Vector operator/ (Vector A, const Scalar K);
		friend Vector operator/ (const Scalar K, Vector A);

		friend bool operator== (const Vector& InA, const Vector& InB);
		friend bool operator!= (const Vector& InA, const Vector& InB);
		// Operators overload End


		inline Scalar GetSqrMagnitude() const { return Vector::Dot(*this, *this); }
		inline Scalar GetMagnitude() const { return std::sqrt(GetSqrMagnitude()); }
		inline Vector GetNormalized() const { return *this / GetMagnitude(); }
		inline void Normalize()
		{
			const Scalar Magnitude = GetMagnitude();
			x /= Magnitude;
			y /= Magnitude;
			z /= Magnitude;
		}


		inline static Scalar Dot(const Vector& InA, const Vector& InB)
		{
			return (InA.x * InB.x) + (InA.y * InB.y) + (InA.z * InB.z);
		}

		inline static Vector Cross(const Vector& InA, const Vector& InB)
		{
			const Scalar X = (InA.y * InB.z) - (InA.z * InB.y);
			const Scalar Y = (InA.z * InB.x) - (InA.x * InB.z);
			const Scalar Z = (InA.x * InB.y) - (InA.y * InB.x);

			return Vector(X, Y, Z);
		}

		inline static Vector Zero() { return Vector(0.f); }
		inline static Vector One() { return Vector(1.f); }
		inline static Vector Forward() { return Vector(0.f, 0.f, 1.f); }
		inline static Vector Up() { return Vector(0.f, 1.f, 0.f); }
		inline static Vector Right() { return Vector(1.f, 0.f, 0.f); }
	};
}
