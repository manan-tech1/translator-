
#include "../headers/STLWriter.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../headers/Point3D.h"
using namespace std;

writer ::writer()
{

}

writer ::~writer()
{

}

void writer::write(std::string filePath ,std::vector<Triangle>& triangles)
{
  std::ofstream outFile;
  outFile.open(filePath);
  
  for (Triangle triangle:triangles)
  {
      outFile << triangle.v1().x() << " " << triangle.v1().y() << " "<< triangle.v1().z() << std::endl;
      outFile << triangle.v2().x() << " " << triangle.v2().y() << " "<< triangle.v2().z() << std::endl;
      outFile << triangle.v3().x() << " " << triangle.v3().y() << " "<< triangle.v3().z() << std::endl;
      outFile << triangle.v1().x() << " " << triangle.v1().y() << " "<< triangle.v1().z() << std::endl;
  }
  outFile.close();
};
