package sorting;

public class InsertionSortMain {

	public static void main(String[] args) {
		// creating object of class InsertionSort
		InsertionSort obj = new InsertionSort();
		int a[] = { 5,4,-7,-9,34,21,3,1,0 };
		
		System.out.println("");
		obj.insertsort(a);

	}

}
class InsertionSort{
	void insertsort(int arr[]) {
		for(int i=1;i<arr.length;i++) {
			//Storing the current array element in temporary variable
			int temp=arr[i];
			int j=i;
			
			// continuously comparing previous element with current element  
			while(j>0 && arr[j-1]>temp) {
				arr[j]=arr[j-1];			//increasing the index of larger element (index j) by one
											// arr[j] is now empty.
				j--;
			}
			
			// storing our current element to the empty place
			arr[j]=temp;
		}
		
		//printing the sorted array
		for(int i=0;i<arr.length;i++) {
			System.out.print(arr[i]+" ");
		}
		
	}
}
