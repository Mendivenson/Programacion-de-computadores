#include <iostream>
#include <vector>
#include <algorithm>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cmath>

using namespace std;

// FUNCIÓN PARA IMPRIMIR EL TABLERO COMPLETO:
void Tablero(string tipo = "Completo"){
  int ancho; string caracter;
  cout << "\nDigite el ancho deseado de su tablero (o 0 para que ocupe el ancho completo de la ventana):  ";
  cin >> ancho;
  cout << '\n';
  
  if (ancho == 0){
    // ancho = system("exit 'tput cols'");
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);        // Obtener las medidas de la ventana actual
    ancho = floor(size.ws_col / 2);                 // Los carácteres que usamos ocupan el espacio de dos carácteres
  }
  
  vector<string> opciones = {"\u2B1C", "\u2B1B"};   // Cuadro blanco, cuadro negro
    
  // Este ciclo se encarga de las filas del tablero
  for (int i = 1; i <= ancho; i++){
    // Este se encarga de las columnas del tablero
    for (int j = 1; j <= ancho; j++){
      // Definimos al carácter como el primer elemento del vector opciones
      caracter = opciones[0];
      
      // Condición tipo de tablero
      if (i > j && tipo == "Superior"){
        caracter = "  ";
      }
      if (i < j && tipo == "Inferior"){
        caracter = "  ";
      }
      cout << caracter;       // Se dibuja el carácter actual
      reverse(opciones.begin(),opciones.end()); // Se invierte el orden del vector para girar el siguiente color
    }
    cout << endl; // Se dibuja la siguiente fila del tablero
    if ((ancho % 2) == 0){    // Por invertir el vector, para números pares de filas se genera un problema que se arregla
      reverse(opciones.begin(),opciones.end()); 
    }
  }
}

// FUNCIÓN CÍRCULO


// FUNCIÓN PARA IMPRIMIR UN MENÚ
void menu(){
  int opcion; string tipo;
  cout << " \n =============== \t GENERADOR DE TABLEROS DE AJEDREZ \t =============== \n" << endl;
  cout << "Seleccione una de las siguientes opciones:" << endl;
  cout << "\t 1. Tablero completo." << endl;
  cout << "\t 2. Tablero triangular superior." << endl;
  cout << "\t 3. Tablero triangular inferior." << endl;
  cout << "\t 4. Círculo de radio dado." << endl;
  cout << "\t 5. Salir." << endl << "\n-----> \t ";
  cin >> opcion;
  
  switch(opcion){
  case 1:
    Tablero("Completo");
    break;
  case 2:
    Tablero("Superior");
    break;
  case 3:
    Tablero("Inferior");
    break;
  case 4:
    // Círculo();
    break;
  case 5:
    cout << "\n\n\033[32m \t Que tenga buen día \t \033[0m \n\n\n";
    return;
  default: 
    cout << "\n\n\033[31m \t Opción inválida. Intente de nuevo \t \033[0m \n\n";
  break;
  }
  menu();
}


int main(){
  menu();
  return 0;
}
