// Alessandro Pegoraro, 2022

#pragma once

#include "Vector.h"
#include "Scalar.h"

namespace APRaycaster
{
	struct Sphere final
	{
		Vector Center;
		Scalar Radius;

		Sphere() = delete;
		inline Sphere(const Vector& _center, const Scalar _radius) : Center(_center), Radius(_radius) { }
		inline Sphere(const Sphere& InToCopy) : Center(InToCopy.Center), Radius(InToCopy.Radius) { }

		// Operators overload
		inline Sphere& operator= (const Sphere& InToCopy)
		{
			Center = InToCopy.Center;
			Radius = InToCopy.Radius;

			return *this;
		}

		friend bool operator== (const Sphere& InA, const Sphere& InB);
		friend bool operator!= (const Sphere& InA, const Sphere& InB);
		// Operators overload End
	};
}
