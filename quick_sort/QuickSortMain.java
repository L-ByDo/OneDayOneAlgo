package sorting;

public class QuickSortMain {

	public static void main(String[] args) {
		QuickSort obj = new QuickSort();
		int a[] = {7,3,1,-9,-4,6,11,24,55,2,0};
		
		System.out.println("");
		obj.quicksort(a,0,a.length-1);
		obj.printArray(a);

	}

}
class QuickSort{
	void quicksort(int arr[],int start, int end) {
		if(start<end) {
			int pivot=partition(arr,start,end);
			quicksort(arr,start,pivot-1);
			quicksort(arr,pivot+1,end);
		}
	}
	
	int partition(int arr[],int p,int q) {
		int i=p-1;
		for(int j=p;j<=q;j++) {
			if(arr[j]<=arr[q]) {
				i++;
				int temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
		return i;
	}
	//printing sorted array
	void printArray(int arr[]) {
		for(int i=0;i<arr.length;i++) {
			System.out.print(arr[i]+" ");
		}
	}
}
