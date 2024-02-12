#include <fstream>
#include <iostream>
#include <cmath>
#include "./headers/STLReader.h"
#include "./headers/STLWriter.h"
#include "./headers/Transform.h"

using namespace std;

int main()
{
    std::vector<Triangle> triangles;
    reader reader("cube.stl");
    reader.getTriangles(triangles);

    Triangulation triangulation(triangles);

    writer writer;

    std::vector<Triangle> outTriangles=triangulation.triangles();

    Transform transform(outTriangles);
    transform.scale(1);

    writer.write("cube.txt", outTriangles);

    return 0;
}
