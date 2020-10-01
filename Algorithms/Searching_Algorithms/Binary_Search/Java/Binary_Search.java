// Binary Search Practice/ Implementation
package binarySearch;

import java.util.Scanner;

public class BinarySearchMain {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter n i.e total number of elements in array");
    int n = sc.nextInt();

    int arr[] = new int[n];
    System.out.println("enter " + n + " numbers in sorted array:");
    for (int i = 0; i < n; i++)
      arr[i] = sc.nextInt();
    System.out.println("Enter a number to find in the array :");
    int num = sc.nextInt();

    sc.close();

    // creating object of class binary search
    BinarySearch obj = new BinarySearch();
    int res = obj.binarySearch(arr, 0, n - 1, num);
    if (res == -1)
      System.out.println("Number not found");
    else
      System.out.println("number found at index : " + res);
  }
}

class BinarySearch {
  int binarySearch(int arr[], int l, int r, int x) {

    if (r >= l) {

      int mid = (l + r) / 2;
      if (arr[mid] == x)
        return mid;
      if (arr[mid] > x) // if given number is less than mid of the array
        return binarySearch(arr, l, mid - 1, x);

      return binarySearch(arr, mid + 1, r, x);
    }
    // the given number is not present in the array
    return -1;
  }
}
