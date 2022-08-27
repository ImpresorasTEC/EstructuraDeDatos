#include <iostream>
#include <random>
#include <ctime>
#include <chrono>

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
void mergeSort(T * arr, const int SIZE){
	if (SIZE == 0) return;
  if (SIZE == 1) return;
  const int LEFT  = SIZE / 2;
  const int RIGHT = SIZE - LEFT;

  T * leftSubArray = new T [LEFT];
  T * rightSubArray = new T [RIGHT];
        
  int k = 0;

  for(int i = 0; i < LEFT; i++)
    leftSubArray[i] = arr[k++];

  for(int j = 0; j < RIGHT; j++)
    rightSubArray[j] = arr[k++];
  
  //Merge sort en la izquierda
  mergeSort(leftSubArray, LEFT);
    
  //Merge sort en la derecha
  mergeSort(rightSubArray, RIGHT);
    
  //Merge completo
  mergeTwoSortedArray(leftSubArray, rightSubArray, arr, LEFT, RIGHT);
}

int main(){

  
  srand(time(NULL));
  int size = 1000000;
  int * nums = new int [size];
  for(int i = 0; i < size; i++){
    nums[i] = rand() % 100000;
  }
  auto start = chrono::system_clock::now();
  mergeSort(nums, size);
  auto end = chrono::system_clock::now();
  chrono::duration<double> elapsed_seconds = end-start;
  cout << "Ellapsed time: " << elapsed_seconds.count() << " seconds.\n";
  for(int i = size - 51; i < size; i++){
    cout << nums[i] << " ";
    if(i+1 % 10 == 0) cout << "\n";
  }
}