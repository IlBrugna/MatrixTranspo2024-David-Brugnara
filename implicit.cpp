#include "matrix_transpo.h"


void matTransposeImp(vector<vector<float>> &raw, vector<vector<float>> &transposed,int size)
{
    timespec start, stop;
    clock_gettime( CLOCK_REALTIME, &start);

    for (int i=0;i<size;i++)
    {
       #pragma unroll (4)
        for (int j=0;j<size;j++)
        {
            transposed[i][j]=raw[j][i];
        }
    }
    clock_gettime( CLOCK_REALTIME, &stop);

    double timeElapsed=( stop.tv_sec - start.tv_sec ) + (double)( stop.tv_nsec - start.tv_nsec ) /BILLION;

    FILE* f = fopen("implicitTranspo.csv","a+");
    fprintf(f,"%.f;%lf\n", log2(size), timeElapsed);
    fclose(f);
    //printf("IMPLICIT TRANSPOSITION: %lf\n", timeElapsed);
}

bool checkSymImp(vector<vector<float>> &matrix,int size)
{
    bool isSymmetric = true;
    timespec start, stop;
    clock_gettime( CLOCK_REALTIME, &start);

    for (int i=0;i<size;i++)
    {
        #pragma unroll (4)
        for (int j=0;j<size;j++)
        {
            if (matrix[i][j] != matrix[j][i]) isSymmetric = false;
        }
    }

    clock_gettime( CLOCK_REALTIME, &stop);

    double timeElapsed=( stop.tv_sec - start.tv_sec ) + (double)( stop.tv_nsec - start.tv_nsec ) /BILLION;

    FILE* f = fopen("implicitCheck.csv","a+");
    fprintf(f,"%.f;%lf\n", log2(size), timeElapsed);
    fclose(f);

    //printf("IMPLICIT CHECK: %lf\n", timeElapsed);
    return isSymmetric;
}
