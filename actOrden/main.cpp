#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

template <class T>
void bubbleSort(T & names, int n) {
  T temp, * arr = new T [n];
  std::stringstream namesStream (names);
  int i = 0;
  while(std::getline(namesStream, temp)){
    arr[i++] = temp;
  }
  for (int i=0; i<n; i++){
    for (int j=0; j<n-1; j++){
      if (arr[j] > arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  names = "";
  for(int i = 0; i < n; i++){
    names += arr[i] + "\n";
  }
}

template <class T>
void sequentialSearch(T & names, int n, char search) {
  T temp, * arr = new T [n];
  std::stringstream namesStream (names);
  int i = 0;
  while(std::getline(namesStream, temp)){
    arr[i++] = temp;
  }
  std::ofstream out("out.csv");
  for(int i=0; i <n; i++) {
    temp = arr[i];
    if(temp[0] == search) {
    out << arr[i] << "\n";
    }
  }
  out.close();
}

int countLines(std::fstream & data){
  std::string line;
  if(data.is_open()){
    int count = 0;
    std::string line;
    while(std::getline(data, line)) 
      count++;
    return count;
  } 
  return 0;
}

int countCols(std::string rawLine){
  std::stringstream str (rawLine);
  int count = 0;
  std::string line;
  while(std::getline(str, line, ','))
    count++;
  return count++;
}

std::string getCol(std::string rawLine, const int INDEX){
  std::stringstream str (rawLine);
  std::string colData;
  int currentIndex = 0;
  while(std::getline(str, colData, ',')){
    if(INDEX==currentIndex) return colData;
    currentIndex++;
  }
  return "";
}

std::string * getContent(std::fstream & data){
  const int N = countLines(data)-1;
  std::string rawLine;
  data.clear();
  data.seekg(0, data.beg);
  std::getline(data, rawLine);
  const int M = countCols(rawLine);
  std::string * content = new std::string[M];
  if(data.is_open()){
    while(std::getline(data, rawLine)){
      for(int i = 0; i < M; i++){
        content[i] += getCol(rawLine, i) +"\n";
      }
    }
  }
  data.close();
  return content;
}

int main(){
  std::fstream data;
  try{
    data.open("marvel_wikia_data.csv", std::fstream::in);
  } catch(...){
    std::cerr << "Could not open file.\n";
  }
  std::string *content = getContent(data);
  bubbleSort(content[1], 16376);
  char toFind;
  std::cout << "What letter do you want to search? (A-Z): ";
  std::cin >> toFind;
  sequentialSearch(content[1], 16376, toFind);
  return 0;
}