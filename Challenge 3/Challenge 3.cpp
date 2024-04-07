#include <iostream>
#include <map>
#include <cmath>

using namespace std;

// ====================== USUARIOS Y CONTRASEÑAS ===============================
map<string, string> usuarios = {
  {"mbarraganz", "1234contraseña"},
  {"sergio", "cocacola"}
};


// ================ USUARIOS Y SALDOS CUENTAS CORRIENTE ========================
map<string, long> saldosCorriente = {
  {"mbarraganz", 10000000},
  {"sergio", 10000000}
};

// ================= USUARIOS Y SALDOS CUENTAS AHORROS =========================
map<string, long> saldosAhorros = {
  {"mbarraganz", 15000000},
  {"sergio", 15000000}
};

// ================ USUARIOS Y CUPOS CUENTAS DE CRÉDITO ========================
map<string, long> cuposCredito = {
  {"mbarraganz", 10000000}
};

// ======================== FUNCIONES SOLICITADAS ==============================

// ---- Función de seguridad (Verificar el usuario y la contraseña):

string seguridad(){
  string usuario; string contraseña; int intento = 1;
  cout << "Por favor, ingrese su usuario y contraseña para continuar:" << endl;
  while (intento < 6){
    cout << "\t - Usuario: "; cin >> usuario;
    cout << "\t - Contraseña: "; cin >> contraseña;
    if (usuarios.find(usuario) != usuarios.end() && usuarios[usuario] == contraseña){
      intento = 6;
    } else {
      cout << "\033[33m\nUsuario o contraseña incorrectos. Intente de nuevo" << endl;
      cout << "Quedan " << 5 - intento << " intentos restantes.\n\033[0m" << endl;
      ++ intento;
      usuario = "\033[31mUsuario o contraseña incorrectos\033[0m";
    }
  }
  return usuario;
}

// ---- Función selección tipo de cuenta:

int tipoCuenta(string usuario){
  int TipoCuenta;
  cout << "\n\033[33mEl usuario \033[31m" << usuario << " \033[33msólo puede acceder a las siguientes cuentas:\n" << endl;
  if (saldosAhorros.find(usuario) != saldosAhorros.end()){
    cout << "\t1. Cuenta de ahorros" << endl;
  }
  
  if (saldosCorriente.find(usuario) != saldosCorriente.end()){
    cout << "\t2. Cuenta corriente" << endl;
  }
  
  if (cuposCredito.find(usuario) != cuposCredito.end()){
    cout << "\t3. Tarjeta de crédito \033[0m" << endl;
  }
  
  cout << "\nIngrese la opción para la que desea realizar la acción: ";
  cin >> TipoCuenta;
  return TipoCuenta;
}


// ---- Función para consultar el saldo:
void consultar(int cuenta, string usuario){
  switch(cuenta){
  case 1:
    cout << " \033[34m\nEl saldo de la cuenta de ahorros de \033[31m" << usuario << " \033[34m es \033[31m" << saldosAhorros[usuario] << "\033[31m.\033[0m" << endl;
    break;
  case 2:
    cout << " \033[34m\nEl saldo de la cuenta de ahorros de \033[31m" << usuario << " \033[34m es \033[31m" << saldosCorriente[usuario] << "\033[31m.\033[0m" << endl;
    break;
  case 3:
    cout << " \033[34m\nEl cupo máximo disponible de crédito para \033[31m" << usuario << " \033[34m es \033[31m" << cuposCredito[usuario] << "\033[31m.\033[0m" << endl;
    break;
  default: {
    cout << "\033[31m Ha seleccionado una opción incorrecta.\033[0m" << endl;
    }
  }
};

// ---- Función para consignar:

void consignar(int cuenta, string usuario, long valor){
  switch (cuenta){
  case 1:
    saldosAhorros[usuario] += valor;
    cout << "\033[34m\nSe han consignado \033[31m" << valor << "\033[34m en la cuenta de ahorros del usuario \033[31m" << usuario << "\033[0m."<< endl;
    break;
  case 2:
    saldosCorriente[usuario] += valor;
    cout << "\033[34m\nSe han consignado \033[31m" << valor << "\033[34m en la cuenta corriente del usuario \033[31m" << usuario << "\033[0m."<< endl;
    break;
  case 3:
    cout << "\033[31m\nOpción inválida, no es posible consignar a un cupo de crédito.\033[0m" << endl;
    break;
  default:
    cout << "\033[31m\nOpción inválida.\033[0m" << endl;
    break;
  }
}

