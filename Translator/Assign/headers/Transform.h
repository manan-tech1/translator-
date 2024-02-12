#pragma once 
#include <vector>
#include "Triangle.h"

class Transform
{
    public:
        Transform(std::vector<Triangle>& triangles);
        ~Transform();

        void translate(double transX, double transY, double transZ);
        void scale(double scale);
        void rotate(double phi, double omg, double kap);

    private:
        Point3D translatedVertex(Point3D point, double transX, double transY, double transZ);
        Point3D scaledVertex(Point3D point, double scale);
        Point3D rotatedVertex(Point3D point, double phi, double omg, double kap);
        std::vector<Triangle>& mTriangles_Transform;
};
