// Alessandro Pegoraro, 2022

#include "Ray.h"

namespace APRaycaster
{
    bool operator==(const Ray& InA, const Ray& InB)
    {
        return InA.mOrigin == InB.mOrigin && InA.mDirection == InB.mDirection;
    }

    bool operator!=(const Ray& InA, const Ray& InB) { return !operator==(InA, InB); }
}
