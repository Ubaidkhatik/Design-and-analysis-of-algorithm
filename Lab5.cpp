#include <iostream>
using namespace std;

void heapify(int h[], int n, int i, int max) {
    int x = i, l = 2*i, r = 2*i+1;

    if (l <= n && (max ? h[l] > h[x] : h[l] < h[x]))
        x = l;

    if (r <= n && (max ? h[r] > h[x] : h[r] < h[x]))
        x = r;

    if (x != i) {
        swap(h[i], h[x]);
        heapify(h, n, x, max);
    }
}

int main() {
    int h[100], n, choice;

    cout << "1. Max Heap\n2. Min Heap\nChoice: ";
    cin >> choice;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    for (int i = n/2; i >= 1; i--)
        heapify(h, n, i, choice == 1);

    cout << "Heap: ";
    for (int i = 1; i <= n; i++)
        cout << h[i] << " ";

    return 0;
}