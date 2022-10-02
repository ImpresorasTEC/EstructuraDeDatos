
#include <time.h>

#include "lista.h"
#include "task.h"

int main() {
  srand(time(NULL));
  Queue<Task> a, b;
  for(int i = 0; i < 10; i++){
    a.enqueue(Task("A" + to_string(rand() % 100), rand()%10+1));
    b.enqueue(Task("B" + to_string(rand() % 100), rand()%10+1));
  }

  cout << a << b << "\n";

  while(!a.is_empty()){
    cout << a.dequeueMax() << " # ";
  }
  cout << "\n";
  while(!b.is_empty()){
    cout << b.dequeueMin() << " @ "; 
  }
  cout << "\n";
  
  return 0;
}
