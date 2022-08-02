// Alessandro Pegoraro, 2022

#include "Vector.h"

namespace APRaycaster
{
	Vector operator+(Vector A, const Vector& InB) { A += InB; return A; }

	Vector operator-(Vector A, const Vector& InB) { A -= InB; return A; }

	Vector operator*(Vector A, const Scalar K) { A *= K; return A; }

	Vector operator*(const Scalar K, Vector A) { A *= K; return A; }

	Vector operator/(Vector A, const Scalar K) { A /= K; return A; }

	Vector operator/(const Scalar K, Vector A) { A /= K; return A; }

	bool operator==(const Vector& InA, const Vector& InB)
	{
		return InA.x == InB.x && InA.y == InB.y && InA.z == InB.z;
	}

	// Doesn't interally call operator== to make less function calls.
	bool operator!=(const Vector& InA, const Vector& InB)
	{
		return InA.x != InB.x && InA.y != InB.y && InA.z != InB.z;
	}
}
