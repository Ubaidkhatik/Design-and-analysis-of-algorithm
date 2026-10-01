#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void merge(int a[], int l, int m, int h, bool asc) {
    int i = l, j = m + 1, k = 0;
    int t[h - l + 1];

    while (i <= m && j <= h)
        t[k++] = (asc ? a[i] <= a[j] : a[i] >= a[j]) ? a[i++] : a[j++];

    while (i <= m) t[k++] = a[i++];
    while (j <= h) t[k++] = a[j++];

    for (i = l, k = 0; i <= h; i++, k++)
        a[i] = t[k];
}

void mergeSort(int a[], int l, int h, bool asc) {
    if (l < h) {
        int m = (l + h) / 2;
        mergeSort(a, l, m, asc);
        mergeSort(a, m + 1, h, asc);
        merge(a, l, m, h, asc);
    }
}

void quickSort(int a[], int l, int h, bool asc) {
    if (l >= h) return;

    int p = a[h], i = l - 1;

    for (int j = l; j < h; j++)
        if (asc ? a[j] <= p : a[j] >= p)
            swap(a[++i], a[j]);

    swap(a[i + 1], a[h]);
    int x = i + 1;

    quickSort(a, l, x - 1, asc);
    quickSort(a, x + 1, h, asc);
}

void test(int n, bool asc) {
    int *a = new int[n], *b = new int[n];

    for (int i = 0; i < n; i++)
        a[i] = b[i] = n - i;

    auto s = high_resolution_clock::now();
    mergeSort(a, 0, n - 1, asc);
    auto e = high_resolution_clock::now();
    auto mt = duration_cast<microseconds>(e - s).count();

    s = high_resolution_clock::now();
    quickSort(b, 0, n - 1, asc);
    e = high_resolution_clock::now();
    auto qt = duration_cast<microseconds>(e - s).count();

    cout << "n = " << n
         << " | Merge = " << mt << " us"
         << " | Quick = " << qt << " us\n";

    delete[] a;
    delete[] b;
}

int main() {
    int choice;
    cout << "1. Ascending\n2. Descending\nChoice: ";
    cin >> choice;

    bool asc = choice == 1;

    test(1000, asc);
    test(2000, asc);
    test(3000, asc);

    return 0;
}