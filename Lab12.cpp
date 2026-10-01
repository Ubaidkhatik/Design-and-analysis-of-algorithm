#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight, profit;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n, capacity;
    double profit = 0;

    cout << "Enter number of items: ";
    cin >> n;

    Item a[n];

    cout << "Enter weight and profit:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i].weight >> a[i].profit;
        a[i].ratio = (double)a[i].profit / a[i].weight;
    }

    cout << "Enter capacity: ";
    cin >> capacity;

    sort(a, a + n, compare);

    for (int i = 0; i < n && capacity > 0; i++) {
        if (a[i].weight <= capacity) {
            capacity -= a[i].weight;
            profit += a[i].profit;
        } else {
            profit += a[i].ratio * capacity;
            capacity = 0;
        }
    }

    cout << "Maximum Profit = " << profit;

    return 0;
}