// ---- Función para contar los billetes:
void cuantos(long valor){
  int billetes;
  cout << "\033[90mEl dinero le será entregado en: " << endl;
  if ((valor / 100000) >= 1){
    billetes = floor(valor/100000);
    valor = valor - billetes * 100000;
    cout << "\t - " << billetes << " billetes de cien mil pesos."<< endl;
  }
  if ((valor / 50000) >= 1){
    billetes = floor(valor/50000);
    valor = valor - billetes * 50000;
    cout << "\t - " << billetes << " billetes de cincuenta mil pesos."<< endl;
  }
  if ((valor / 20000) >= 1){
    billetes = floor(valor/20000);
    valor = valor - billetes * 20000;
    cout << "\t - " << billetes << " billetes de veinte mil pesos."<< endl;
  }
  if ((valor / 10000) >= 1){
    billetes = floor(valor/10000);
    valor = valor - billetes * 10000;
    cout << "\t - " << billetes << " billetes de diez mil pesos."<< endl;
  }
  if ((valor / 5000) >= 1){
    billetes = floor(valor/5000);
    valor = valor - billetes * 5000;
    cout << "\t - " << billetes << " billetes de cinco mil pesos."<< endl;
  }
  if ((valor / 2000) >= 1){
    billetes = floor(valor/2000);
    valor = valor - billetes * 2000;
    cout << "\t - " << billetes << " billetes de dos mil pesos."<< endl;
  }
  if ((valor / 1000) >= 1){
    billetes = floor(valor/1000);
    valor = valor - billetes * 1000;
    cout << "\t - " << billetes << " billetes de mil pesos."<< endl;
  }
  cout << "El restante " << valor << " se le entregará en monedas.\033[0m" << endl;
}

// ---- Función para retirar:

void retirar(int cuenta, string usuario, long valor){
  long ValorActual;
  switch(cuenta){
  case 1:
    ValorActual = saldosAhorros[usuario];
    if (valor <= ValorActual && valor > 0){
      saldosAhorros[usuario] = saldosAhorros[usuario] - valor;
      cout << "\033[34m\nLa transacción se ha realizado\033[0m" << endl;
      cuantos(valor);
    } 
    else { 
      cout << "\033[31m\nOpción inválida. No hay esa cantidad de dinero en la cuenta\033[0m" << endl;
      }
   break;
  case 2:
    ValorActual = saldosCorriente[usuario];
    if (valor <= ValorActual && valor > 0){
      cout << "\033[34m\nLa transacción se ha realizado\033[0m" << endl;
      cuantos(valor);
      saldosCorriente[usuario] = saldosCorriente[usuario] - valor;
    } else { cout << "\033[31m\nOpción inválida. No hay esa cantidad de dinero en la cuenta\033[0m" << endl;}
    break;
  case 3:
    ValorActual = cuposCredito[usuario];
    if (valor <= ValorActual && valor > 0){
      cout << "\n\033[31m\n Cuidado. Está a punto de realizar un préstamo\033[0m\n" << endl;
      string word;
      cout << "Si está seguro que desea continuar con la transacción escriba Y, de lo contrario se cancelará la transacción. ";
      cin >> word;
      if (word == "Y" || word == "YES" || word == "yes" || word == "Yes"){
        cout << "\033[34m\nEl crédito se ha realizado\033[0m" << endl;
        cuposCredito[usuario] = cuposCredito[usuario] - valor;
        cuantos(valor);
      } else {
        cout << "\033[34m\nLa transacción ha sido cancelada\033[0m" << endl;
      } 
    } else { cout << "\033[31m\nOpción inválida. El usuario no cuenta con el suficiente cupo de crédito\033[0m" << endl;}
   break; 
  }
}


// ---- Función Menú principal (Recursión)

void menu(string usuario, int Cuenta){

  int Accion; long valor;
  if (Cuenta == 0){
    Cuenta = tipoCuenta(usuario);
  }
  
  // Elección de la acción a realizar:
  cout << "\n\033[33mSeleccione la acción que desea realizar: " << endl;
  cout << "\n\t 1. Consultar el saldo o el cupo de la cuenta." << endl;
  cout << "\t 2. Consignar a la cuenta." << endl;
  cout << "\t 3. Retirar de la cuenta." << endl;
  cout << "\t 4. Volver al menú de selección de tipo de cuenta." << endl;
  cout << "\t \033[31m5. Salir. \033[0m\n" << endl;
  cout << "Ingrese la acción que desea realizar: ";
  cin >> Accion;
  
  
  switch(Accion){
  case 1:
    consultar(Cuenta, usuario);
    break;
  case 2:
    cout << "\nDigite el valor que desea consignar: ";
    cin >> valor;
    consignar(Cuenta, usuario, valor);
    break;
  case 3:
    cout << "Digite el valor que desea retirar: ";
    cin >> valor;
    retirar(Cuenta, usuario, valor);
    break;
  case 4:
    Cuenta = 0;
    std::cout << "\033[2J\033[1;1H";
    break;
  case 5:
    cout << "\033[32m\n ========== Gracias por preferirnos, qué tenga buen día =========== \033[0m\n" << endl; 
    return;
    break;
  default:
    cout << "\033[31m\n Opción inválida.\033[0m" << endl;
    break;
  }
  menu(usuario, Cuenta);
}


int main() {
  
  std::cout << "\033[2J\033[1;1H";
  cout << "\033[32m\n\n================ \t BIENVENIDO A ESTE, SU BANCO\t ================\033[0m\n" << endl;
  string usuario = seguridad(); // Usuario y contraseña
  std::cout << "\033[2J\033[1;1H";
  
  if (usuario == "\033[31mUsuario o contraseña incorrectos\033[0m"){
    cout << usuario << endl;
    return 0;
  } else {
    cout << "\n================ \t MENÚ PRINCIPAL\t ================\n" << endl;
    menu(usuario, 0);
  }  
  return 0;
}
