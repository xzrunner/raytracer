#ifndef _RT_POINT3D_H_
#define _RT_POINT3D_H_

#include "Vector3D.h"

namespace rt
{

class Point3D
{
public:
	float x, y, z;

public:
	Point3D() : x(0), y(0), z(0) {}
	Point3D(float x, float y, float z)
		: x(x), y(y), z(z) {}
// 	Point3D& operator = (const Point3D& p) {
// 		x = p.x; y = p.y; z = p.z;
// 	}

	Point3D operator + (const Vector3D& v) const;

	Vector3D operator - (const Point3D& p) const;

	float Distance(const Point3D& p) const;
	float DistanceSquared(const Point3D& p) const;

}; // Point3D

inline Point3D Point3D::operator + (const Vector3D& v) const
{
	return Point3D(x + float(v.x), y + float(v.y), z + float(v.z));
}

inline Vector3D Point3D::operator - (const Point3D& p) const
{
	return Vector3D(x - p.x, y - p.y, z - p.z);
}

inline float Point3D::Distance(const Point3D& p) const
{
	return sqrt(DistanceSquared(p));
}

inline float Point3D::DistanceSquared(const Point3D& p) const
{
	return (x - p.x) * (x - p.x) 
		+  (y - p.y) * (y - p.y)
		+  (z - p.z) * (z - p.z);
}

Point3D 
operator * (const Matrix& mat, const Point3D& p);

}

#endif // _RT_POINT3D_H_