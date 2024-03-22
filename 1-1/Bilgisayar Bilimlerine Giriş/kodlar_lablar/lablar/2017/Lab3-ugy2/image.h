#ifndef IMAGE_H
#define IMAGE_H

class Image
{
      public:
             Image();
             Image(int numRows, int numCols, int grayLevels);
             ~Image();
             Image(const Image& oldImage);
             void operator=(const Image&);
             void setImageInfo(int numRows, int numCols, int maxVal);
             void getImageInfo(int &numRows, int &numCols, int &maxVal);
             int getPixelVal(int row, int col);
             void setPixelVal(int row, int col, int value);
             bool inBounds(int row, int col);
      private:
              int N; // number of rows
              int M; // number of columns
              int Q; // number of gray levels
              int **pixelVal;
};

#endif
