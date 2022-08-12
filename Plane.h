// Alessandro Pegoraro, 2022

#pragma once

#include "Vector.h"

namespace APRaycaster
{
	class Plane final
	{
	public:

		Plane() = delete;
		inline Plane(const Vector& Normal, const Vector& Point)
			: mNormal(Normal.GetNormalized()), mK(-Vector::Dot(Normal, Point)) { }
		inline Plane(const Plane& InToCopy) : mNormal(InToCopy.mNormal), mK(InToCopy.mK) { }

		inline Vector GetPlaneNormal() const { return mNormal; }
		inline Scalar GetPlaneCoefficent() const { return mK; }

		inline void ChangePlaneLocation(const Vector& Point) { mK = -Vector::Dot(mNormal, Point); }

		// Operators overload
		inline Plane& operator= (const Plane& InToCopy)
		{
			mNormal = InToCopy.mNormal;
			mK = InToCopy.mK;

			return *this;
		}

		friend bool operator== (const Plane& InA, const Plane& InB);
		friend bool operator!= (const Plane& InA, const Plane& InB);
		// Operators overload Ends

	private:

		Vector mNormal;
		Scalar mK; // Equivalent to -(PlaneNormal dot PointOnThePlane)
	};
}
