// Alessandro Pegoraro, 2022

#pragma once

#include "Vector.h"
#include "Scalar.h"

namespace APRaycaster
{
	struct Capsule final
	{
		Vector CenterA;
		Vector CenterB;
		Scalar Radius;

		Capsule() = delete;
		inline Capsule(const Vector& InCenterA, const Vector& InCenterB, const Scalar _Radius)
			: CenterA(InCenterA), CenterB(InCenterB), Radius(_Radius) { }
		inline Capsule(const Capsule& InToCopy)
			: CenterA(InToCopy.CenterA), CenterB(InToCopy.CenterB), Radius(InToCopy.Radius) { }

		inline Scalar GetLength() const { return (CenterA - CenterB).GetMagnitude(); }
		inline Scalar GetSqrLength() const { return (CenterA - CenterB).GetSqrMagnitude(); }

		// Operators overload
		inline Capsule& operator= (const Capsule& InToCopy)
		{
			CenterA = InToCopy.CenterA;
			CenterB = InToCopy.CenterB;
			Radius = InToCopy.Radius;

			return *this;
		}

		friend bool operator==(const Capsule& InA, const Capsule& InB);
		friend bool operator!=(const Capsule& InA, const Capsule& InB);
		// Operators overload End
	};
}
