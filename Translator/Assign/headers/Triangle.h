#pragma once
#include "Point3D.h"
#include "Shape.h"

class Triangle
{
    public:
        Triangle(Point3D p1, Point3D p2, Point3D p3);
        ~Triangle();

        Point3D v1();
        Point3D v2();
        Point3D v3();

    private:
        Point3D mV1;
        Point3D mV2;
        Point3D mV3;
};