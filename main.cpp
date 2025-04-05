//REGISTRO DE NOTAS PARA ESTUDIANTES
/*
 PROGRAMA CREADO POR:
 RASHELL RAMIREZ
 JERELYN MARIN
 */
#include <iostream>

using namespace std;

//CONSTANTE, LOS DATOS SOLICITADOS TIENEN UN LIMITE
const int MAX_ESTUDIANTES = 10;
const int MAX_NOTAS = 5;

//INGRESO DE DATOS, GUARDAR DATOS EN ARRAYS
void ingresarNotas(double notas[][MAX_NOTAS], int numEstudiantes) {
 for (int i = 0; i < numEstudiantes; i++) {
  cout << "Ingrese las notas del estudiante " << i + 1 << ":" << endl;
  for (int j = 0; j < MAX_NOTAS; j++) {
   cout << "Nota " << j + 1 << ": ";
   cin >> notas[i][j];
  }
 }
}
//MODIFICACION/CONVERSION DE DATOS, recorrer arreglos
void calcularPromedios(double notas[][MAX_NOTAS], double promedios[], int numEstudiantes) {
 for (int i = 0; i < numEstudiantes; i++) {
  double suma = 0;
  for (int j = 0; j < MAX_NOTAS; j++) {
   suma += notas[i][j];
  }
  promedios[i] = suma / MAX_NOTAS;
 }
}
//acceder a posiciones específicas de un arreglo
void mostrarResultados(double notas[][MAX_NOTAS], double promedios[], int numEstudiantes) {
 for (int i = 0; i < numEstudiantes; i++) {
  cout << "Estudiante " << i + 1 << ":" << endl;
  for (int j = 0; j < MAX_NOTAS; j++) {
   cout << "Nota " << j + 1 << ": " << notas[i][j] << endl;
  }
  cout << "Promedio: " << promedios[i] << endl;
  cout << endl;
 }
}
//MUESTRA TODOS LOS RESULTADOS
int main() {
 int numEstudiantes;
 cout << "Ingrese el número de estudiantes (máximo " << MAX_ESTUDIANTES << "): ";
 cin >> numEstudiantes;

 if (numEstudiantes > MAX_ESTUDIANTES) {
  cout << "Número de estudiantes excede el máximo permitido." << endl;
  return 1;
 }

 double notas[MAX_ESTUDIANTES][MAX_NOTAS];
 double promedios[MAX_ESTUDIANTES];

 ingresarNotas(notas, numEstudiantes);
 calcularPromedios(notas, promedios, numEstudiantes);
 mostrarResultados(notas, promedios, numEstudiantes);

 return 0;
}