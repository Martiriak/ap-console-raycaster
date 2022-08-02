// Alessandro Pegoraro, 2022

#include "Capsule.h"

namespace APRaycaster
{
	bool operator==(const Capsule& InA, const Capsule& InB)
	{
		return InA.CenterA == InB.CenterA && InA.CenterB == InB.CenterB && InA.Radius == InB.Radius;
	}

	bool operator!=(const Capsule& InA, const Capsule& InB) { return !operator==(InA, InB); }
}
