/**
 * @file examenDiagnostico.cpp
 * @author Ernesto Miranda Solis (A01656828)
 * @brief El programa encuentra un elemento terminator en un arreglo. Un elemento es un terminator si NO es más pequeño que sus vecinos. Para elementos de esquina, debemos considerar solo un vecino.
 * @version 0.1
 * @date 2022-08-08
 * 
 */

#include <iostream>

using namespace std;

/**
 * @brief La funcion regresa los indices de los terminators, si en el índice actual no hay un terminator, agrega un -1.
 * 
 * La funcion utiliza varios condicionales anidados junto con un ciclo for 
 * que se encarga de construir el arreglo de los terminators. 
 * 
 * @param arr el arreglo de numeros
 * @param N el tamaño del arreglo
 * @return int* apuntador con los índices de los terminators
 */
int * terminatorFinder(int * arr, const int N){
  if(N == 0) return new int {-1};
  int counter = 0, * terminators = new int[N];
  for(int i = 0; i < N; i++){
    if(i == 0){
      if(*arr > *(arr + 1)) {
        *terminators = i;
      }
      else{
        *terminators = -1;
      }
    }
    else if(i == N-1){
      if(*(arr + N - 1) > *(arr + N - 2)){
        *(terminators+counter)= N-1;
      } else{
        *(terminators+counter)= -1;
      }
    }
    else{
      if(arr[i-1] < arr[i] && arr[i+1] < arr[i]) {
        *(terminators+counter) = i;
      } else{
        *(terminators+counter) = -1;
      }
    }
    counter++;
  }
  return terminators;
}
/**
 * @brief Imprime las posiciones de los terminators
 * 
 * Utiliza simplemente un ciclo for y algunas condicionales para evaluar los distintos 
 * casos y posiciones de los terminators.
 * 
 * @param terminators 
 * @param N 
 */
void printPositions(int * terminators, const int N){
  if(N == 0) {
    cout << "Arreglo vacio!\n" << *terminators << endl;
    return;
  }
  int pos = 1, failed = 0;
  for(int i = 0; i < N; i++){
    if(*(terminators+i) != -1){
      cout << "Terminator " << pos << ": " << *(terminators + i) << endl;
      pos++;
    } else{
      failed++;
    }
  }
  if(failed == N) {
    cout << "No terminator: " << -1 << endl;
  }
}
/**
 * @brief namespace para los test cases.
 * 
 */
namespace testCases{
  /**
   * @brief Test case 1, el output de esta funcion debe ser 2
   * 
   */
  void caseOne() {
    int arr[] = {5, 10, 20, 15};
    int * terminators = terminatorFinder(arr, 4);
    printPositions(terminators, 4);
  }
  /**
   * @brief Test case 2, el output debe ser 1
   * 
   */
  void caseTwo(){
    int arr[] = {10, 20, 15, 2, 23, 90, 67};
    int * terminators = terminatorFinder(arr, 7);
    printPositions(terminators, 7);
  }
  /**
   * @brief Test case 3, el output debe ser -1
   * 
   */
  void caseThree(){
    int * ptr= new int[0];
    int * terminators = terminatorFinder(ptr, 0);
    printPositions(terminators, 0);
  }
  /**
   * @brief Test case 4, el output debe ser -1
   * 
   */
  void caseFour(){
    int arr[] = {1, 1, 1};
    int * terminators = terminatorFinder(arr, 3);
    printPositions(terminators, 3);
  }
  /**
   * @brief Test case 5, el output debe ser 0
   * 
   */
  void caseFive(){
    int arr[] = {7, 4, 3, 2};
    int * terminators = terminatorFinder(arr, 4);
    printPositions(terminators, 4);
  }
  /**
   * @brief Test case 6, el output debe ser 3
   * 
   */
  void caseSix(){
    int arr[] = {1, 2, 3, 5};
    int * terminators = terminatorFinder(arr, 4);
    printPositions(terminators, 4);
  }
  /**
   * @brief Ejecucion de los test cases
   * 
   * No utiliza try/catch para input no deseado, pero maneja errores prácticos de rango.
   * Con ayuda de un switch case puede navegar entre los distintos test cases.
   */
  void menu(){
    int option;
    do{
      cout << "-- Que test case vas a hacer? (ingresa un entero de 0-6) --\n" 
      << "0. Salir\n1. {5, 10, 20, 15}\n2. {10, 20, 15, 2, 23, 90, 67}\n"
      << "3. {}\n4. {1, 1, 1}\n5. {7, 4, 3, 2}\n6. {1, 2, 3, 5}\n>> ";
      cin >> option;
      switch(option){
        case 0:
          cout << "Gracias!\n";
          break;
        case 1:
          caseOne();
          break;
        case 2:
          caseTwo();
          break;
        case 3:
          caseThree();
          break;
        case 4:
          caseFour();
          break;
        case 5:
          caseFive();
          break;
        case 6:
          caseSix();
          break;
        default:
          cout << "- Input invalido\n";
          break;
      }
    } while(option != 0);

  }
}

int main(){
  testCases::menu();
}