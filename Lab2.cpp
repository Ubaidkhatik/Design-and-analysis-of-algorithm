#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter n and m: ";
    cin >> n >> m;

    if (m < 0 || m > n) {
        cout << "Invalid input";
        return 0;
    }

    int C[n + 1][m + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m && j <= i; j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    cout << "Binomial Coefficient = " << C[n][m];

    return 0;
}