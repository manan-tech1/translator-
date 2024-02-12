#pragma once
#include<vector>
#include<string>
#include "../headers/Triangle.h"

class writer
{
    public:
    writer();
    ~writer();

    void write(std::string filePath ,std::vector<Triangle>& triangles);

};
