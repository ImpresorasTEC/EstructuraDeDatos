#include <string>
#include <ostream>
using namespace std;

class Task{
  private:
    string id;
    int value;
  public:
    Task(string id = "", int value = 0){
      this->id = id;
      this->value = value;
    }
    bool operator < (const Task & t){
      return value < t.value; 
    }
    bool operator > (const Task & t){
      return value > t.value;
    }
    friend ostream & operator << (ostream & os, const Task & t){
      os << t.id << " :: " << t.value;
      return os; 
    }
};
