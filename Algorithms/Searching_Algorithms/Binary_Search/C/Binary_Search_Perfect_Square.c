// Program in C to implement binary search algorithm while finding out whether a
// number is a perfect square or not
#include <stdio.h>

// Recursive function to implement binary search.It returns the number,of which
// the given number is a perfect square. Otherwise,it returns the floor of it's
// square root.(rounded off to the next integer) e.g.,for 100,it will
// return 10.While for 99,it will also return 10.

int perfectSquare(int l, int r, int number) {
  int mid = (l + r) / 2;
  // Binary Search
  while (l <= r) {
    if (l > r) {
      return -1;
    }
    if (mid * mid == number)
      return mid;
    // moves to left half
    else if (mid * mid > number)
      return perfectSquare(l, mid - 1, number);
    // moves to right half
    else
      return perfectSquare(mid + 1, r, number);
  }
}

// Driver program to test the above function
int main() {
  int number = 1225;
  printf("%d", perfectSquare(1, number, number));

  return 0;
}
