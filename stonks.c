#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
    int N, K;

    // Allocate arrays for storing the buying and selling prices
    int** buy = malloc(N * sizeof(int*));
    int** sell = malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        buy[i] = malloc(K * sizeof(int));
        sell[i] = malloc(K * sizeof(int));
    }

    freopen("input0.txt", "r", stdin);
    freopen("output0.txt", "w", stdout);

    assert(2 == scanf("%d%d", &N, &K));

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
            assert(2 == scanf("%d%d", &buy[i][j], &sell[i][j]));
        }
    }

    // Allocate an array for storing the maximum profit that can be made on each day
    double* maxProfit = malloc(N * sizeof(double));

    // Initialize the maximum profit for the first day to 0
    maxProfit[0] = 0;

    // Loop through each day from 1 to N
    for (int i = 1; i < N; i++) {
        double currentMaxProfit = 0;
        // Loop through each stock
        for (int j = 0; j < K; j++) {
            // Calculate the profit that can be made by buying and selling the stock on this day
            double profit = (double)sell[i][j] - (double)buy[i][j];
            // Select the stock with the maximum profit
            if (profit > currentMaxProfit) {
                currentMaxProfit = profit;
            }
        }
        // Add the maximum profit for this day to the total profit made on the previous days
        maxProfit[i] = maxProfit[i - 1] + currentMaxProfit;
    }

    // Print the maximum possible amount of Euro that Dario can have at the end of the N days
    printf("%.6f\n", maxProfit[N - 1]);

    // Free the allocated memory
    for (int i = 0; i < N; i++) {
        free(buy[i]);
        free(sell[i]);
    }
    free(buy);
    free(sell);
    free(maxProfit);

    return 0;
}