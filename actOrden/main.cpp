#include <fstream>
#include <iostream>
#include <string>

int countLines(std::fstream & data){
  if(data.is_open()){
    int count;
    std::string line;
    while(std::getline(data, line)) 
      count++;
    return count;
  } 
  return 0;
}

std::string * readNames(std::string * data, const int N){
  std::string * names = new string [N];
  for(int i = 0; i < N; i++)
}

int main(){
  std::fstream data;
  std::string line;
  try{
    data.open("marvel-wikia-data.csv", std::fstream::in);
  } catch(...){
    std::cerr << "Could not open file.\n";
  }
  std::cout << countLines(data) << std::endl;
  data.close();
  return 0;
}