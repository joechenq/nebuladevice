/* [SCE CONFIDENTIAL DOCUMENT]
 * $PSLibId$
 *                Copyright (C) 2006 Sony Computer Entertainment Inc.
 *                                                All Rights Reserved.
 */

#ifndef __BOX_H__
#define __BOX_H__

#include <math.h>
#include <vectormath_aos.h>

using namespace Vectormath::Aos;

enum FeatureType { F, E, V };

//----------------------------------------------------------------------------
// Box
//----------------------------------------------------------------------------

class Box
{
public:
	Vector3 half;

	inline Box()
	{}
	inline Box(Vector3 half_);
	inline Box(float hx, float hy, float hz);

	inline void Set(Vector3 half_);
	inline void Set(float hx, float hy, float hz);

	inline Vector3 GetAABB(const Matrix3& rotation) const;
};

inline
Box::Box(Vector3 half_)
{
	Set(half_);
}

inline
Box::Box(float hx, float hy, float hz)
{
	Set(hx, hy, hz);
}

inline
void
Box::Set(Vector3 half_)
{
	half = half_;
}

inline
void
Box::Set(float hx, float hy, float hz)
{
	half = Vector3(hx, hy, hz);
}

inline
Vector3
Box::GetAABB(const Matrix3& rotation) const
{
	return absPerElem(rotation) * half;
}

//-------------------------------------------------------------------------------------------------
// BoxPoint
//-------------------------------------------------------------------------------------------------

class BoxPoint
{
public:
	BoxPoint() : localPoint(0.0f) {}

	Point3      localPoint;
	FeatureType featureType;
	int         featureIdx;

	inline void setVertexFeature(int plusX, int plusY, int plusZ);
	inline void setEdgeFeature(int dim0, int plus0, int dim1, int plus1);
	inline void setFaceFeature(int dim, int plus);

	inline void getVertexFeature(int & plusX, int & plusY, int & plusZ) const;
	inline void getEdgeFeature(int & dim0, int & plus0, int & dim1, int & plus1) const;
	inline void getFaceFeature(int & dim, int & plus) const;
};

inline
void
BoxPoint::setVertexFeature(int plusX, int plusY, int plusZ)
{
	featureType = V;
	featureIdx = plusX << 2 | plusY << 1 | plusZ;
}

inline
void
BoxPoint::setEdgeFeature(int dim0, int plus0, int dim1, int plus1)
{
	featureType = E;

	if (dim0 > dim1) {
		featureIdx = plus1 << 5 | dim1 << 3 | plus0 << 2 | dim0;
	} else {
		featureIdx = plus0 << 5 | dim0 << 3 | plus1 << 2 | dim1;
	}
}

inline
void
BoxPoint::setFaceFeature(int dim, int plus)
{
	featureType = F;
	featureIdx = plus << 2 | dim;
}

inline
void
BoxPoint::getVertexFeature(int & plusX, int & plusY, int & plusZ) const
{
	plusX = featureIdx >> 2;
	plusY = featureIdx >> 1 & 1;
	plusZ = featureIdx & 1;
}

inline
void
BoxPoint::getEdgeFeature(int & dim0, int & plus0, int & dim1, int & plus1) const
{
	plus0 = featureIdx >> 5;
	dim0 = featureIdx >> 3 & 3;
	plus1 = featureIdx >> 2 & 1;
	dim1 = featureIdx & 3;
}

inline
void
BoxPoint::getFaceFeature(int & dim, int & plus) const
{
	plus = featureIdx >> 2;
	dim = featureIdx & 3;
}

#endif /* __BOX_H__ */
