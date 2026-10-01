#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int binarySearch(int a[], int n, int key) {
    int l = 0, h = n - 1;

    while (l <= h) {
        int m = (l + h) / 2;

        if (a[m] == key)
            return m;
        if (a[m] < key)
            l = m + 1;
        else
            h = m - 1;
    }

    return -1;
}

void test(int n, int key) {
    int *a = new int[n];

    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    auto start = high_resolution_clock::now();
    int result = binarySearch(a, n, key);
    auto end = high_resolution_clock::now();

    cout << "n = " << n
         << " | " << (result != -1 ? "Found" : "Not Found")
         << " | Time = "
         << duration_cast<nanoseconds>(end - start).count()
         << " ns\n";

    delete[] a;
}

int main() {
    int key;
    cout << "Enter element to search: ";
    cin >> key;

    test(1000, key);
    test(2000, key);
    test(3000, key);

    return 0;
}