#include <iostream>
using namespace std;
void insert(int h[], int &n, int x, bool maxHeap) {
    h[++n] = x;
    int i = n;
 while (i > 1 && (maxHeap ? h[i] > h[i/2] : h[i] < h[i/2])) {
        swap(h[i], h[i/2]);
        i /= 2;
  }}
int main() {
    int h[100], n = 0, x, choice, size;
 cout << "1. Max Heap\n2. Min Heap\nChoice: ";
  cin >> choice;
cout << "Enter number of elements: ";
  cin >> size;
 for (int i = 0; i < size; i++) {
        cin >> x;
        insert(h, n, x, choice == 1);}
cout << "Heap: ";
    for (int i = 1; i <= n; i++)
        cout << h[i] << " ";
 return 0;
}
