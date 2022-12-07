// NOTE: it is recommended to use this even if you don't understand the following code.
//ciaooooo 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// constraints
#define MAXN 3000
#define MAXK 3000

// input data
int N, K, i, j;                   // N->number of days, K->number of stocks
int B[MAXN][MAXK], S[MAXN][MAXK]; // B->buy, S->sell


int nVertici(int N, int K)
{
    return N * 2 * K;
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

struct nodo{
    double peso;
    struct nodo *next;
};typedef struct nodo Nodo;


Nodo *createPath(int N, int K, int B[MAXN][MAXK], int S[MAXN][MAXK], Nodo *prev)
{

    //TOFIX: non so come creare il path, non so creare il grafo 

    //creao un nodo che ha il peso dell'elemento dell'array e il puntatore al nodo successivo che è il nodo che ho creato prima
    //problema è che il nodo precedente non esiste ancora se inizio a creare il path
    //il path è un array di nodi, quindi devo creare un array di nodi
    //probabilmente non ha senso salvare il puntatore al nodo successivo, ma solo il peso
    

    Nodo *nodo = malloc(sizeof(Nodo));
    nodo->peso = prev->peso / prev->next->peso;
    nodo->next = malloc(sizeof(Nodo));
    nodo->next->peso = B[1][1];
    
    return nodo;
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



    printf("%d\n",42); // print your result

    return 0;
}
