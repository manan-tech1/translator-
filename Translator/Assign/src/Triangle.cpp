#include "../headers/Triangle.h"
#include "../headers/Point3D.h"

using namespace std;

Triangle::Triangle(Point3D p1, Point3D p2, Point3D p3)
: mV1(0,0,0),
  mV2(0,0,0),
  mV3(0,0,0)
{
    mV1 = p1;
    mV2 = p2;
    mV3 = p3;
}

Triangle::~Triangle()
{
}

Point3D Triangle::v1()
{
    return mV1;
}

Point3D Triangle::v2()
{
    return mV2;
}

Point3D Triangle::v3()
{
    return mV3;
}