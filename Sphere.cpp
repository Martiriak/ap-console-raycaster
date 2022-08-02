// Alessandro Pegoraro, 2022

#include "Sphere.h"

namespace APRaycaster
{
	bool operator==(const Sphere& InA, const Sphere& InB)
	{
		return InA.Center == InB.Center && Equal(InA.Radius, InB.Radius);
	}

	bool operator!=(const Sphere& InA, const Sphere& InB) { return !operator==(InA, InB); }
}