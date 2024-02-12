#pragma once
#include "Triangulation.h"

class reader
{
    public:
        reader(std::string filePath);
        ~reader();
   
        void getTriangles(std::vector<Triangle>& triangles);

    private:
        std::string mFilePath;
};
