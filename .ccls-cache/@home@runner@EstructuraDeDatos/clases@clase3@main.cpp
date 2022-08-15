

int ** sumaMatrices (int ** A, int ** B) {
  const int N = sizeof(*A)/sizeof(**B); // O(1)
  int ** C = new int*[N]; // O(1)
  for(int i = 0; i < N; i++){ // O(n^2)
    *(C+i) = new int[N]; // O(1)
    for(int j = 0; j < N; j++) { // O(n)
      C[i][j] = A[i][j] + B[i][j]; // O(1)
      }
    }
  return C;
} // Complejidad de la función O(n^2)

/*
Escribe un función que calcule el producto de un matriz por un escalar y obtén su complejidad. Al ser un apuntador, no se necesita una variable de retorno. 
*/
void prodEscalarMatrices(int ** mat, const int K){
  const int N = sizeof(*mat)/sizeof(**mat); // O(1)
  for(int i = 0; i < N; i++){ // O(n^2)
    for(int j = 0; j < N; j++){ // O(n)
      mat[i][j] *= K; // O(1)
    }
  }
} // Complejidad de la función O(n^2)

#include <iostream>
using namespace std;

int main(){
  int arr[2][2] = {
    {1,2}, 
    {3,4}
  };
  int arr2[2][2] = {
    {3, 4}, 
    {5, 6}
  };
  int * mat1 [2], *mat2[2];
  mat1[0] = arr[0];
  mat1[1] = arr[1];
  mat2[0] = arr2[0];
  mat2[1] = arr2[1];
  prodEscalarMatrices(mat1, 3);
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      cout << mat1[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
  int ** C = sumaMatrices(mat1, mat2);
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      cout << C[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}