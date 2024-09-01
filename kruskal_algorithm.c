#include <stdio.h>

int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];
int find(int);
int unionSets(int, int);

int main() {
    printf("\nImplementation of Kruskal's Algorithm\n");
    printf("\nEnter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost of adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999;  // Use 999 as a representation for infinity
            }
        }
    }

    // Initialize parent array
    for (i = 0; i < n; i++) {
        parent[i] = 0;
    }

    printf("The edges of minimum spanning tree are:\n");
    while (ne < n) {
        for (i = 0, min = 999; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);

        if (unionSets(u, v)) {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;  // Remove the edge by setting it to infinity
    }
    printf("\nMinimal cost = %d\n", mincost);

    return 0;
}

// Function to find the parent of a node
int find(int i) {
    while (parent[i]) {
        i = parent[i];
    }
    return i;
}

// Function to perform union of two subsets
int unionSets(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}
