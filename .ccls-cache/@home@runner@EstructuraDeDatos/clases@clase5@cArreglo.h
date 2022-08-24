#include <iostream>

template <class T>
class Arreglo{
  private:
    T arr[100];
    int pos;
  public:
    Arreglo(){
      pos = 0;
    }
    void add(T dato){
      if(pos < 100)
        arr[pos++] = dato;
    }
    void print(){
      for(int i = 0; i < pos; i++)
        std::cout << arr[i] << "\n";
    }
};