#include "..\headers\Triangulation.h"
#include<map>
#include<vector>
#include<iostream>

Triangulation::Triangulation(std::vector<Triangle> triangles)
//:mBBox(triangles)
{
    mTriangles=triangles;
}

Triangulation::~Triangulation()
{
    
}

vector<Triangle> & Triangulation::triangles()
{
    return mTriangles;
}

vector<Point3D> & Triangulation::uniquePoints()
{
    return mUniquePoints;
}

vector<Point3D> & Triangulation::uniqueNormal()
{
    return mUniqueNormal;
}