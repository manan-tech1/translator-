#include <iostream>
#include <cmath>
#include "../headers/Triangle.h"
#include "../headers/Point3D.h"
#include "../headers/VertexVaule.h"

using namespace std;

VertexVal::VertexVal(std::vector<Triangle> triangles)
{
    
}

VertexVal::~VertexVal()
{

}

Point3D VertexVal::getCenter()
{
    return mCenter;
}
