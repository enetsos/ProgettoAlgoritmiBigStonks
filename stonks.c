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

struct nodo
{
    int id; // 0 buy, 1 sell
    double peso[];
};
typedef struct nodo Nodo;

double createNodoB(int B, int S)
{
    return B * S;
}

double createNodoS(int B, int S)
{
    return S * B;
}

void createNodo(int id, double peso[], Nodo nodo){
    nodo.id = id;
    for(int i = 0; i < K-1; i++)
        nodo.peso[i] = peso[i];
}

void createArchiB(int N, int K, int B[MAXN][MAXK], int S[MAXN][MAXK], double archiB[N][K])
{
    int cont = 0;
    for (int i = 0; i < N-1; i++)
    {
        for (int j = i; j < N-1; j++)
        {
            for(int k = 0; k < K; k++)
            {
                archiB[i][k] = createNodoB(B[i][k], S[j+1][k]);
                cont++;
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
                    archiS[i-1][k] = createNodoS(S[i][k], B[i][0]);
                }
                else if((k+j) > K)
                    archiS[i-1][k] = createNodoS(S[i][k], B[i][k+j-K]);
                else
                    archiS[i-1][k] = createNodoS(S[i][k], B[i][k+j]);
                cont++;
            }
        }
    }
}

void lineeFinali(int N, int K, int B[MAXN][MAXK], int S[MAXN][MAXK], double archiB[nArchi(N, K)], double archiS[nArchi(N, K)]){
    for (i = 0; i < nArchi(N, K); i++)
    {
        if ((i + 1) % 3 == 0)
        {
            printf("\n");
        }
    }
}

void printArchiB(double path[nArchi(N, K)])
{
    for (i = 0; i < nArchi(N, K); i++)
    {
        printf("%f ", path[i]);
        if ((i + 1) % 3 == 0)
        {
            printf("\n");
        }
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
    

    printf("%d\n", 42); // print your result

    return 0;
}
