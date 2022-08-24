#include <fstream>
#include <iostream>
#include <string>

int main(){
  std::fstream data;
  std::string line;
  data.open("marvel-wikia-data.csv", std::fstream::in);
  std::getline(data, line, '-');
  std::cout << line << "\n";
  data.close();
  return 0;
}