#include <iostream>
using namespace std;

#define INF 9999

int main() {
    int n, source;

    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[n][n];

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];

            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }

    cout << "Enter source vertex: ";
    cin >> source;

    int distance[n], visited[n];

    for (int i = 0; i < n; i++) {
        distance[i] = graph[source][i];
        visited[i] = 0;
    }

    distance[source] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1, minDistance = INF;

        for (int i = 0; i < n; i++)
            if (!visited[i] && distance[i] < minDistance) {
                minDistance = distance[i];
                u = i;
            }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] != INF &&
                distance[u] + graph[u][v] < distance[v])
                distance[v] = distance[u] + graph[u][v];
    }

    cout << "\nShortest distances from vertex " << source << ":\n";

    for (int i = 0; i < n; i++) {
        if (distance[i] == INF)
            cout << source << " -> " << i << " = Not Reachable\n";
        else
            cout << source << " -> " << i << " = " << distance[i] << endl;
    }

    return 0;
}