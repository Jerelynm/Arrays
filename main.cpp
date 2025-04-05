#include <iostream>

using namespace std;

const int MAX_ESTUDIANTES = 10;
const int MAX_NOTAS = 5;

void ingresarNotas(double notas[][MAX_NOTAS], int numEstudiantes) {
 for (int i = 0; i < numEstudiantes; i++) {
  cout << "Ingrese las notas del estudiante " << i + 1 << ":" << endl;
  for (int j = 0; j < MAX_NOTAS; j++) {
   cout << "Nota " << j + 1 << ": ";
   cin >> notas[i][j];
  }
 }
}