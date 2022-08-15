#include <iostream>
int ** prodEscalarMatrices(int ** mat, const int K){
  const int N = sizeof(*mat)/sizeof(**mat);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      std::cout << mat[i][j] << ",";
      mat[i][j] *= K;
      std::cout << mat[i][j] << " ";
    }
    std::cout << "\n";
  }
  return mat;
}

int main(){
  
  int arr[2][2] = {
    {1,2}, 
    {3,4}
  };
  int * mat1 [2];
  mat1[0] = arr[0];
  mat1[1] = arr[1];
  int ** mat = prodEscalarMatrices(mat1, 4);
  return 0;
}