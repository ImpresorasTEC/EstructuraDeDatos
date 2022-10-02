#include <iostream>

template <typename T>
class ArrayStack{
  private:
    T * elements;
    int size, count = 0;
  public:
    ArrayStack(int size = 16){
      this->size = size;
      elements = new T [size];
    }
    void push(T element){
      if(count < size)
        elements[count++] = element;
    }
    T pop(){
      T * temp = new T [size], el = elements[count-- -1];
      for(int i = 0; i < count; i++){
        *(temp+i) = elements[i];
        *(elements + i) = *(temp + i);
      }
      delete temp;
      return el;
    }
    void print(){
      for(int i = 0; i < count; i++)
        std::cout << elements[i] << "\n";
    }
};