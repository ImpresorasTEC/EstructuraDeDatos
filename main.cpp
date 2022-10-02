#include "persona.h"
#include "lista.h"
#include "sort.h"
#include <fstream>
#include "sstream"
using namespace std;

void mostPopulated(LinkedList<Persona> data){
  cout << "--- 5 GREATEST CITIES ---\n";
  LinkedList<string> cities;
  LinkedList<int> nums;
  string city;
  for(int i = 0; i < data.size(); i++){
    city = data[i].getCity();
    if(cities.contains(city)){
      nums[cities.find(city)]++;
    } else{ 
      cities.addLast(city);
      nums.addLast(1);
    }
  }
  countSort(nums);
  int greatest, greatestIndex, population;
  for(int i = 0; i < 5; i++){
    greatest = nums[0], greatestIndex = 0;
    for(int j = 0; j > nums.size(); j++){
      if(greatest < nums[j]){
        greatest = nums[j];
        greatestIndex = j;
      }
    } 
    city = cities.remove(greatestIndex);
    population = nums.remove(greatestIndex);
    cout << city <<"\n";
  }
};

int frequencyName(LinkedList<Persona> &data, string fname) {
  int count = 0;
  for(int i = 0; i < data.size(); i++) {
    if(data[i].getName() == fname) {
      count ++;
    }
  }

  return count;
};

int habitants(LinkedList<Persona> &data, string city) {
  int count = 0;
  for(int i = 0; i < data.size(); i++) {
    if(data[i].getCity() == city) {
      count++;
    }
  }

  return count;
};

int main() {
  stringstream ss;
  LinkedList<Persona> data;
  
  ifstream MyReadFile("debug.csv");
  string myText;
  getline(MyReadFile,myText);
  while(getline(MyReadFile, myText)) {
    ss << myText.substr(0, myText.find(","));
    int id;
    ss >> id;
    ss.clear();
    myText = myText.substr(myText.find(",")+1, myText.length());
    string firstName = myText.substr(0, myText.find(","));
    myText = myText.substr(myText.find(",")+1, myText.length());
    string lastName = myText.substr(0, myText.find(","));
    myText = myText.substr(myText.find(",")+1, myText.length());
    int zip; 
    ss << myText.substr(0, myText.find(","));
    ss >> zip;
    ss.clear();
    string city = myText.substr(myText.find(",")+1, myText.length());
    data.addLast(Persona(id, zip, firstName, lastName, city));
  }
  mostPopulated(data);
  cout << frequencyName(data, "jeffery") << endl;
  cout << habitants(data, "Fort Worth") << endl;
   
 
  // cout << data;
  cout << "finito" << endl;  
}
