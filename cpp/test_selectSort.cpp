#include "selectSort.h"
using namespace std;
#include <iostream>
int main() {
  int a[]{1, 2, 5, 4};
  int size = sizeof(a) / sizeof(a[0]);
  selectSort(a, size);
  for (int i = 0; i < size; i++) {
    cout << a[i] << endl;
  }
  std::array<int, 4> b{1, 2, 5, 4};
  selectSort(b);
  for (int i = 0; i < size; i++) {
    cout << b[i] << endl;
  }
}
