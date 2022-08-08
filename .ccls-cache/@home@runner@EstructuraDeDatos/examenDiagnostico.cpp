#include <iostream>

using namespace std;


/**
* La funcion regresa las posiciones de los terminator
*/
int * terminatorFinder(int * arr, const int n){
  if(n == 0) return new int {-1};
  for(int i = 0; i < n; i++){
    if(i == 0){
      if(*arr > *(arr + 1)) return new int{0};
    }
    else if(i == n-1){
      if(*(arr + n - 1) > *(arr + n - 2)) return new int {n-1};
    }
    else{
      if(arr[i-1] < arr[i] && arr[i+1] < arr[i]) return new int{i};
    }
    
  }
}

int main(){
  int arr[] = {1, 2, 3, 5};
  int * ptr = arr;
  cout << *terminatorFinder(ptr, 4) << endl;
}