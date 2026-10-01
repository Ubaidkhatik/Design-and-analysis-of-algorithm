#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void heapify(int a[], int n, int i, bool asc) {
    int x = i, l = 2*i+1, r = 2*i+2;

    if (l < n && (asc ? a[l] > a[x] : a[l] < a[x]))
        x = l;

    if (r < n && (asc ? a[r] > a[x] : a[r] < a[x]))
        x = r;

    if (x != i) {
        swap(a[i], a[x]);
        heapify(a, n, x, asc);
    }
}

void heapSort(int a[], int n, bool asc) {
    for (int i = n/2-1; i >= 0; i--)
        heapify(a, n, i, asc);

    for (int i = n-1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0, asc);
    }
}

void test(int n, bool asc) {
    int *a = new int[n];

    for (int i = 0; i < n; i++)
        a[i] = n - i;

    auto start = high_resolution_clock::now();

    heapSort(a, n, asc);

    auto end = high_resolution_clock::now();

    cout << "n = " << n << " | Time = "
         << duration_cast<microseconds>(end-start).count()
         << " microseconds\n";

    delete[] a;
}

int main() {
    int choice;
    cout << "1. Ascending\n2. Descending\nChoice: ";
    cin >> choice;

    bool asc = (choice == 1);

    cout << "\nHeap Sort Execution Time\n";
    test(1000, asc);
    test(2000, asc);
    test(3000, asc);

    return 0;
}