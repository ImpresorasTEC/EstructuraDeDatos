/**
* EL programa encuentra un elemento Terminator en un arreglo. Un elemento es un terminator si NO es más pequeño que sus vecinos. Para elementos de esquina, debemos considerar solo un vecino.
* @author: Ernesto Miranda Solis
* @date: 8.8.22
*/


#include <iostream>

using namespace std;

/**
* Cuenta los terminators en un array.
* @params: 
* - 
*/
int countTerminators(int * arr, const int N){
  int counter = 0;
  for(int i = 0; i < N; i++){
    if(i == 0){
      if(*arr >= *(arr + 1)) counter++;
    }
    else if(i == N-1){
      if(*(arr + N - 1) >= *(arr + N - 2)) counter++;
    }
    else{
      if(arr[i-1] <= arr[i] && arr[i+1] <= arr[i]) counter++;
    }
  }
  return counter;
}

/**
* La funcion regresa las posiciones de los terminator
*/
int * terminatorFinder(int * arr, const int N){
  if(N == 0) return new int {-1};
  int counter = 0, * terminators = new int[countTerminators(arr, N)];
  for(int i = 0; i < N; i++){
    if(i == 0){
      if(*arr >= *(arr + 1)) {
        *terminators = *arr;
        counter++;
        }
    }
    else if(i == N-1){
      if(*(arr + N - 1) >= *(arr + N - 2)){
        *(terminators+counter)= N-1;
        counter++;
      }
    }
    else{
      if(arr[i-1] <= arr[i] && arr[i+1] <= arr[i]) {
        *(terminators+counter) = i;
        counter++;
      }
    }
  }
  return terminators;
}

int main(){
  int arr[] = {10, 20, 15, 2, 23, 90, 67};
  int * ptr = arr, * terminators;
  terminators = terminatorFinder(ptr, 7);
  int size = sizeof(terminators)/sizeof(*terminators);
  for(int i = 0; i < size; i++){
    cout << *(terminators + i) << endl;
  }
}