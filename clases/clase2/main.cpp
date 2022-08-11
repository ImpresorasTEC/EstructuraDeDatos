#include <iostream>
using namespace std;

void salta(int n){
  for(int i = 0; i < n; i++){
    cout << "Salta" << endl;
  }
}

void saltaRecursivo(int n){
  if(n > 0) {
    cout << "Salta" << endl;
    saltaRecursivo(n-1);
  }
}

int factorial(unsigned int n){
  int x = 1;
  do{
    x *= n;
    n--;
  } while(n>1);
  return x;
}

int factorialRecursivo(unsigned int n){
  if(n == 0) return 1;
  return n * factorialRecursivo(n-1);
}

int main(){
  salta(3);
  cout << endl;
  saltaRecursivo(3);

  cout << factorial(5) << endl;
  cout << factorialRecursivo(5) << endl;
  return 0;
}