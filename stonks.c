// NOTE: it is recommended to use this even if you don't understand the following code.
// ciaooooo
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// constraints
#define MAXN 3000
#define MAXK 3000

// input data
int N, K, i, j;                   // N->number of days, K->number of stocks
int B[MAXN][MAXK], S[MAXN][MAXK]; // B->buy, S->sell

int nArchi(int N, int K)
{
    return 10;
}

void printMatrix(int N, int K, int B[MAXN][MAXK], int S[MAXN][MAXK])
{
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < K; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < K; j++)
        {
            printf("%d ", S[i][j]);
        }
        printf("\n");
    }
}


double createNodoB(int B, int S)
{
    return B * S;
}

double createNodoS(int S, int B)
{
    return S / (double)B;
}

void createArchiB(int N, int K, int B[MAXN][MAXK], int S[MAXN][MAXK], double archiB[N][K])
{
    for (int i = 0; i < N-1; i++)
    {
        for (int j = i; j < N; j++)
        {
            for(int k = 0; k < K; k++)
            {
                if(i == 0)
                    archiB[j][k] = 1 / createNodoB(B[i][k], S[j][k]);
                else
                    archiB[j][k] = createNodoB(B[i][k], S[j][k]);
            }
        }
    }
}
void createArchiS(int N, int K, int B[MAXN][MAXK], int S[MAXN][MAXK], double archiS[N][K])
{
    int cont = 0;
    for (int i = 1; i < N-1; i++)
    {
        for (int j = i; j < N; j++)
        {
            for (int k = 0; k < K; k++)
            { 
                if((k+j) == K){
                    archiS[j-1][k] = createNodoS(S[i][k], B[i][0]);
                }
                else if((k+j) > K)
                    archiS[j-1][k] = createNodoS(S[i][k], B[i][k+j]);
                else
                    archiS[j-1][k] = createNodoS(S[i][k], B[i][k+j]);
                cont++;
            }
        }
    }
}

void createPath(int N, int K, double archiB[N][K], double archiS[N][K],int B[MAXN][MAXK],int S[MAXN][MAXK], double path[15]){
    int cont = 0;
    for(int i = 0; i < N; i++){
        path[cont] = (double) 1 / B[0][i];
        path[cont] *= archiS[0][i];
        if((i+1) == K)
            path[cont] *= B[N-1][0];
        else
            path[cont] *= B[N-1][i+1];
        cont++;
    }

    for(int i = 0; i < N; i++){
        path[cont] = (double) 1 / B[0][i];
        path[cont] *= archiS[0][i];
        if((i-1) == 0)
            path[cont] *= B[N-1][K-1];
        else
            path[cont] *= B[N-1][i-1];
        cont++;
    }

    for(int i = 0; i < N; i++){
        path[cont] = (double) 1 / B[0][i];
        path[cont] *= S[2][i];
        cont++;
    }
}

void printPath(double path[15]){
    for(int i = 0; i < 15; i++){
        printf("%f ", path[i]);
    }
}


void printArchi(double archi[N][K])
{
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < K; j++)
        {
            printf("%f ", archi[i][j]);
        }
        printf("\n");
    }
}


double maxOfPath(double path[15]){
    double max = path[0];
    for(int i = 0; i < 15; i++){
        if(path[i] > max)
            max = path[i];
    }
    return max;
}
int main()
{
    //  uncomment the following lines if you want to read/write from files
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);

    assert(2 == scanf("%d%d", &N, &K));
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < K; j++)
        {
            assert(2 == scanf("%d%d", &B[i][j], &S[i][j]));
        }
    }

    // insert your code here
    printMatrix(N, K, B, S);

    printf("\n");

    double archiB[N][K];
    double archiS[N][K];
    createArchiB(N, K, B, S, archiB);
    createArchiS(N, K, B, S, archiS);
    printArchi(archiB);
    printf("\n");
    printf("\n");
    printArchi(archiS);

    double path[15];
    createPath(N, K, archiB, archiS,B,S, path);
    printf("\n");
    printPath(path);
    

    printf("\n");
    printf("%f", maxOfPath(path)); // print your result

    return 0;
}
