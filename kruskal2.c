#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset (for Union-Find)
struct Subset {
    int parent, rank;
};

// Function to find the parent of a vertex (with path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two subsets (by rank)
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Kruskal's algorithm to find MST
void kruskalMST(struct Edge edges[], int V, int E) {
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    struct Edge* result = (struct Edge*)malloc((V - 1) * sizeof(struct Edge));

    // Initialize subsets
    for (int i = 0; i < V; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Sort edges by weight
    // (You can use any sorting algorithm here)
    // ...

    int e = 0; // Index for result[]
    int i = 0; // Index for sorted edges

    while (e < V - 1 && i < E) {
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    // Print the MST
    printf("Edges in MST:\n");
    for (int j = 0; j < e; ++j)
        printf("%d -- %d (weight %d)\n", result[j].src, result[j].dest, result[j].weight);

    free(subsets);
    free(result);
}

int main() {
    int V = 9; // Number of vertices
    int E = 14; // Number of edges

    struct Edge edges[] = {
        // Initialize your graph edges here
        // {src, dest, weight}
        // ...
    };

    kruskalMST(edges, V, E);

    return 0;
}
