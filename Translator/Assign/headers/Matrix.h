#pragma once
#include <vector>
#include "Point3D.h"

class Matrix
{
    public:
        Matrix();
        ~Matrix();
    
        
        std::vector<std::vector<double>> createIdentityMatrix(int size);
        std::vector<std::vector<double>> createTranslationMatrix(double transX, double transY, double transZ);
        std::vector<std::vector<double>> createScaleMatrix(double scale);
        std::vector<std::vector<double>> createRotationMatrix(double phi, double omg, double kap);
        std::vector<double> matrixMultiplication(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vector);
};
