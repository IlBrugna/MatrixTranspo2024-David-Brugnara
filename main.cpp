#include <iostream>
#include "matrix_transpo.h"

#define REPS 5
int main(int argc, char *argv[])
{

    const int size = pow (2,atoi(argv[1]));
    vector<vector<float>> M( size,vector<float>(size));
    vector<vector<float>> T( size,vector<float>(size));
    ini_matrix(M,size);

//CORE

    for (int i=0;i<REPS;i++) {
        matTranspose(M,T,size);
        matTransposeImp(M,T,size);
        matTransposeOmp(M,T,size);

        checkSym(M,size);
        checkSymImp(M,size);
        checkSymOmp(M,size);
    }



    //CYCLE USED TO COMPARE DIFFERENT IMPLICIT IMPLEMENTATIONS
    /*
    for (int i=0;i<REPS;i++)
    {
        matTransposeTag(M,T,size);
        matTransposeBlock(M,T,size);
    }
 */

    //printf("is equal:%i ",ifEqual(4)); //SIMPLE CHECK TO VERIFY CODE IS ACTUALLY WORKING AS INTENDED
    return 0;
}


void ini_matrix(vector<vector<float>> &matrix, int size){
    std::random_device rd;
    std::uniform_real_distribution<float> dist(1.f,100.f);
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            matrix[i][j]=dist(rd);
        }
    }
}


bool ifEqual(int size)
{
    vector<vector<float>> M( size,vector<float>(size));
    vector<vector<float>> T1( size,vector<float>(size));
    vector<vector<float>> T2( size,vector<float>(size));
    ini_matrix(M,size);
    bool isEqual = true;

    matTranspose(M,T1,size);
    matTransposeOmp(M,T2,size);
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            if (T1[i][j] != T2[i][j]) isEqual = false;
        }
    }

    return isEqual;
}


/*
void print_matrix(vector<vector<float>> &matrix,int size)
{
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            printf("%i %i value is: %.2f\n",i,j,matrix[i][j]);
        }
    }
}*/

