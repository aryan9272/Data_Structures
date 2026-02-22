#include <stdio.h>
#define MAX 100
int parent[MAX];
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void union_set(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}
void prims(int cost[MAX][MAX], int n) {
    int selected[MAX] = {0}, edges = 0, minCost = 0;
    selected[0] = 1;
    printf("\nPrim’s Algorithm:\n");

    while (edges < n - 1) {
        int min = 999999, x = 0, y = 0;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && cost[i][j] && cost[i][j] < min) {
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        printf("Edge %d: (%d - %d) cost: %d\n", edges + 1, x, y, cost[x][y]);
        minCost += cost[x][y];
        selected[y] = 1;
        edges++;
    }
    printf("Total Minimum Cost (Prim’s): %d\n", minCost);
}
void kruskals(int cost[MAX][MAX], int n) {
    int minCost = 0, edges = 0;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    printf("\nKruskal’s Algorithm:\n");

    while (edges < n - 1) {
        int min = 999999, a = -1, b = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j] && find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        union_set(a, b);
        printf("Edge %d: (%d - %d) cost: %d\n", edges + 1, a, b, min);
        minCost += min;
        cost[a][b] = cost[b][a] = 999999; // mark edge as used
        edges++;
    }

    printf("Total Minimum Cost (Kruskal’s): %d\n", minCost);
}

int main() {
    int n;
    int cost[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999999; // treat 0 as infinity
        }
    }

    prims(cost, n);

    // reset cost matrix for Kruskal’s
    printf("\nEnter cost adjacency matrix again for Kruskal’s (0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999999;
        }
    }

    kruskals(cost, n);

    return 0;
}
