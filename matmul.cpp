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
      C[i * wB + j] = (float)sum1;
      C[i * wB + j + 1] = (float)sum2; 
    }
  } 
*/
  for (unsigned int r = 0; r < hA; r+=2) {
    for(unsigned int c = 0; c < wB; c+=2) {
      
    }
  }
  for (unsigned int r = 0; r < hA; r++) {
    for (unsigned int c = 0; c < wB; c++) {
      //double sum1 = 0;
      //double sum2 = 0;
      for (unsigned int k = 0; k < wA; k++) {
        C[r*hA+k] += float(A[r*hA+c])*float(B[k*hA+c]);
      }
    }
  }
  /*for (unsigned int i = 0; i < hA; ++i)  {
    for (unsigned int j = 0; j < hA; ++j) {
      double sum = 0;
      for (unsigned int k = 0; k < wA; ++k) {
        double a = A[i * wA + k];
        double b = B[j * wB + k];
        sum += a * b;
      }
      C[i * wB + j] = (float)sum;
    }
  }*/
  /*for (unsigned int row = 0; row < hA; row++) {
    unsigned l = 0;
    unsigned sum = 0;
    for (unsigned int r = 0; r < wB * wB; r++) {
      sum += A[] * B[r];
      l++;
      l%=wB;
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

