 #ifndef __MATRIX_TRANSPO_H__
 #define __MATRIX_TRANSPO_H__
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <random>
#include <omp.h>

#define BILLION  1000000000L
using namespace std;

void ini_matrix(vector<vector<float>> &matrix,int size);
void print_matrix(vector<vector<float>> &matrix,int size);

//SEQUENTIAL
bool checkSym(vector<vector<float>> &matrix,int size);
void matTranspose(vector<vector<float>> &raw, vector<vector<float>> &transposed,int size);

//IMPLICIT
bool checkSymImp(vector<vector<float>> &matrix,int size);
void matTransposeImp(vector<vector<float>> &raw, vector<vector<float>> &transposed,int size);

//PARALLEL
bool checkSymOmp(vector<vector<float>> &matrix,int size);
void matTransposeOmp(vector<vector<float>> &raw, vector<vector<float>> &transposed,int size);

 #endif