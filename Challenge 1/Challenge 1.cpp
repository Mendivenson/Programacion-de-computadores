//Challenge 1

// Punto 1

#include <iostream>
using namespace std;

int main() {
    double x, y;

    cout << "Ingrese el valor de la coordenada x: ";
    cin >> x;
    cout << "Ingrese el valor de la coordenada y: ";
    cin >> y;

    if (x > 0 && y > 0)
        cout << "El punto se encuentra en el primer cuadrante" << endl;
    else if (x < 0 && y > 0)
        cout << "El punto se encuentra en el segundo cuadrante" << endl;
    else if (x < 0 && y < 0)
        cout << "El punto se encuentra en el tercer cuadrante" << endl;
    else if (x > 0 && y < 0)
        cout << "El punto se encuentra en el cuarto cuadrante" << endl;
    else
        cout << "El punto se encuentra sobre alguno de los ejes del plano" << endl;

    if (y > x)
        cout << "El punto se encuentra por encima de y=x" << endl;
    else if (y < x)
        cout << "El punto se encuentra por debajo de y=x" << endl;
    else
        cout << "El punto hace parte de la recta y=x" << endl;

    return 0;
}


// Punto 2

#include <iostream>
using namespace std;

int segundo() {
    double x, y;

    cout << "Ingrese el valor de la coordenada x: ";
    cin >> x;
    cout << "Ingrese el valor de la coordenada y: ";
    cin >> y;

    if (x > 0 && y > 0)
        cout << "Primer cuadrante" << endl;
    else if (x < 0 && y > 0)
        cout << "Segundo cuadrante" << endl;
    else if (x < 0 && y < 0)
        cout << "Tercer cuadrante" << endl;
    else if (x > 0 && y < 0)
        cout << "Cuarto cuadrante" << endl;
    else
        cout << "El punto se encuentra sobre alguno de los ejes del plano" << endl;

    if (y > -x)
        cout << "El punto se encuentra por encima de y=-x" << endl;
    else if (y < -x)
        cout << "El punto se encuentra por debajo de y=-x" << endl;
    else
        cout << "El punto se encuentra en la recta y=-x" << endl;

    return 0;
}


//Punto 3

#include <iostream>
#include <cmath>
using namespace std;

int tercero() {
    double x, y, r;

    cout << "Ingrese el valor de la coordenada x: ";
    cin >> x;
    cout << "Ingrese el valor de la coordenada y: ";
    cin >> y;
    cout << "Ingrese el radio de la circunferencia";
    cin >> r;

    double distOrigen = sqrt(x*x + y*y);

    if (x > 0 && y > 0)
        cout << "El punto se encuentra en el primer cuadrante" << endl;
    else if (x < 0 && y > 0)
        cout << "El punto se encuentra en el segundo cuadrante" << endl;
    else if (x < 0 && y < 0)
        cout << "El punto se encuentra en el tercer cuadrante" << endl;
    else if (x > 0 && y < 0)
        cout << "El punto se encuentra en el cuarto cuadrante" << endl;
    else
        cout << "Origen" << endl;

    if (distOrigen > r)
        cout << "Fuera del circulo" << endl;
    else if (distOrigen < r)
        cout << "Dentro del circulo" << endl;
    else
        cout << "En la circunferencia del circulo" << endl;

    return 0;
}

//Punto 4

#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double x, y, r;
    cout << "Ingrese el valor de la coordenada x: ";cin >> x;
    cout << "Ingrese el valor de la coordenada y: ";cin >> y;
    if (x > 0 && y > 0)
        cout << "El punto se encuentra en el primer cuadrante" << endl;
    else if (x < 0 && y > 0)
        cout << "El punto se encuentra en el segundo cuadrante" << endl;
    else if (x < 0 && y < 0)
        cout << "El punto se encuentra en el tercer cuadrante" << endl;
    else if (x > 0 && y < 0)
        cout << "El punto se encuentra en el cuarto cuadrante" << endl;
    else
        cout << "El punto se encuentra sobre alguno de los ejes del plano" << endl;
    if (y > -x)
        cout << "El punto se encuentra por encima de y=-x" << endl;
    else if (y < -x)
        cout << "El punto se encuentra por debajo de y=-x" << endl;
    else
        cout << "En y=-x" << endl;
    cout << "Ingrese el radio de la circunferencia ";
    cin >> r;
    double distOrigen = sqrt(x*x + y*y);
    if (distOrigen > r)
        cout << "El punto se encuentra fuera del circulo" << endl;
    else if (distOrigen < r)
        cout << "El punto se encuentra dentro del circulo" << endl;
    else
        cout << "El punto se encuentra dentro de la circunferencia del circulo" << endl;

    return 0;
}
