#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;


int sudoku[9][9];
map<int, set<int>> filas, columnas, cuadrado;
bool nosolution;


// Convierte el carácter en un valor del 0-9 o -1
int converter(char x) {
  if(x<'0' or x>'9') return -1;
  return int(x)-48;
}


// Muestra el sudoku s por pantalla
void printsudoku(){
  for(int i = 0; i < 9; i++){
    if(i%3 == 0 and i!=0) cout << "------+-------+------" << endl;
    for(int j = 0; j < 8; j++){
      if(j%3 == 0 and j != 0) cout << "| ";
      cout << sudoku[i][j] << ' ';
    }
    cout << sudoku[i][8] << endl;
  }
  cout << endl;
}


// Muestra el mapa m por pantalla
void printmap(map<int, set<int>> m){
  for(auto n : m){
    cout << n.first << ' ';
    for(auto k : n.second){
      cout << k << ' ';
    }
    cout << endl;
  }
}


// Recibe las entradas y prepara los mapas y el sudoku
void creadora() {
  // Creamos todos los valores posibles para todas las filas, columnas y cuadrados
  for(int i = 0; i < 9; ++i){
    filas[i] = columnas[i] = cuadrado[i] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  }

  char x;
  int y;
  for(int f = 0; f < 9; ++f){
    for(int c = 0; c < 9; ++c){
      // Calcular el valor
      cin >> x;
      y = converter(x);
      bool restar = (y==-1);

      // Guardarlo en el sudoku
      sudoku[f][c] = y;

      // Quitarlo de valores de la fila disponibles
      auto it = filas[f].find(y);
      if(it != filas[f].end()) filas[f].erase(it);

      // Quitarlo de valores de la columna disponibles
      it = columnas[c].find(y);
      if(it != columnas[c].end()) columnas[c].erase(it);

      // Quitarlo de valores de la cuadrados disponibles
      int aux = (f/3)*3 + (c/3);
      it = cuadrado[aux].find(y);
      if(it != cuadrado[aux].end()) cuadrado[aux].erase(it);

      if(restar) c--;
    }
  }
}


set<int> intersection(set<int>::iterator fb, set<int>::iterator fe, set<int>::iterator cb, set<int>::iterator ce)
{
  set<int> aux;
  while(fb != fe and cb != ce){
    if(*fb < *cb) fb++;
    else if(*fb > *cb) cb++;
    else{
      aux.insert(*fb);
      fb++; cb++;
    }
  }
  return aux;
}


void calculadora(int f, int c) {
  // Final sudokus
  if(f>8){
    printsudoku();
    nosolution = false;
  }
  // Valor ya determinado
  else if(sudoku[f][c] != 0){
    if(c == 8) calculadora(f+1, 0);
    else calculadora(f, c+1);
  }
  // Calculamos los valores posibles
  else {
    int q = (f/3)*3 + c/3;
    set<int> aux = intersection(filas[f].begin(), filas[f].end(), columnas[c].begin(), columnas[c].end());
    aux = intersection(aux.begin(), aux.end(), cuadrado[q].begin(), cuadrado[q].end());

    // Existe algún valor posible
    if(aux.begin() != aux.end()){
      for(auto x : aux){
        sudoku[f][c] = x;
        filas[f].erase(x);
        columnas[c].erase(x);
        cuadrado[q].erase(x);

        // Final recursividad
        if(c == 8) calculadora(f+1, 0);
        else calculadora(f, c+1);

        sudoku[f][c] = 0;
        filas[f].insert(x);
        columnas[c].insert(x);
        cuadrado[q].insert(x);
        aux.erase(x);
      }
    }
  }
}


// Función principal
int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    nosolution = true;
    creadora();
    calculadora(0,0);
    if(nosolution) cout << "no solution" << endl;
    cout << "******************************" << endl;
  }
}
