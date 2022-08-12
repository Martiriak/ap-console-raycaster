// Alessandro Pegoraro, 2022

#pragma once

#include "Vector.h"

namespace APRaycaster
{
	class Ray final
	{
	public:
		
		Ray() = delete;
		inline Ray(const Vector& Origin, const Vector& Direction)
			: mOrigin(Origin), mDirection(Direction.GetNormalized()) { }
		inline Ray(const Ray& InToCopy) : mOrigin(InToCopy.mOrigin), mDirection(InToCopy.mDirection) { }

		inline Vector GetOrigin() const { return mOrigin; }
		inline Vector GetDirection() const { return mDirection; }
		inline void SetOrigin(const Vector& InNewOrigin) { mOrigin = InNewOrigin; }
		inline void SetDirection(const Vector& InNewDirection) { mOrigin = InNewDirection.GetNormalized(); }

		inline Vector GetPointOnRay(const Scalar K) const { return mOrigin + (K * mDirection); }


		// Operators overload
		inline Ray& operator= (const Ray& InToCopy)
		{
			mOrigin = InToCopy.mOrigin;
			mDirection = InToCopy.mDirection;

			return *this;
		}

		friend bool operator== (const Ray& InA, const Ray& InB);
		friend bool operator!= (const Ray& InA, const Ray& InB);
		// Operators overload End

	private:

		Vector mOrigin;
		Vector mDirection;
	};

	struct Sphere;
	struct Capsule;
	class Plane;

	bool Raycast(const Vector& InOrigin, const Vector& InDirection, const Plane& InPlane, Vector& OutHitPoint, Vector& OutHitNorm, Scalar& OutDistance);
	bool Raycast(const Vector& InOrigin, const Vector& InDirection, const Capsule& InCapsule, Vector& OutHitPoint, Vector& OutHitNorm, Scalar& OutDistance);
	bool Raycast(const Vector& InOrigin, const Vector& InDirection, const Sphere& InSphere, Vector& OutHitPoint, Vector& OutHitNorm, Scalar& OutDistance);
	bool Raycast(const Ray& InRay, const Plane& InPlane, Vector& OutHitPoint, Vector& OutHitNorm, Scalar& OutDistance);
	bool Raycast(const Ray& InRay, const Capsule& InCapsule, Vector& OutHitPoint, Vector& OutHitNorm, Scalar& OutDistance);
	bool Raycast(const Ray& InRay, const Sphere& InSphere, Vector& OutHitPoint, Vector& OutHitNorm, Scalar& OutDistance);
}
