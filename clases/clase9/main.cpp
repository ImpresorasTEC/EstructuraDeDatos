#include "stack.h"

/**
* @author: Ernesto Miranda Solis
*/
int main(){
  int size, el;
  std::cout << "Ingresa el numero de elementos: ";
  std::cin >> size;
  ArrayStack <int> stack(size);
  for(int i = 0; i < size; i++){
    std::cin >> el;
    stack.push(el);
  }
  std::cout << "\n\n";
  for(int i = 0; i < size; i++){
    std::cout << stack.pop() << "\n";
  }
}