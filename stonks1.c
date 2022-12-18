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
double C[MAXN];

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

    printf("\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < K; j++)
        {
            printf("%d ", S[i][j]);
        }
        printf("\n");
    }
}


void stampaC(int N)
{
    for(int i = 0; i < N; i++)
    {
        printf("%f ", C[i]);
    }
    printf("\n");
}

int max(double a, double b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
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

    C[0] = 1;
    for(int daySell = 1; daySell < N; daySell++)
    {
        for(int dayBuy = 0; dayBuy < daySell; dayBuy++)
        {
            double gain = 0.0;

            for(int w = 0; w < K; w++)
            {
                gain = max(gain, (double)(S[daySell][w] - B[dayBuy][w]) / (double)B[dayBuy][w]);
                
            }
            if(gain > 0)
            {
                C[daySell] = max(C[daySell], C[dayBuy] * (1 + gain));
            }
        }
    }

    printMatrix(N, K, B, S);

    printf("\n");

    stampaC(N);


    return 0;
}
