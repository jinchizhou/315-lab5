#include <stdlib.h>
#include "matmul.h"

Matrix Allocate2ndMatrix(int height, int width, int init);

void matmul( float*, const float*, const float*, unsigned int, unsigned int, unsigned int);

////////////////////////////////////////////////////////////////////////////////
//! C = A * B
//! @param C          result matrix
//! @param A          matrix A 
//! @param B          matrix B
//! @param hA         height of matrix A
//! @param wB         width of matrix B
////////////////////////////////////////////////////////////////////////////////

/* You'll need to modify this function such that matrix B is accessed
 * correctly once you change the memory layout to column-major. */
void matmul(float* C, const float* A, const float* B, unsigned int hA, 
    unsigned int wA, unsigned int wB)
{
  /*for (unsigned int i = 0; i < hA; ++i)  {
    for (unsigned int j = 0; j < wB; ++j) {
      double sum = 0;
      for (unsigned int k = 0; k < wA; ++k) {
        double a = A[i * wA + k];
        double b = B[k * wB + j];
        sum += a * b;
      }
      C[i * wB + j] = (float)sum;
    }
  } 
  */
  for (unsigned int i = 0; i < hA; i += 2)  {
    for (unsigned int j = 0; j < hA; j += 2) {
      double sum1 = 0;
      double sum2 = 0;
      double sum3 = 0;
      double sum4 = 0;
      for (unsigned int k = 0; k < wA; ++k) {
      	int temp1 = i * wA + k;
      	int temp2 = (i+1) * wA + k;
      	int temp3 = j * wB + k;
      	int temp4 = (j+1) * wB + k;
        double a = A[temp1];
        double b = B[temp3];

        double c = A[temp1];
        double d = B[temp4];

        double e = A[temp2];
        double f = B[temp3];

        double g = A[temp2];
        double h = B[temp4];
        sum1 += a * b;
        sum2 += c * d;
        sum3 += e * f;
        sum4 += g * h;
      }
      C[i * wB + j] = (float)sum1;
      C[i * wB + (j+1)] = (float)sum2;
      C[(i+1) * wB + j] = (float)sum3;
      C[(i+1) * wB + (j+1)] = (float)sum4;
    }
  }
  
  /*
  for (unsigned int i = 0; i < hA; ++i)  {
    for (unsigned int j = 0; j < hA; ++j) {
      double sum = 0;
      for (unsigned int k = 0; k < wA; ++k) {
        double a = A[i * wA + k];
        double b = B[j * wB + k];
        sum += a * b;
      }
      C[i * wB + j] = (float)sum;
    }
  }
  */
   /*
  for (unsigned int i = 0; i < hA; i += 4)  {
    for (unsigned int j = 0; j < hA; j += 4) {
      double sum1 = 0;
      double sum2 = 0;
      double sum3 = 0;
      double sum4 = 0;
      double sum5 = 0;
      double sum6 = 0;
      double sum7 = 0;
      double sum8 = 0;
      double sum9 = 0;
      double sum10 = 0;
      double sum11 = 0;
      double sum12 = 0;
      double sum13 = 0;
      double sum14 = 0;
      double sum15 = 0;
      double sum16 = 0;

      for (unsigned int k = 0; k < wA; ++k) {
      	int temp1 = i * wA + k;
      	int temp2 = (i+1) * wA + k;
      	int temp3 = (i+2) * wA + k;
      	int temp4 = (i+3) * wA + k;

      	int temp5 = j * wB + k;
      	int temp6 = (j+1) * wB + k;
      	int temp7 = (j+2) * wB + k;
      	int temp8 = (j+3) * wB + k;

        double a = A[temp1];
        double b = B[temp5];

        double c = A[temp1];
        double d = B[temp6];

        double e = A[temp1];
        double f = B[temp7];

        double g = A[temp1];
        double h = B[temp8];
        //////////////////////////////////
        double i = A[temp2];
        double j = B[temp5];

        double kk = A[temp2];
        double l = B[temp6];

        double m = A[temp2];
        double n = B[temp7];

        double o = A[temp2];
        double p = B[temp8];
		//////////////////////////////////
        double q = A[temp3];
        double r = B[temp5];

        double s = A[temp3];
        double t = B[temp6];

        double u = A[temp3];
        double v = B[temp7];

        double w = A[temp3];
        double x = B[temp8];
		//////////////////////////////////
        double y = A[temp4];
        double z = B[temp5];

        double aa = A[temp4];
        double ab = B[temp6];

        double ac = A[temp4];
        double ad = B[temp7];

        double ae = A[temp4];
        double af = B[temp8];

        sum1 += a * b;
        sum2 += c * d;
        sum3 += e * f;
        sum4 += g * h;

        sum5 += i * j;
        sum6 += kk * l;
        sum7 += m * n;
        sum8 += o * p;

        sum9 += q * r;
        sum10 += s * t;
        sum11 += u * v;
        sum12 += w * x;
        
        sum13 += y * z;
        sum14 += aa * ab;
        sum15 += ac * ad;
        sum16 += ae * af;
      }
      C[i * wB + j] = (float)sum1;
      C[i * wB + (j+1)] = (float)sum2;
      C[i * wB + (j+2)] = (float)sum3;
      C[i * wB + (j+3)] = (float)sum4;

      C[(i+1) * wB + j] = (float)sum5;
      C[(i+1) * wB + (j+1)] = (float)sum6;
      C[(i+1) * wB + (j+2)] = (float)sum7;
      C[(i+1) * wB + (j+3)] = (float)sum8;

      C[(i+2) * wB + j] = (float)sum9;
      C[(i+2) * wB + (j+1)] = (float)sum10;
      C[(i+2) * wB + (j+2)] = (float)sum11;
      C[(i+2) * wB + (j+3)] = (float)sum12;

      C[(i+3) * wB + j] = (float)sum13;
      C[(i+3) * wB + (j+1)] = (float)sum14;
      C[(i+3) * wB + (j+2)] = (float)sum15;
      C[(i+3) * wB + (j+3)] = (float)sum16;

    }
  }
  */
}

// Allocate a matrix of dimensions height*width
Matrix Allocate2ndMatrix(int height, int width)
{
  Matrix M;
  M.width = M.pitch = width;
  M.height = height;
  int size = M.width * M.height;
  M.elements = NULL;

  M.elements = (float*) malloc(size*sizeof(float));

  /* This is a row-major allocation and initialization.
   * You need to modify this function which is only called
   * for Matrix B such that a column-major ordering is
   * performed. */
  for(unsigned int i = 0; i < M.height; i++){
    for(unsigned int j = 0; j < M.width; j++){
      M.elements[i+j * M.width] = (rand() / (float)RAND_MAX);
    }
  }
  /*for(unsigned int i = 0; i < M.height * M.width; i++)
  {
    M.elements[i] = (rand() / (float)RAND_MAX);
  }*/
  return M;
  
}

