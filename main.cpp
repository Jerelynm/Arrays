// REGISTRO DE NOTAS PARA ESTUDIANTES
/*
 PROGRAMA CREADO POR:
 RASHELL RAMIREZ
 JERELYN MARIN
*/

#include <iostream>
#include <fstream>

using namespace std;

//CONSTANTE, LOS DATOS SOLICITADOS TIENEN UN LIMITE
const int MAX_ESTUDIANTES = 10;
const int MAX_NOTAS = 5;
const int MAX_LONGITUD = 50;

//INGRESO DE DATOS, GUARDAR DATOS EN ARRAYS
void ingresarDatosEstudiantes(string nombres[], string grados[], double notas[][MAX_NOTAS], int numEstudiantes) {
    for (int i = 0; i < numEstudiantes; i++) {
        cout << "\nEstudiante " << i + 1 << ":" << endl;
        cin.ignore();

        cout << "  Nombre: ";
        getline(cin, nombres[i]);

        cout << "  Grado: ";
        getline(cin, grados[i]);

        cout << "  Ingrese las notas (0 a 100):" << endl;
        for (int j = 0; j < MAX_NOTAS; j++) {
            do {
                cout << "    Nota " << j + 1 << ": ";
                cin >> notas[i][j];
                if (notas[i][j] < 0 || notas[i][j] > 100) {
                    cout << "Nota invalida. Debe estar entre 0 y 100." << endl;
                }
            } while (notas[i][j] < 0 || notas[i][j] > 100);
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
void mostrarYGuardarResultados(string nombres[], string grados[], double notas[][MAX_NOTAS], double promedios[], int numEstudiantes) {
    ofstream archivo("resultados_estudiantes.txt");

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para guardar los resultados." << endl;
        return;
    }

    for (int i = 0; i < numEstudiantes; i++) {
        cout << "\nEstudiante " << i + 1 << ":" << endl;
        cout << "  Nombre: " << nombres[i] << endl;
        cout << "  Grado: " << grados[i] << endl;

        archivo << "Estudiante " << i + 1 << ":\n";
        archivo << "  Nombre: " << nombres[i] << endl;
        archivo << "  Grado: " << grados[i] << endl;

        for (int j = 0; j < MAX_NOTAS; j++) {
            cout << "    Nota " << j + 1 << ": " << notas[i][j] << endl;
            archivo << "    Nota " << j + 1 << ": " << notas[i][j] << endl;
        }

        cout << "  Promedio: " << promedios[i] << endl;
        archivo << "  Promedio: " << promedios[i] << "\n\n";
    }

    archivo.close();
    cout << "\nResultados guardados en 'resultados_estudiantes.txt'." << endl;
}
//MUESTRA TODOS LOS RESULTADOS
int main() {
    int numEstudiantes;

    cout << "Ingrese el numero de estudiantes (maximo " << MAX_ESTUDIANTES << "): ";
    cin >> numEstudiantes;

    if (numEstudiantes > MAX_ESTUDIANTES || numEstudiantes <= 0) {
        cout << "Numero de estudiantes invalido." << endl;
        return 1;
    }

    string nombres[MAX_ESTUDIANTES];
    string grados[MAX_ESTUDIANTES];
    double notas[MAX_ESTUDIANTES][MAX_NOTAS];
    double promedios[MAX_ESTUDIANTES];

    ingresarDatosEstudiantes(nombres, grados, notas, numEstudiantes);
    calcularPromedios(notas, promedios, numEstudiantes);
    mostrarYGuardarResultados(nombres, grados, notas, promedios, numEstudiantes);

    return 0;
}