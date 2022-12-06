// NOTE: it is recommended to use this even if you don't understand the following code.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stonks.c"

int nVertici(int N, int K){
    return N*2*K;
}

struct nodo{
    int id;
    int peso;
    struct nodo *next;
};typedef struct nodo Nodo;


Nodo *genGraphByMatrixOfVertex(int N, int K, int B[MAXN][MAXK], int S[MAXN][MAXK]){
    int n = nVertici(N, K);
    Nodo *graph[n];
    int i, j, k;
    for(i=0; i<n; i++){
        graph[i] = NULL;
    }
    for(i=0; i<N; i++){
        for(j=0; j<K; j++){
            for(k=0; k<K; k++){
                if(j!=k){
                    Nodo *new = malloc(sizeof(Nodo));
                    new->id = i*K+k;
                    new->peso = B[i][j]-S[i][k];
                    new->next = graph[i*K+j];
                    graph[i*K+j] = new;
                }
            }
        }
    }
    return graph;
}

void printGraph(Nodo *graph, int N, int K){
    int n = nVertici(N, K);
    for(int i = 0; i < n; i++){
        printf("%d: ", graph[i].id);
        Nodo *tmp = graph[i].next;
        while(tmp != NULL){
            printf("%d ", tmp->id);
            tmp = tmp->next;
        }
        printf("\n");
    }
}


int main() {

printGraph(genGraphByMatrixOfVertex(3, 3, B, S), 3, 3);


    return 0;
}
