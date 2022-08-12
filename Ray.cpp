// Alessandro Pegoraro, 2022

#include <cmath>
#include "Vector.h"
#include "Scalar.h"
#include "Ray.h"
#include "Shapes.h"

namespace APRaycaster
{
    bool operator==(const Ray& InA, const Ray& InB)
    {
        return InA.mOrigin == InB.mOrigin && InA.mDirection == InB.mDirection;
    }

    bool operator!=(const Ray& InA, const Ray& InB) { return !operator==(InA, InB); }




    bool Raycast(const Ray& InRay, const Plane& InPlane, Vector& OutHitPoint, Vector& OutHitNorm, Scalar& OutDistance)
    {
        const Scalar PlaneAndRayConcordance = Vector::Dot(InRay.GetDirection(), InPlane.GetPlaneNormal());

        if (Equal(PlaneAndRayConcordance, 0.f)) return false;

        const Scalar Nominator = Vector::Dot(InRay.GetOrigin(), InPlane.GetPlaneNormal()) + InPlane.GetPlaneCoefficent();
        const Scalar Coefficent = -(Nominator / PlaneAndRayConcordance);

        if (Coefficent < 0.f) return false;

        OutHitPoint = InRay.GetPointOnRay(Coefficent);
        OutHitNorm = InPlane.GetPlaneNormal();
        OutDistance = Coefficent;

        return true;
    }

    bool Raycast(const Ray& InRay, const Sphere& InSphere, Vector& OutHitPoint, Vector& OutHitNorm, Scalar& OutDistance)
    {
        const Vector v = InRay.GetOrigin() - InSphere.Center;
        const Scalar b = Vector::Dot(InRay.GetDirection(), v);
        const Scalar Delta = b * b - v.GetSqrMagnitude() + (InSphere.Radius * InSphere.Radius);

        if (Delta < 0.f) return false;

        const Scalar Coefficent = -b - std::sqrt(Delta);

        if (Coefficent < 0.f) return false;

        OutHitPoint = InRay.GetPointOnRay(Coefficent);
        OutHitNorm = (OutHitPoint - InSphere.Center).GetNormalized();
        OutDistance = Coefficent;

        return true;
    }



    bool Raycast(const Vector& InOrigin, const Vector& InDirection, const Plane& InPlane, Vector& OutHitPoint, Vector& OutHitNorm, Scalar& OutDistance)
    {
        const Ray TmpRay(InOrigin, InDirection);
        return Raycast(TmpRay, InPlane, OutHitPoint, OutHitNorm, OutDistance);
    }

    bool Raycast(const Vector& InOrigin, const Vector& InDirection, const Capsule& InCapsule, Vector& OutHitPoint, Vector& OutHitNorm, Scalar& OutDistance)
    {
        const Ray TmpRay(InOrigin, InDirection);
        return Raycast(TmpRay, InCapsule, OutHitPoint, OutHitNorm, OutDistance);
    }

    bool Raycast(const Vector& InOrigin, const Vector& InDirection, const Sphere& InSphere, Vector& OutHitPoint, Vector& OutHitNorm, Scalar& OutDistance)
    {
        const Ray TmpRay(InOrigin, InDirection);
        return Raycast(TmpRay, InSphere, OutHitPoint, OutHitNorm, OutDistance);
    }
}
