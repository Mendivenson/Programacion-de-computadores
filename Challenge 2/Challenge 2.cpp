#include <iostream>
#include <map>
#include <ncurses.h> // La librería ncurses cambia el color del terminal en linux

using namespace std;

map<string, string> usuarios = {
  {"mbarraganz", "contrasena"}
};

long saldo = 15000000;
bool corriente = false;
bool sobregiro = false;
long tcredito = 0;
long max_sobregiro = 0;
long cupocredito = 0;

int main() {
  char usuario[100]; 
  char contrasena[100];
  bool usuarioValido = false;
  
  
  initscr();
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_RED);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  
  printw("\t\tBIENVENIDO A SU CAJERO\n\n");
  printw("Por favor, ingrese su usuario: ");
  scanw("%s", usuario);
  printw("Ingrese su contrasena: ");
  scanw("%s", contrasena);
  
  string usuario_str(usuario);
  string contrasena_str(contrasena);
  
  if (usuarios.find(usuario_str) != usuarios.end() && usuarios[usuario_str] == contrasena_str) {
    usuarioValido = true;
    int cuenta;
    printw("\nSeleccione el tipo de cuenta (ahorros o corriente):\n");
    printw("\t1. Cuenta de ahorros\n");
    printw("\t2. Cuenta corriente\n");
    scanw("%d", &cuenta);
    if (cuenta == 2) {
      corriente = true;
    } else {
      corriente = false;
    }
    
  } else {
    attron(COLOR_PAIR(1));
    printw("Usuario o contrasena incorrectos. Intente nuevamente.\n");
    printw("Presione cualquier tecla para salir...");
    getch(); 
    endwin(); 
    return 0;
  }
  
  int opcion = 0;
  
  printw("\t\tPor favor, ingrese la operacion que desea realizar: \n\n");
  printw("1. Consultar saldo\n");
  printw("2. Consignar\n");
  printw("3. Retirar\n");
  printw("4. Hacer sobregiro cuenta corriente\n");
  printw("5. Hacer un avance de tarjeta de credito\n");
  printw("6. Salir\n");
  scanw("%d", &opcion);
  
  switch (opcion) {
  case 1:
    printw("\nSu saldo es: $%ld\n", saldo);
    break;
  case 2:
    printw("\nDetermine el monto a consignar: ");
    long valor;
    scanw("%ld", &valor);
    attron(COLOR_PAIR(2));
    saldo = saldo + valor;
    printw("\nSu nuevo saldo es: $%ld\n", saldo);
    break;
  case 3:
    printw("\nDigite el monto que desea retirar: ");
    long valor_retirar;
    scanw("%ld", &valor_retirar);
    
    if (valor_retirar <= saldo && valor_retirar % 10000 == 0) {
      attron(COLOR_PAIR(2));
      printw("Su nuevo saldo es $%ld y su retiro sera dado en: \n", saldo - valor_retirar);
      int cantidad_100k = valor_retirar / 100000;
      int cantidad_50k = (valor_retirar % 100000) / 50000;
      int cantidad_20k = ((valor_retirar % 100000) % 50000) / 20000;
      int cantidad_10k = (((valor_retirar % 100000) % 50000) % 20000) / 10000;
      
      if (cantidad_100k > 0)
        printw("%d billetes de $100000 ", cantidad_100k);
      if (cantidad_50k > 0)
        printw("%d billetes de $50000 ", cantidad_50k);
      if (cantidad_20k > 0)
        printw("%d billetes de $20000 ", cantidad_20k);
      if (cantidad_10k > 0)
        printw("%d billetes de $10000 ", cantidad_10k);
    }
    if (valor_retirar % 10000 != 0) {
      attron(COLOR_PAIR(3));
      printw("El monto ingresado no es multiplo de $10000.\n");
    }
    
    if (saldo < valor_retirar) {
      attron(COLOR_PAIR(1));
      printw("Cuenta con saldo insuficiente para realizar esta operacion.\n");
    }
    break;
  case 4:
    if (corriente) {
      printw("\n Ingrese el monto del sobregiro a su cuenta corriente\n");
      long sobregiro;
      scanw("%ld", &sobregiro);
      max_sobregiro = 10000000; // El cupo de sobregiro que no puede ser excedido
      if (sobregiro <= max_sobregiro) {
        attron(COLOR_PAIR(2));
        saldo = saldo + sobregiro;
        printw("\nSu nuevo saldo es: $%ld\n", saldo);
      } else {
        attron(COLOR_PAIR(1));
        printw("Sobregiro excedido, no es posible efectuar la transaccion.\n");
      }
    } else {
      attron(COLOR_PAIR(3));
      printw("\nEsta operacion solo esta permitida para cuentas corrientes.\n");
    }
    break;
  case 5:
    printw("\nDigite el monto del avance con tarjeta de credito: ");
    long avance;
    scanw("%ld", &avance);
    cupocredito = 100000000; // El cupo de la tarjeta de crédito que no puede ser excedido
    if (avance <= cupocredito) {
      saldo = saldo + avance;
      attron(COLOR_PAIR(2));
      cupocredito = cupocredito - avance;
      printw("\nSu nuevo saldo es: $%ld\n", saldo);
      printw("\nSu nuevo cupo credito disponible es: $%ld\n", cupocredito);
    } else {
      attron(COLOR_PAIR(1));
      printw("\nCupo insuficiente en la tarjeta de credito.\n");
    }
    break;
  case 6:
    printw("\nGracias por utilizar nuestros servicios. Vuelva pronto!\n");
    break;
  default:
    printw("Ingrese por favor una opcion valida.\n");
  }
  
  printw("Presione cualquier tecla para salir...");
  getch(); 
  endwin();
  
  return 0;
}
