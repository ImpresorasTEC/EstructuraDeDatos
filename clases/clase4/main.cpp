#include <iostream>
using namespace std;

int largestElement(int arr[], int N){
  
  int max = arr[0]; // O(1)
  for(int i = 0; i < N; i++) { // O(n)
    if(arr[i] > max) { // O(1)
        max = arr[i]; // O(1)
    }
  }

  return max; // O(1)
}
// Complejidad O(n)

/*
* La función encuentra los elementos repetidos en un arreglo. 
*/
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

void twoArraySum(){

    int n;
    int i;
    cout << "Numero de items en cada lista listas: \n";
    cin>>n;
    n = n+1; // O(1)
    int *arr = new int(n); // O(1)
    int *arry = new int(n); // O(1)
    int *arresultado = new int(n); // O(1)


    cout << "Introduce " << n << " Elementos para la primera lista" << endl;

    for (i = 0; i < n; i++){ // O(n)

        cin >> arr[i]; // O(1)
    }

    cout << "Introduce " << n << " Elementos para la segunda lista" << endl;

    for (i = 0; i < n; i++){ // O(n)

        cin >> arry[i];// O(1)
    }

    cout << "Sumando cada elemento respectivo en ambas listas... \n \n ... ... ... ... ...\n \n ... ... ... ... ...";
    cout << "\nEl resultado es: \n";
    for(i=0; i < n; i++){ // O(n)
        arresultado[i] = arr[i] + arry[i]; // O(1)
        cout << arresultado[i]<<" "; // O(1)
    }
};
// Complejidad de O(n)


int main(){
  int arr[5] = {10, 50, 4, 500, 45};
  int N = sizeof(arr)/sizeof(arr[0]);
  cout << largestElement(arr, N) << endl;
  twoArraySum();


  return 0;
}