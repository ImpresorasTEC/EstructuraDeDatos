/**
 * @file examenDiagnostico.cpp
 * @author Ernesto Miranda Solis (A01656828)
 * @brief El programa encuentra un elemento terminator en un arreglo. Un elemento es un terminator si NO es más pequeño que sus vecinos. Para elementos de esquina, debemos considerar solo un vecino.
 * @version 0.1
 * @date 2022-08-08
 * 
 */

#include <iostream>

using namespace std;

/**
 * @brief Cuenta los terminators en un arreglo
 * 
 * @param arr arreglo de numeros
 * @param N tamaño del arreglo
 * @return int el numero de terminators en el arreglo
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
 * @brief La funcion regresa las posiciones de los terminators
 * 
 * @param arr el arreglo de numeros
 * @param N el tamaño del arreglo
 * @return int* apuntador con las posiciones de los terminators
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

void printPositions(int * terminators){
  int size = sizeof(terminators)/sizeof(*terminators);
  if(size == 0) {
    cout << "Empty array!\n";
    return;
  }
  for(int i = 0; i < size; i++){
    cout << "Posicion " << i+1 << ": " << *(terminators + i) << endl;
  }
}

namespace testCases{
  /**
   * @brief Test case 1, el output de esta funcion debe ser 2
   * 
   */
  void caseOne() {
    int arr[] = {5, 10, 20, 15};
    int * terminators = terminatorFinder(arr, 4);
    printPositions(terminators);
  }
  /**
   * @brief Test case 2, el output debe ser 1
   * 
   */
  void caseTwo(){
    int arr[] = {10, 20, 15, 2, 23, 90, 67};
    int * terminators = terminatorFinder(arr, 7);
    printPositions(terminators);
  }
  void caseThree(){
    int * ptr= new int;
    int * terminators = terminatorFinder(ptr, 0);
    printPositions(terminators);
  }
}

int main(){
  testCases::caseThree();
}