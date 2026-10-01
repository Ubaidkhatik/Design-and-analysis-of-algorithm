#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int parent[100];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unionSet(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b)
        parent[b] = a;
}

int main() {
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    Edge edges[e];

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < e; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;

    sort(edges, edges + e, compare);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int totalCost = 0, count = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            cout << u << " - " << v << " : "
                 << edges[i].weight << endl;

            totalCost += edges[i].weight;
            unionSet(u, v);
            count++;
        }
    }

    cout << "\nMinimum Cost = " << totalCost;

    return 0;
}