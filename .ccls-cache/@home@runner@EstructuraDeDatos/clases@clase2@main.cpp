#include <iostream>
using namespace std;

void salta(int n){
  for(int i = 0; i < n; i++){
    cout << "Salta" << endl;
  }
}

void saltaRecursivo(int n){
  if(n > 0) {
    cout << "Salta" << endl;
    saltaRecursivo(n-1);
  }
}

int factorial(unsigned int n){
  int x = 1;
  do{
    x *= n;
    n--;
  } while(n>1);
  return x;
}

int factorialRecursivo(unsigned int n){
  if(n == 0) return 1;
  return n * factorialRecursivo(n-1);
}

// Challenge John Wick

/*
@authors: 
  - Ernesto Miranda Solis A01656828
  - Adrian Aguilar Sanchez A01651592
*/
/*
Crea una función recursiva que obtenga la suma de los números naturales desde 1 hasta N. Se debe pasar como parámetro el número N (50 puntos)
*/
int sumaN(int n) {
  if(n > 0){
    return n+sumaN(n-1);
  }
  return 0;
}

/*
Crea una función recursiva que imprima los dígitos desde 1 hasta N. Se debe pasar como parámetro el número N (25 puntos)
*/

void ejercicioDos(int n){
  if(n>1) 
    ejercicioDos(n-1);
  cout << n << endl;
}

/*
Crea una función recursiva que imprima los dígitos desde N hasta 1. Se debe pasar como parámetro el número N (25 puntos)
*/
void ejercicioTres(int n){
  if(n > 0){
    cout << n << endl;
    ejercicioTres(n-1);
  }
}

/*
Crear una función recursiva que obtenga el resultado de elevar un número a otro. Ambos números se deben pasar como parámetros(75 puntos)
*/

int ejercicioCuatro(const int num, int pow){
  if(pow == 0)  return 1;
  return num * ejercicioCuatro(num, pow - 1);
}

int main(){
  /*
  salta(3);
  cout << endl;
  saltaRecursivo(3);

  cout << factorial(5) << endl;
  cout << factorialRecursivo(5) << endl;
  */

  cout << "Ejercicio 1\n" << sumaN(8) << endl;
  cout << "\nEjercicio 2 \n";
  ejercicioDos(5);
  cout << "\nEjercicio 3 \n";
  ejercicioTres(5);
  cout << "\nEjercicio 4 \n";
  cout << ejercicioCuatro(2, 5) << endl;
  return 0;
}