#include <iostream>
void f(int a){ // Paso por valor
  a++;
}
void g(int & a){ // Paso por referencia
  a++;
}
void h(int * a){ // Paso por apuntador
  *a++;
}
int main(){
  int z = 10;
  f(z);
  std::cout << z << std::endl;
  g(z);
  std::cout << z << std::endl;
  h(&z);
  std::cout << z << std::endl;
  
  int arreglo [] = {7, 8, 9, 10};
  for(int i = 0; i < 4; i++){
    std::cout << arreglo[i] << std::endl;
  }
  int * j = arreglo;
  for(int i = 0; i < 4; i++){
    std::cout << *(j+i) << std::endl;
  }
}