#include "matrix_transpo.h"
#include <omp.h>
/*# ifdef _OPENMP
# include <omp .h>
# else
...
# endif*/

/*
gcc -fopenmp pi.c
export OMP NUM THREADS=4; ./ a.out
*/
void matTransposeOmp(vector<vector<float>> &raw, vector<vector<float>> &transposed,int size)
{
    timespec start, stop;
    clock_gettime( CLOCK_REALTIME, &start);

    #pragma omp parallel for collapse(2)
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            transposed[i][j]=raw[j][i];
        }
    }

    clock_gettime( CLOCK_REALTIME, &stop);

    double timeElapsed=( stop.tv_sec - start.tv_sec ) + (double)( stop.tv_nsec - start.tv_nsec ) /BILLION; //VOLENDO (double)BILLION


    char *env_var = getenv("OMP_NUM_THREADS");
    FILE* f = fopen("parallelTranspo.txt","a+");
    fprintf(f,"n: %.f, threads: %i, time: %lf\n", log2(size),atoi(env_var), timeElapsed);
    fclose(f);

    printf("PARALLEL TRANSPOSITION: %lf\n", timeElapsed);
}

bool checkSymOmp(vector<vector<float>> &matrix,int size)
{
    bool isSymmetric = false;
    timespec start, stop;
    clock_gettime( CLOCK_REALTIME, &start);
#pragma omp parallel for collapse(2) reduction(&:isSymmetric)
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            if (matrix[i][j] != matrix[j][i])
                isSymmetric = false;
        }
    }

    clock_gettime( CLOCK_REALTIME, &stop);

    double timeElapsed=( stop.tv_sec - start.tv_sec ) + (double)( stop.tv_nsec - start.tv_nsec ) /BILLION; //VOLENDO (double)BILLION
    printf("PARALLEL CHECK: %lf\n", timeElapsed);

    char *env_var = getenv("OMP_NUM_THREADS");
    FILE* f = fopen("parallelCheck.txt","a+");
    fprintf(f,"n: %.f, threads: %i, time: %lf\n", log2(size),atoi(env_var), timeElapsed);
    fclose(f);

    return isSymmetric;
}
