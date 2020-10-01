package sorting;

public class MergeSortMain {

  public static void main(String[] args) {
    MergeSort obj = new MergeSort();
    int a[] = {7, -9, 0, 4, 8, 9, 1, 15, 44, 2, -4, 6};

    System.out.println("");
    obj.mergesort(a, 0, a.length - 1);
    obj.printArray(a);
  }
}
class MergeSort {
  public void mergesort(int arr[], int l, int r) {
    if (r > l) {
      int m = (l + r) / 2;
      mergesort(arr, l, m); // sort the two array
      mergesort(arr, m + 1, r);
      merge(arr, l, m, r); // merge the array
    }
  }
  // function to merge the array
  public void merge(int arr[], int l, int m, int r) {
    int leftArray[] = new int[m - l + 1];
    int rightArray[] = new int[r - m];

    // storing the array in left and right
    for (int i = 0; i < m - l + 1; i++) {
      leftArray[i] = arr[l + i];
    }
    for (int j = 0; j < r - m; j++) {
      rightArray[j] = arr[m + 1 + j];
    }
    int i = 0, j = 0;
    int k = l;
    while (i < m - l + 1 && j < r - m) {
      if (leftArray[i] <= rightArray[j]) {
        arr[k] = leftArray[i];
        i++;
      } else {
        arr[k] = rightArray[j];
        j++;
      }
      k++;
    }
    while (i < m - l + 1) { // if any element remaining in left array
      arr[k] = leftArray[i];
      i++;
      k++;
    }
    while (j < r - m) {
      arr[k] = rightArray[j]; // if any element remaining in right array
      k++;
      j++;
    }
  }

  // printing the sorted array
  public void printArray(int[] array) {
    for (int i = 0; i < array.length; i++) {
      System.out.print(array[i] + " ");
    }
  }
}
