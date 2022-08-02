// Alessandro Pegoraro, 2022

#include "Plane.h"

namespace APRaycaster
{
	bool operator==(const Plane& InA, const Plane& InB)
	{
		return InA.mNormal == InB.mNormal && InA.mK == InB.mK;
	}

	bool operator!=(const Plane& InA, const Plane& InB) { return !operator==(InA, InB); }
}