#include <stdlib.h>
#include <iostream>
#include "image.h"
#include <cmath>
using namespace std;

Image::Image()
{
    N = 0;
    M = 0;
    Q = 0;
    
    pixelVal = NULL;
}

Image::Image(int numRows, int numCols, int grayLevels)
{    
    
    N = numRows;
    M = numCols;
    Q = grayLevels;
    
    pixelVal = new int *[N];
    for(int i = 0; i < N; i++)
    {
        pixelVal[i] = new int [M];
        for(int j = 0; j < M; j++)
            pixelVal[i][j] = 0;
    }
}

Image::~Image()
{
    N = 0;
    M = 0;
    Q = 0;
    
    for(int i = 0; i < N; i++)
        delete pixelVal [N];
    
    delete pixelVal;
}

Image::Image(const Image& oldImage)
{    
    N = oldImage.N;
    M = oldImage.M;
    Q = oldImage.Q;
    
    pixelVal = new int* [N];
    for(int i = 0; i < N; i++)
    {
        pixelVal[i] = new int [M];
        for(int j = 0; j < M; j++)
            pixelVal[i][j] = oldImage.pixelVal[i][j];
    }
}

void Image::operator=(const Image& oldImage)
{
    N = oldImage.N;
    M = oldImage.M;
    Q = oldImage.Q;
    
    pixelVal = new int* [N];
    for(int i = 0; i < N; i++)
    {
        pixelVal[i] = new int [M];
        for(int j = 0; j < M; j++)
            pixelVal[i][j] = oldImage.pixelVal[i][j];
    }
}

void Image::setImageInfo(int numRows, int numCols, int maxVal)
{
    N = numRows;
    M = numCols;
    Q = maxVal;
}

void Image::getImageInfo(int &numRows, int &numCols, int &maxVal)
{
    numRows = N;
    numCols = M;
    maxVal = Q;
}

int Image::getPixelVal(int row, int col)
{
    return pixelVal[row][col];
}


void Image::setPixelVal(int row, int col, int value)
{
    pixelVal[row][col] = value;
}

bool Image::inBounds(int row, int col)
/*checks to see if a pixel is within the image, returns true or false*/
{
    if(row >= N || row < 0 || col >=M || col < 0)
        return false;
    //else
    return true;
}
