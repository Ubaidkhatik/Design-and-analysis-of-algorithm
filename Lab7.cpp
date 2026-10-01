#include <iostream>
using namespace std;

int parent[100], sizeSet[100];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);   // Collapsing Find
    return parent[x];
}

void weightedUnion(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;

    if (sizeSet[a] < sizeSet[b]) {
        parent[a] = b;
        sizeSet[b] += sizeSet[a];
    } else {
        parent[b] = a;
        sizeSet[a] += sizeSet[b];
    }
}

int main() {
    int n, ch, a, b;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        sizeSet[i] = 1;
    }

    do {
        cout << "\n1. Weighted Union";
        cout << "\n2. Collapsing Find";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nChoice: ";
        cin >> ch;

        if (ch == 1) {
            cin >> a >> b;
            weightedUnion(a, b);
            cout << "Union performed";
        }
        else if (ch == 2) {
            cin >> a;
            cout << "Root = " << find(a);
        }
        else if (ch == 3) {
            for (int i = 0; i < n; i++)
                cout << parent[i] << " ";
        }
    } while (ch != 4);

    return 0;
}