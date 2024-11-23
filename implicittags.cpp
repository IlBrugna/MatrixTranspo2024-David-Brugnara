#include "matrix_transpo.h"
//g++ -c implicit.cpp -o implicit.o  -ftree-vectorize -O2
//-march=native
//block base tequinque
#define blockSize 64

void matTransposeTag(vector<vector<float>> &raw, vector<vector<float>> &transposed,int size)
{
    timespec start, stop;
    clock_gettime( CLOCK_REALTIME, &start);

    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            transposed[i][j]=raw[j][i];
        }
    }
    clock_gettime( CLOCK_REALTIME, &stop);

    double timeElapsed=( stop.tv_sec - start.tv_sec ) + (double)( stop.tv_nsec - start.tv_nsec ) /BILLION;

    FILE* f = fopen("tags.txt","a+");
    fprintf(f,"%.f, %lf\n", log2(size), timeElapsed);
    fclose(f);
    //printf("IMPLICIT TRANSPOSITION: %lf\n", timeElapsed);
}

void matTransposeBlock(vector<vector<float>> &raw, vector<vector<float>> &transposed,int size)
{
    timespec start, stop;
    clock_gettime( CLOCK_REALTIME, &start);

    for (int i = 0; i < size; i += blockSize) {
        for (int j = 0; j < size; j += blockSize) {
            // Transpose elements within the block
            for (int blockRow = i; blockRow < std::min(i + blockSize, size); ++blockRow) {
                for (int blockCol = j; blockCol < std::min(j + blockSize, size); ++blockCol) {
                    transposed[blockCol][blockRow] = raw[blockRow][blockCol];
                }
            }
        }
    }
    clock_gettime( CLOCK_REALTIME, &stop);

    double timeElapsed=( stop.tv_sec - start.tv_sec ) + (double)( stop.tv_nsec - start.tv_nsec ) /BILLION;

    FILE* f = fopen("block.txt","a+");
    fprintf(f,"%.f, %lf\n", log2(size), timeElapsed);
    fclose(f);
    //printf("IMPLICIT TRANSPOSITION: %lf\n", timeElapsed);
}