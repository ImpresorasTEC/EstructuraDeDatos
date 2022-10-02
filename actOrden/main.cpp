#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

/**
* @author: 
** Ernesto Miranda Solis A01656828
** Adrian Aguilar Sanchez A01651592
** Federico Castro Zenteno A01660986
*/

/**
 * @brief Hace un ordenamiento burbuja de complejidad O(n^2)
 * 
 * @tparam T el objeto pasado como referencia, se ausme que puede ser un string
 * @param names objeto con los nombres
 * @param n tamanio del arreglo
 */
template <class T>
void bubbleSort(T & names, int n) {
  T temp, * arr = new T [n]; // O(1)
  std::stringstream namesStream (names); // O(1)
  int i = 0; // O(1)
  while(std::getline(namesStream, temp)){ // O(n)
    arr[i++] = temp; // O(1)
  }
  for (int i=0; i<n; i++){ // O(n^2)
    for (int j=0; j<n-1; j++){ // O(n)
      if (arr[j] > arr[j+1]){ // O(1)
        temp = arr[j]; // O(1)
        arr[j] = arr[j+1]; // O(1)
        arr[j+1] = temp; // O(1)
      }
    }
  }
  names = ""; // O(1)
  for(int i = 0; i < n; i++){ // O(n)
    names += arr[i] + "\n"; // O(1)
  }
}

/**
 * @brief Hace la búsqueda secuencial y el resultado lo guarda en un documento llamado out.csv
 * 
 * @tparam T objeto que se asume que se comporta como string
 * @param names objeto con los nombres
 * @param n tamanio del arreglo
 * @param search caracter a buscar
 */
template <class T>
void sequentialSearch(T & names, int n, char search) {
  T temp, * arr = new T [n]; // O(1)
  std::stringstream namesStream (names); // O(1)
  int i = 0; // O(1)
  while(std::getline(namesStream, temp)){ // O(n)
    arr[i++] = temp; // O(1)
  }
  std::ofstream out("out.csv"); // O(1)
  for(int i=0; i <n; i++) { // O(n)
    temp = arr[i]; // O(1)
    if(temp[0] == search) { // O(1)
    out << arr[i] << "\n"; // O(1)
    }
  }
  out.close(); // O(1)
}

/**
 * @brief Cuenta las lineas del archivo
 * 
 * @param data referencia del stream del archivo
 * @return int el numero de lineas
 */
int countLines(std::fstream & data){
  if(data.is_open()){ // O(1)
    int count = 0; // O(1)
    std::string line; // O(1)
    while(std::getline(data, line)) // O(n)
      count++; // O(1)
    return count; // O(1)
  } 
  return 0; // O(1)
}

/**
 * @brief cuenta las columnas del archivo
 * 
 * @param rawLine string con cada fila
 * @return int el numero de columnas
 */
int countCols(std::string rawLine){
  std::stringstream str (rawLine);
  int count = 0;
  std::string line;
  while(std::getline(str, line, ','))
    count++;
  return count++;
}

/**
 * @brief regresa el dato de la columna
 * 
 * @param rawLine string con los valores de la línea 
 * @param INDEX indice buscado
 * @return std::string 
 */
std::string getCol(std::string rawLine, const int INDEX){
  std::stringstream str (rawLine); // O(1)
  std::string colData; // O(1)
  int currentIndex = 0; // O(1)
  while(std::getline(str, colData, ',')){ // O(n)
    if(INDEX==currentIndex) return colData; // O(1)
    currentIndex++; // O(1)
  }
  return ""; // O(1)
}

/**
 * @brief Regresa el contenido del archivo como un apuntador de strings
 * 
 * @param data referencia del stream del archivo
 * @return std::string* el apuntador con el contenido del archivo
 */
std::string * getContent(std::fstream & data){
  const int N = countLines(data)-1; // O(1)
  std::string rawLine; // O(1)
  data.clear(); // O(1)
  data.seekg(0, data.beg); // O(1)
  std::getline(data, rawLine); // O(1)
  const int M = countCols(rawLine); // O(1)
  std::string * content = new std::string[M]; // O(1)
  if(data.is_open()){ // O(1)
    while(std::getline(data, rawLine)){ // O(n)
      for(int i = 0; i < M; i++){ // O(m)
        content[i] += getCol(rawLine, i) +"\n"; // O(n) por la complejidad de la funcion
      }
    }
  }
  data.close(); // O(1)
  return content; // O(1)
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