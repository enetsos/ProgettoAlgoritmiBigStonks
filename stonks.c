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
    return 1000;
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
    double peso;
    struct nodo *next;
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

void createPath(int N, int K, int B[MAXN][MAXK], int S[MAXN][MAXK], double path[nArchi(N, K)])
{
    int cont = 0;
    for (int i = 0; i < N-1; i++)
    {
        for (int j = i; j < N-1; j++)
        {
            for(int k = 0; k < K; k++)
            {
                path[cont] = createNodoB(B[i][k], S[j+1][k]);
                cont++;
            }
        }
    }

    /*

    create path (B[0][j], S[1][j])
    create path (B[0][j], S[2][j])

    create path (B[1][j], S[2][j])


    */
    for (int i = 1; i < N-1; i++)
    {
        for (int j = i; j < N; j++)
        {
            for (int k = 0; k < K; k++)
            { 
                if((k+j) == K){
                    path[cont] = createNodoS(S[i][k], B[i][0]);
                }
                else if((k+j) > K)
                    path[cont] = createNodoS(S[i][k], B[i][k+j-K]);
                else
                    path[cont] = createNodoS(S[i][k], B[i][k+j]);
                cont++;
            }
        }
    }
}

void printPath(double path[nArchi(N, K)])
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

    double path[nArchi(N, K)];
    createPath(N, K, B, S, path);
    printPath(path);

    printf("%d\n", 42); // print your result

    return 0;
}
