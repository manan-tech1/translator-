#include<math.h>
#include "../headers/Matrix.h"
#include "../headers/Point3D.h"

Matrix::Matrix() 
{

}

Matrix::~Matrix()
{

}

std::vector<std::vector<double>> Matrix::createIdentityMatrix(int size)
{
    std::vector<std::vector<double>> identityMatrix(size, std::vector<double>(size, 0.0));
    for (int i = 0; i < size; i++) {
        identityMatrix[i][i] = 1.0;
    }
    return identityMatrix;
}

std::vector<std::vector<double>> Matrix::createTranslationMatrix(double translationX, double translationY, double translationZ)
{
    std::vector<std::vector<double>> translationMatrix = createIdentityMatrix(4);

    translationMatrix[0][3] = translationX;
    translationMatrix[1][3] = translationY;
    translationMatrix[2][3] = translationZ;

    return translationMatrix;
}

std::vector<std::vector<double>> Matrix::createRotationMatrix(double phi, double omg, double kap)
{
    std::vector<std::vector<double>> rotationMatrix = createIdentityMatrix(4);

    rotationMatrix[0][0] = cos(phi)*cos(kap);
    rotationMatrix[0][1] = cos(omg)*sin(kap)+sin(omg)*sin(phi)*cos(kap);
    rotationMatrix[0][2] = sin(omg)*sin(kap)-cos(omg)*sin(phi)*cos(kap);
 
    rotationMatrix[1][0] = -cos(phi)*sin(kap);
    rotationMatrix[1][1] = cos(omg)*cos(kap)-sin(omg)*sin(phi)*sin(kap);
    rotationMatrix[1][2] = sin(omg)*cos(kap)+cos(omg)*sin(phi)*sin(kap);
 
    rotationMatrix[2][0] = sin(phi);
    rotationMatrix[2][1] = -sin(omg)*cos(phi);
    rotationMatrix[2][2] = cos(omg)*cos(phi);

    return rotationMatrix;
}

std::vector<std::vector<double>> Matrix::createScaleMatrix(double scale)
{
    std::vector<std::vector<double>> scaleMatrix = createIdentityMatrix(4);

    scaleMatrix[0][0] = scale;
    scaleMatrix[1][1] = scale;
    scaleMatrix[2][2] = scale;

    return scaleMatrix;
}

std::vector<double> Matrix::matrixMultiplication(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vector) 
{
    std::vector<double> result(4, 0.0);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }

    return result;
}

