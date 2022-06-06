#include <array>
template <typename T>
void selectSort(T alist[], const int size) {
  for (int i = 0; i < size; i++) {
    int min_index = i;
    for (int j = i + 1; j < size; j++) {
      if (alist[j] < alist[min_index]) {
        min_index = j;
      }
    }
    T temp = alist[i];
    alist[i] = alist[min_index];
    alist[min_index] = temp;
  }
}

template <typename T, long unsigned int N>
void selectSort(std::array<T, N> &alist) {
  for (int i = 0; i < N; i++) {
    int min_index = i;
    for (int j = i + 1; j < N; j++) {
      if (alist[j] < alist[min_index]) {
        min_index = j;
      }
    }
    T temp = alist[i];
    alist[i] = alist[min_index];
    alist[min_index] = temp;
  }
}