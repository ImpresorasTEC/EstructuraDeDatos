#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

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

void setLines(std::string * row, std::string rawLine){
  std::stringstream str (rawLine);
  std::string line;
  int i = 0;
  while(std::getline(str, line, ',')){
    row[i] = line;
    i++;
  }
}

std::string ** getContent(std::fstream & data){
  const int N = countLines(data)-1;
  std::string rawLine, ** content = new std::string * [N], * row;
  data.clear();
  data.seekg(0, data.beg);
  std::getline(data,rawLine);
  const int M = countCols(rawLine);
  int i = 0;
  if(data.is_open()){
    while(std::getline(data, rawLine)){
      row = new std::string [M];
      setLines(row, rawLine);
      content[i] = row;
      i++;
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
  std::string ** content = getContent(data);
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 13; j++){
      std::cout << content[i][j] << " ";
    }
    std::cout << "\n";
  }
  return 0;
}