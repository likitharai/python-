#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define INF 9999

int graph[MAX][MAX];

// Function to generate a random graph
void generateGraph(int n, int maxWeight) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                int weight = rand() % maxWeight + 1;
                graph[i][j] = graph[j][i] = weight;
            }
        }
    }
}

// Prim's algorithm
void primMST(int n) {
    int selected[MAX] = {0};
    int no_edges = 0;
    int min, x, y;
    int totalCost = 0;

    selected[0] = 1; // Start from node 0

    printf("\nEdges in MST:\n");

    while (no_edges < n - 1) {
        min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j]) {
                        if (min > graph[i][j]) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, graph[x][y]);
        totalCost += graph[x][y];
        selected[y] = 1;
        no_edges++;
    }

    printf("Total cost of MST = %d\n", totalCost);
}

int main() {
    int n, maxWeight;
    clock_t start, end;

    printf("Enter number of vertices (<= %d): ", MAX);
    scanf("%d", &n);

    printf("Enter maximum edge weight: ");
    scanf("%d", &maxWeight);

    srand(time(NULL)); // Seed random number generator
    generateGraph(n, maxWeight);

    printf("\nGenerated Graph (Adjacency Matrix):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", graph[i][j]);
        }
        printf("\n");
    }

    start = clock();
    primMST(n);
    end = clock();

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("CPU Time used: %f seconds\n", cpu_time_used);

    return 0;
}
