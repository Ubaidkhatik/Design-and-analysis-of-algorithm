#include <iostream>
using namespace std;
#define INF 9999
int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
int g[n][n], key[n], parent[n], used[n];
 cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            if (g[i][j] == 0)
                g[i][j] = INF;
        }
  for (int i = 0; i < n; i++) {
        key[i] = INF;
        parent[i] = -1;
        used[i] = 0;
    }
 key[0] = 0;
    int cost = 0;
 cout << "\nEdges in MST:\n";
for (int c = 0; c < n; c++) {
        int u = -1;
  for (int i = 0; i < n; i++)
            if (!used[i] && (u == -1 || key[i] < key[u]))
                u = i;
used[u] = 1;
 if (parent[u] != -1) {
            cout << parent[u] << " - " << u
                 << " : " << g[parent[u]][u] << endl;
            cost += g[parent[u]][u];
        }
  for (int v = 0; v < n; v++)
            if (!used[v] && g[u][v] < key[v]) {
                key[v] = g[u][v];
                parent[v] = u;
            }
    }
cout << "\nMinimum Cost = " << cost;
  return 0;
}
