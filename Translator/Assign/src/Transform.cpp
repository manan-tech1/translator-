#include <iostream>
#include "../headers/Transform.h"
#include "../headers/Matrix.h"
#include "../headers/Point3D.h"
#include "../headers/VertexVaule.h"

Transform::Transform(std::vector<Triangle>& triangles)
: mTriangles_Transform(triangles)
{
    
}

Transform::~Transform()
{

}

void Transform::translate(double transX, double transY, double transZ) 
{
    for (int i = 0; i < mTriangles_Transform.size(); i++) {
        Point3D p1 = translatedVertex(mTriangles_Transform[i].v1(), transX, transY, transZ);
        Point3D p2 = translatedVertex(mTriangles_Transform[i].v2(), transX, transY, transZ);
        Point3D p3 = translatedVertex(mTriangles_Transform[i].v3(), transX, transY, transZ);
        mTriangles_Transform[i] = Triangle(p1, p2, p3);
    }

}

Point3D Transform::translatedVertex(Point3D point, double transX, double transY, double transZ)
{
    Matrix matrix;
    std::vector<std::vector<double>> transMatrix = matrix.createTranslationMatrix(transX, transY, transZ);
    std::vector<double> pointDefault = {point.x(), point.y(), point.z(), 1.0};
    std::vector<double> transfromedPoint = matrix.matrixMultiplication(transMatrix, pointDefault);
    return Point3D(transfromedPoint[0], transfromedPoint[1], transfromedPoint[2]);
}

void Transform::scale(double scale)
{
    VertexVal vertexVal(mTriangles_Transform);
    Point3D center=vertexVal.getCenter();

   translate(-center.x(), -center.y(), -center.z());

    for (int i = 0; i < mTriangles_Transform.size(); i++)
    {
        Point3D p1 = scaledVertex(mTriangles_Transform[i].v1(), scale);
        Point3D p2 = scaledVertex(mTriangles_Transform[i].v2(), scale);
        Point3D p3 = scaledVertex(mTriangles_Transform[i].v3(), scale);
        mTriangles_Transform[i] = Triangle(p1, p2, p3);
    }
    
    translate(center.x(),center.y(),center.z());
}

Point3D Transform::scaledVertex(Point3D point, double scale)
{
    Matrix matrix;
    std::vector<std::vector<double>> scalingMatrix = matrix.createScaleMatrix(scale);
    std::vector<double> pointDefault = {point.x(), point.y(), point.z(), 1.0};
    std::vector<double> scaledPoint = matrix.matrixMultiplication(scalingMatrix, pointDefault);

    double scaledX = scaledPoint[0] / scaledPoint[3];
    double scaledY = scaledPoint[1] / scaledPoint[3];
    double scaledZ = scaledPoint[2] / scaledPoint[3];

    return Point3D(scaledX, scaledY, scaledZ);
}

void Transform::rotate(double phi, double omg, double kap) 
{
    for (int i = 0; i < mTriangles_Transform.size(); i++) 
    {
        Point3D p1 = rotatedVertex(mTriangles_Transform[i].v1(), phi, omg, kap);
        Point3D p2 = rotatedVertex(mTriangles_Transform[i].v2(), phi, omg, kap);
        Point3D p3 = rotatedVertex(mTriangles_Transform[i].v3(), phi, omg, kap);
        mTriangles_Transform[i] = Triangle(p1, p2, p3);
    }

}

Point3D Transform::rotatedVertex(Point3D point, double phi, double omg, double kap)
{
    Matrix matrix;
    std::vector<std::vector<double>> rotateMatrix = matrix.createRotationMatrix(phi, omg, kap);
    std::vector<double> pointDefault = {point.x(), point.y(), point.z(), 1.0};
    std::vector<double> rotatedPoint = matrix.matrixMultiplication(rotateMatrix, pointDefault);
    return Point3D(rotatedPoint[0], rotatedPoint[1], rotatedPoint[2]);
}