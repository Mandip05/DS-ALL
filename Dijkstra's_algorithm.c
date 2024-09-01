#include <stdio.h>
#define INF 999999

void dij(int n, int v, int cost[10][10], int dist[]) {
    int i, u, count, w, min;
    int flag[10] = {0};  // Initialize flag array to 0

    // Initialize distance array and flag array
    for (i = 0; i < n; i++) {
        dist[i] = cost[v][i];
        flag[i] = 0;
    }

    dist[v] = 0;  // Distance to the source node is 0
    flag[v] = 1;  // Mark the source node as processed
    count = 1;

    while (count < n) {
        min = INF;
        // Find the vertex with the minimum distance that has not been processed
        for (w = 0; w < n; w++) {
            if (dist[w] < min && !flag[w]) {
                min = dist[w];
                u = w;
            }
        }

        // Mark the selected vertex as processed
        flag[u] = 1;
        count++;

        // Update the distance value of the adjacent vertices
        for (w = 0; w < n; w++) {
            if (!flag[w] && (dist[u] + cost[u][w] < dist[w])) {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
}

int main() {
    int n, v, i, j, cost[10][10], dist[10];

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j) {
                cost[i][j] = INF;  // Set to infinity for non-diagonal zeroes
            }
        }
    }

    printf("\nEnter the source node: ");
    scanf("%d", &v);
    v--;  // Adjust for 0-based index

    dij(n, v, cost, dist);

    printf("\nShortest Path:\n");
    for (i = 0; i < n; i++) {
        if (i != v) {
            printf("%d -> %d, cost = %d\n", v + 1, i + 1, dist[i]);
        }
    }

    return 0;
}
