#include "cArreglo.h"
#include <random>
using namespace std;

template <class T>
T minVal(T a, T b){
  return (a < b) ? a : b;
}

template<class T>
T suma(T a, T b){
  return a + b;
}

template <class T>
void bubbleSort(T * arr, const int N){
  T temp;
  for (int i = 1; i < N; i++){
    for (int j = 0; j < N-1; j++){
      if(arr[j] > arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int main(){
  double x = 1.5, y = 3.5;
  cout << minVal(x, y) << endl;
  cout << suma(x, y) << endl;
  srand(0);
  Arreglo<string> arr;
  for(int i = 0; i < 20; i++){
    arr.add("hoy toca " + to_string(rand() % 20));
  }
  arr.print();

  cout << "Bubble Sort\n";
  int a [7] = {4, 2, 6, -2, 8, 9, 3};
  int * aPtr = a;
  bubbleSort(aPtr, 7);
  for(int i = 0; i < 7; i++)
    cout << aPtr[i] << " ";
  cout << "\n";
  return 0;
}