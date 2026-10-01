#include <iostream>
using namespace std;

int board[20][20], n;

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

void solve(int row) {
    if (row == n) {
        cout << "Solution:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            solve(row + 1);
            board[row][col] = 0;
        }
    }
}

int main() {
    cout << "Enter value of N: ";
    cin >> n;

    solve(0);

    return 0;
}