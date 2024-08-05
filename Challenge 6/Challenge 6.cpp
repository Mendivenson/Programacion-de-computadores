#include <iostream>
#include <vector>
#include <algorithm>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cmath>

using namespace std;

//Función para mostrar el tablero en pantalla:
void Tablero(vector<string> estado = {" ", " ", " ", " ", " ", " ", " ", " ", " "}){
    cout << "\n";
    for (int i = 0; i <= 8; i++){
        cout << " | ";
        cout << estado[i];
        if ((i+1) % 3 == 0){
            cout << " |";
            cout << endl;
            if (i < 8){
                cout << " -------------";
            }
            cout << endl;
        }
    }
}

// Función para elegir el siguiente movimiento en función de la dificultad escogida:


// Función para definir si se ha ganado la partida:
bool Ganar(string simbolo = "O", vector<string> estado = {" ", "O", " ", " ", " ", " ", " ", " ", " "}){
    //auto indice = std::find(estado.begin(), estado.end(), simbolo);
    //cout << indice;
    return true;
}

//Función de menú:
void menu(){
    int opcion; vector<string> estado = {"1", "2","3", "4", "5", "6", "7", "8", "9"};
    cout << " \n =============== \t TRIQUI \t =============== \n" << endl;
    cout << "El juego cuenta con las siguientes opciones de dificultad:" << endl;
    cout << "\t 1. Ultra fácil." << endl; cout << "\t 2. Fácil" << endl;
    cout << "\t 3. Normal" << endl; cout << "\t 4. Imposible" << endl;
    cout << "Seleccione una de las 4 opciones o escriba 5 para salir ";
    cin >> opcion; cout << "\n\n";
    switch (opcion){
    case 5:
        cout << "\t\tQue tenga buen día\n\n"; 
        return;
    case 1:
    case 2:
    case 3:
    case 4:
        cout << "\033[2J\033[1;1H";
        cout << "\tHa seleccionado el nivel de dificultad ";
        cout << opcion;
        cout << "\n\n";  
        cout << "El tablero de triqui se imprimirá de la siguiente forma: \n";
        Tablero(estado);
        cout << "En cada turno debe escoger el número que se corresponda con la casilla que seleccionó.\n";
        cout << "Además el jugador siempre juega de primero con el símbolo O." << endl;
        break;
    default:
        cout << "\t La selección es inválida intente de nuevo\n";
        break;
    }
    menu();
}

int main(){
    menu();
    Ganar();
    return 0;
}