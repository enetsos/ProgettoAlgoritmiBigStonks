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

double createNodoB(double B, double S)
{
    return B * S;
}

double createNodoS(int S, int B)
{
    return S / (double)B;
}

void createArchiB(int N, int K, int B[MAXN][MAXK], int S[MAXN][MAXK], double archiB[N][K])
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i; j < N; j++)
        {
            for (int k = 0; k < K; k++)
            {
                archiB[j][k] = createNodoB((double)1 / B[i][k], S[j][k]);
            }
        }
    }
}
void createArchiS(int N, int K, int B[MAXN][MAXK], int S[MAXN][MAXK], double archiS[N][K])
{
    int cont = 0;
    for (int i = 1; i < N - 1; i++)
    {
        for (int j = i; j < N; j++)
        {
            for (int k = 0; k < K; k++)
            {
                if ((k + j) == K)
                {
                    archiS[j - 1][k] = createNodoS(S[i][k], B[i][0]);
                }
                else if ((k + j) > K)
                    archiS[j - 1][k] = createNodoS(S[i][k], B[i][k + j - K]);
                else
                    archiS[j - 1][k] = createNodoS(S[i][k], B[i][k + j]);
                cont++;
            }
        }
    }
}

void createPath(int N, int K, double archiB[N][K], double archiS[N][K], int B[MAXN][MAXK], int S[MAXN][MAXK], double path[15])
{
    int cont = 0;
    for (int i = 0; i < N; i++)
    {
        path[cont] = (double)1 / B[0][i];
        path[cont] *= archiS[0][i];
        if ((i + 1) == K)
            path[cont] *= B[N - 1][0];
        else
            path[cont] *= B[N - 1][i + 1];
        cont++;
    }

    for (int i = 0; i < N; i++)
    {
        path[cont] = (double)1 / B[0][i];
        path[cont] *= archiS[0][i];
        if ((i - 1) == 0)
            path[cont] *= B[N - 1][K - 1];
        else
            path[cont] *= B[N - 1][i - 1];
        cont++;
    }

    for (int i = 0; i < N; i++)
    {
        path[cont] = (double)1 / B[0][i];
        path[cont] *= S[2][i];
        cont++;
    }
}

void printPath(double path[15])
{
    for (int i = 0; i < 15; i++)
    {
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
-
double maxOfPath(double path[15])
{
    double max = path[0];
    for (int i = 0; i < 15; i++)
    {
        if (path[i] > max)
            max = path[i];
    }
    return max;
}

double maxArchiB(double archiB[N][K])
{
    double max = archiB[0][0];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            if (archiB[i][j] > max)
                max = archiB[i][j];
        }
    }
    return max;
}

double maxOfTwo(double a, double b)
{
    if (a > b)
        return a;
    else
        return b;
}

void matrixZero(int N, int K, double archiB[N][K], double archiS[N][K])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            archiB[i][j] = 0;
            archiS[i][j] = 0;
        }
    }
}

int main()
{
    //  uncomment the following lines if you want to read/write from files
    freopen("input0.txt", "r", stdin);
    freopen("output0.txt", "w", stdout);

    assert(2 == scanf("%d%d", &N, &K));

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < K; j++)
        {
            assert(2 == scanf("%d%d", &B[i][j], &S[i][j]));
        }
    }

    // insert your code here
    // printMatrix(N, K, B, S);

    // printf("\n");

    double archiB[N][K];
    double archiS[N][K];

    matrixZero(N, K, archiB, archiS);

    createArchiB(N, K, B, S, archiB);
    if (K == 1)
    {
        double max = maxArchiB(archiB);
        printf("%f", max);
        return 0;
    }

    createArchiS(N, K, B, S, archiS);
    // printArchi(archiB);
    // printf("\n");
    // printf("\n");
    // printArchi(archiS);

    double path[15] = {0};
    createPath(N, K, archiB, archiS, B, S, path);
    // printf("\n");
    // printPath(path);

    // printf("\n");
    // printf("\n");
    double max = maxOfTwo(maxOfPath(path), maxArchiB(archiB));
    printf("%f", max); // print your result

    return 0;
}
