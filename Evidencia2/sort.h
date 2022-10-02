
#include "lista.h"
template <typename T>
void countSort(LinkedList<T> & array) {
  LinkedList<T> output;
  int count [array.size()];
  int max = array[0];

  for (int i = 1; i < array.size(); i++) {
    if (array[i] > max)
      max = array[i];
  }

  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
    cout << "DEBUG\n";
  }
  
  for (int i = 0; i < array.size(); i++) {
    count[array[i]]++;
  }


  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }
  
  for (int i = array.size() - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  for (int i = 0; i < array.size(); i++) {
    array[i] = output[i];
  }
}

/**
* @brief Une ambos arreglos
* @param leftSubArray arreglo de la mitad izquierda
* @param rightSubArray arreglo de la mitad derecha
* @param arr arreglo principal
* @param LEFT_LENGTH longitud del arreglo de izquierda
* @param RIGHT_LENGTH longitud del arreglo de derecha
*/
template <class T>
void mergeArray(LinkedList<T> & leftSubArray, LinkedList<T> & rightSubArray, LinkedList<T> & arr)
{
  const int LEFT_LENGTH = leftSubArray.size(), 
  RIGHT_LENGTH = rightSubArray.size();;
  int i = 0; // O(1)
  int j = 0; // O(1)
  int k = 0; // O(1)

  while (i < LEFT_LENGTH && j < RIGHT_LENGTH) { // O(N)
    if (leftSubArray[i] <= rightSubArray[j]) // O(1)
      arr[k++] = leftSubArray[i++];
    else // O(1)
      arr[k++] = rightSubArray[j++]; 
  }
  
    for(; i < LEFT_LENGTH; i++) // O(N)
    arr[k++] = leftSubArray[i];

  for(; j < RIGHT_LENGTH; j++) // O(M)
    arr[k++] = rightSubArray[j];
}

template <class T>
void mergeSort(LinkedList<T> & arr){
  const int SIZE = arr.size();
	if (SIZE == 0) return; // O(1)
  if (SIZE == 1) return; // O(1)
  const int LEFT  = SIZE / 2; // O(1)
  const int RIGHT = SIZE - LEFT; // O(1)

  LinkedList<T> leftSubArray, rightSubArray; // O(1)
        
  int k = 0; // O(1)

  for(int i = 0; i < LEFT; i++) // O(N)
    leftSubArray[i] = arr[k++]; // O(1)

  for(int j = 0; j < RIGHT; j++) // O(M)
    rightSubArray[j] = arr[k++]; // O(1)
  
  //Merge sort en la izquierda
  mergeSort(leftSubArray); // O(log_2(n)))
    
  //Merge sort en la derecha
  mergeSort(rightSubArray); // O(log_2(n))
    
  //Merge completo
  mergeArray(leftSubArray, rightSubArray, arr); // O(N + M)
}