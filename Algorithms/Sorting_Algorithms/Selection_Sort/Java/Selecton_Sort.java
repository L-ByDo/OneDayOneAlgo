// Implementation of selection sort

package sorting;

public class SelectonSortMain {

  public static void main(String[] args) {
    SelectionSort obj = new SelectionSort();
    int a[] = {1, 5, 3, 7, 4, 76, 32}; // given unsorted array

    System.out.println("");
    obj.selectSort(a);
  }
}

class SelectionSort {
  public void selectSort(int arr[]) {
    int j = 0;
    for (int i = 0; i < arr.length - 1; i++) {
      int minIn = i;
      for (j = i + 1; j < arr.length; j++) {
        if (arr[j] < arr[minIn]) {
          minIn = j; // Finding minimum element in the unsorted array
        }
      }
      if (i != minIn) {
        int temp = arr[minIn]; // Swapping the first number in an unsorted array
                               // with minimum number
        arr[minIn] = arr[i];
        arr[i] = temp;
      }
    }
    // Printing the Sorted Array
    for (j = 0; j < arr.length; j++)
      System.out.print(arr[j] + " ");
  }
}
