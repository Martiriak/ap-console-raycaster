// Alessandro Pegoraro, 2022

#pragma once

namespace APRaycaster
{
	using Scalar = float;

	inline bool Equal(const Scalar A, const Scalar B)
	{
		static const Scalar TOLERANCE = 1e-5f;

		return (A > B - TOLERANCE) && (A < B + TOLERANCE);
	}
}
