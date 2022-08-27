#include <iostream>

using namespace std;

template <class T>
void mergeTwoSortedArray(T * leftSubArray, T * rightSubArray, T * arr, const int LEFT_LENGTH, const int RIGHT_LENGTH)
{
  int i = 0;
  int j = 0;
  int k = 0;


  while (i < LEFT_LENGTH && j < RIGHT_LENGTH) {
    if (leftSubArray[i] <= rightSubArray[j]) 
      arr[k++] = leftSubArray[i++];
    else 
      arr[k++] = rightSubArray[j++];
  }

  for(; i < LEFT_LENGTH; i++)
    arr[k++] = leftSubArray[i];

  for(; j < RIGHT_LENGTH; j++)
    arr[k++] = rightSubArray[j];
}

template <class T>
void mergeSort(T arr[], const int SIZE){
	//this is a special case - it means we don't have an array to sort. Mind that the array size can never be less than 0
	if (SIZE == 0) {
		return;
}

     // if only one element is present in arr then we don't need to divide array further as one element is sorted in itself.
       if(SIZE == 1)
       {
        	return;
       }
    // create leftSubArray and rightSubArray - and copy the elements as it is from arr.
        int n  = SIZE / 2;
        int m = SIZE - n;

        int leftSubArray[n];
        int rightSubArray[m];
        
   //pointer for arr
        int k = 0;

        for(int i = 0; i < n; i++)
        {
            leftSubArray[i] = arr[k];
            k++;
        }

        for(int j = 0; j < m; j++)
        {
            rightSubArray[j] = arr[k];
            k++;
        }
    
     //call mergeSort on left subarray
        mergeSort(leftSubArray, n);
    
     //call mergeSort on right subarray
        mergeSort(rightSubArray, m);
    
     //merging the two sorted subarrays back to the original one
        mergeTwoSortedArray(leftSubArray, rightSubArray, arr, n, m);
        return;
}

int main(){
    int arr[] = { 14, 17, 22, 4, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr,n);
    
    cout<<"Sorted array: ";
    for(int i = 0; i < n; i++)
    {
         cout<<arr[i]<<" ";
    }
   
    return 0;
}