// NOTE: it is recommended to use this even if you don't understand the following code.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// constraints
#define MAXN 3000
#define MAXK 3000

// input data
int N, K, i, j;
int B[MAXN][MAXK], S[MAXN][MAXK];

int createMatrixFromFile(char *filename, int matrix[MAXN][MAXK]) {
    FILE *fp;
    int i, j;
    int N, K;

    fp = fopen(filename, "r");
    assert(fp != NULL);

    fscanf(fp, "%d %d", &N, &K);
    for (i=0; i<N; i++)
        for (j=0; j<K; j++)
            fscanf(fp, "%d", &matrix[i][j]);

    fclose(fp);

    return N;
}

int main()
{
    //  uncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d%d", &N, &K));
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < K; j++)
        {
            assert(2 == scanf("%d%d", &B[i][j], &S[i][j]));
        }
    }

    // insert your code here

    printf("%d\n", 42); // print the result
    return 0;
}
