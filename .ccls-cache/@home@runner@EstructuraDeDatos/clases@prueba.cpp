#include <iostream>
#include <vector>
using namespace std;

vector<int> rep(vector<int> nums){
  vector<int> reps;
  for(auto i = nums.begin(); i != nums.end(); i++){
    
  }
  return reps;
}

void repeatedElements(int * arr, const int N){
  int * copy = new int [N]; // O(1)
  for(int i = 0; i < N; i++){ // O(n)
    copy[i] = arr[i]; // O(1)
  }
  for(int i = 0; i < N; i++){ // O(n)
    if(arr[i] >= 0) arr[arr[i] % N] += N; // O(1)
  }
  for(int i = 0; i < N; i++){ // O(n)
    if(abs(arr[i]) >= N * 2) 
      cout << copy[i] << " "; // O(1)    
  }
  cout << endl; // O(1)
  delete [] copy; // O(1)
}
// Complejidad de O(n)

int main(){
  int array[10] = {0, 0, 0, 1, 2, 3, 6, 3, 6, 1};
  int * arrPtr = new int[10];
  arrPtr = array;
  repeatedElements(arrPtr, 10);
}