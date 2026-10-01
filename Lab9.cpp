#include <iostream>
using namespace std;

void maxmin(int a[], int l, int h, int &mn, int &mx) {
    if (l == h)
        mn = mx = a[l];
    else {
        int m = (l + h) / 2;
        int mn1, mx1;

        maxmin(a, l, m, mn, mx);
        maxmin(a, m + 1, h, mn1, mx1);

        if (mn1 < mn) mn = mn1;
        if (mx1 > mx) mx = mx1;
    }
}

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int mn, mx;
    maxmin(a, 0, n - 1, mn, mx);

    cout << "Minimum = " << mn << endl;
    cout << "Maximum = " << mx;

    return 0;
}
