#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include "../headers/Point3D.h"
#include "../headers/STLReader.h"
#include "../headers/Triangle.h"
#include "../headers/Triangulation.h"

using namespace std;

reader ::reader(std::string filePath)
{
    mFilePath=filePath;
}

reader ::~reader()
{
    
}
 
void reader::getTriangles(std::vector<Triangle>& triangles) 
{
    std::ifstream readFile;
    readFile.open(mFilePath);
    if (!readFile.is_open())
    { 
        std::cout<<"File not exist"<<std::endl;
        return ;
    }

    std::string line;

    while (std::getline(readFile, line)) 
    {
        std::cout<<line<<std::endl;
        if (line.find("vertex") != std::string::npos) 
        {
            std::istringstream iss(line);
            std::string token;
            double x, y, z;
 
            iss >> token >> x >> y >> z;
        
            Point3D point1(x, y, z);

            std::getline(readFile,line);
            std::cout<<line<<std::endl;
            std::istringstream iss1(line);
            iss1 >> token >> x >> y >> z;
            Point3D point2(x, y, z);

            std::getline(readFile,line);
            std::cout<<line<<std::endl;
            std::istringstream iss2(line);
            iss2 >> token >> x >> y >> z;
            Point3D point3(x, y, z);
            
            Triangle triangle(point1, point2, point3);
            triangles.push_back(triangle);
        }

    }
    readFile.close();
}
