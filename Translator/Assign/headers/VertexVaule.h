#pragma once
#include <vector>
#include "Triangle.h"

class VertexVal
{
    public:
        VertexVal(std::vector<Triangle> triangles);
        ~VertexVal();
        Point3D getCenter();

    private:
        Point3D mMin;
        Point3D mMax;
        Point3D mCenter;
        // std::vector<Point3D> mData;
        // double mRadius;
};