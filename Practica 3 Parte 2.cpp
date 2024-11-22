#include <iostream>
#include <cmath>
using namespace std;

struct Punto {
    int x, y;
};

double calcularDistancia(Punto p1, Punto p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

bool estaDentroDelCuadrante(Punto p, int xMin, int xMax, int yMin, int yMax) {
    return p.x >= xMin && p.x <= xMax && p.y >= yMin && p.y <= yMax;
}

double distanciaMaxima(Punto puntos[], int n, int xMin, int xMax, int yMin, int yMax) {
    double maxDistancia = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (estaDentroDelCuadrante(puntos[i], xMin, xMax, yMin, yMax) &&
                estaDentroDelCuadrante(puntos[j], xMin, xMax, yMin, yMax)) {
                double distancia = calcularDistancia(puntos[i], puntos[j]);
                if (distancia > maxDistancia) {
                    maxDistancia = distancia;
                }
            }
        }
    }
    return maxDistancia;
}

void imprimirDistancias(Punto puntos[], int n, int xMin, int xMax, int yMin, int yMax, int indice) {
    cout << "Distancias desde el punto (" << puntos[indice].x << ", " << puntos[indice].y << "):\n";
    for (int i = 0; i < n; i++) {
        if (i != indice && estaDentroDelCuadrante(puntos[i], xMin, xMax, yMin, yMax)) {
            double distancia = calcularDistancia(puntos[indice], puntos[i]);
            cout << "A punto (" << puntos[i].x << ", " << puntos[i].y << ") = " << distancia << "\n";
        }
    }
}

int main() {
    const int MAX_PUNTOS = 100;
    Punto puntos[MAX_PUNTOS];
    int n;

    cout << "Ingrese el numero de puntos: ";
    cin >> n;

    while (n <= 0 || n > MAX_PUNTOS) {
        cout << "Numero de puntos no valido. Ingrese un numero entre 1 y " << MAX_PUNTOS << ": ";
        cin >> n;
    }

    for (int i = 0; i < n; i++) {
        cout << "Ingrese las coordenadas del punto " << i + 1 << " (en formato x y, separados por espacio): ";
        while (!(cin >> puntos[i].x >> puntos[i].y)) {
            cout << "Entrada no valida. Por favor ingrese dos numeros (x y): ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    int xMin, xMax, yMin, yMax;
    cout << "Ingrese los limites del cuadrante (xMin, xMax, yMin, yMax): ";
    cin >> xMin >> xMax >> yMin >> yMax;

    double maxDistancia = distanciaMaxima(puntos, n, xMin, xMax, yMin, yMax);
    cout << "La distancia maxima entre dos puntos dentro del cuadrante es: " << maxDistancia << "\n";

    int indicePunto;
    cout << "Ingrese el indice (0 a " << n - 1 << ") del punto para calcular distancias a otros puntos: ";
    cin >> indicePunto;

    if (indicePunto >= 0 && indicePunto < n) {
        imprimirDistancias(puntos, n, xMin, xMax, yMin, yMax, indicePunto);
    } else {
        cout << "Indice de punto no valido.\n";
    }

    return 0;
}