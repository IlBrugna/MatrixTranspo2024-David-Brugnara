//#include <complex>
#include <iostream>
#include "matrix_transpo.h"

/*to always be on the same node, inside pbs script select ncpus64.... export omp... /.ex
 *average not inside the code, we need to remove outlayers
 * 96 max threads
 * speedup and efficency complusory
 * cache miss?
 * qsub -I -q short_cpuQ -l select=1:ncpus=64:ompthreads=64:mem=1mb
 * aggiungere controlli di sicurezza
 * aggiungere controllo delle matrici
 * block structure?
 */

int main(int argc, char *argv[])
{

    const int size = pow (2,atoi(argv[1]));
    vector<vector<float>> M( size,vector<float>(size,1)); //TOGLIERE IL VALORE DI INI!! MESSO SOLO PER CONTROLLARE SE SYMM
    vector<vector<float>> T( size,vector<float>(size));
    ini_matrix(M,size);
    /*
    printf("is symm: %d\n",checkSym(M,size));
    matTranspose(M,T,size);*/
    /*
    printf("is symm: %d\n",checkSymImp(M,size));
    matTransposeImp(M,T,size);*/

    matTranspose(M,T,size);
    matTransposeImp(M,T,size);
    matTransposeOmp(M,T,size);

    checkSym(M,size);
    checkSymImp(M,size);
    checkSymOmp(M,size);

    return 0;
}


//SHOULD I PASS SIZE FOR REFERENCE OR SOMETHING ELSE?
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

