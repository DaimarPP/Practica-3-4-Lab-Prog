#include <iostream>
using namespace std;

int determinarCuadrante(int x, int y) {
    if (x > 0 && y > 0) return 1;
    if (x < 0 && y > 0) return 2;
    if (x < 0 && y < 0) return 3;
    if (x > 0 && y < 0) return 4;
    return 0;
}

void ecuacionRecta(int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        cout << "Recta vertical: x = " << x1 << "\n";
    } else if (y1 == y2) {
        cout << "Recta horizontal: y = " << y1 << "\n";
    } else {
        double pendiente = static_cast<double>(y2 - y1) / (x2 - x1);
        double intercepto = y1 - pendiente * x1;
        cout << "Ecuacion: y = " << pendiente << "x + " << intercepto << "\n";
    }
}

bool enMismaLinea(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1);
}

int main() {
    const int MAX_PUNTOS = 100;
    int puntos[MAX_PUNTOS][2];
    int n;

    cout << "Ingrese el numero de puntos: ";
    cin >> n;

    while (n <= 0 || n > MAX_PUNTOS) {
        cout << "Número de puntos no válido. Ingrese un número entre 1 y " << MAX_PUNTOS << ": ";
        cin >> n;
    }

    for (int i = 0; i < n; i++) {
        cout << "Ingrese las coordenadas del punto " << i + 1 << " (en formato x y, separados por espacio): ";
        while (!(cin >> puntos[i][0] >> puntos[i][1])) {
            cout << "Entrada no válida. Por favor ingrese dos números (x y): ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    cout << "\nCuadrantes:\n";
    for (int i = 0; i < n; i++) {
        int cuadrante = determinarCuadrante(puntos[i][0], puntos[i][1]);
        cout << "Punto (" << puntos[i][0] << ", " << puntos[i][1] << ") -> Cuadrante " << cuadrante << "\n";
    }

    cout << "\nPuntos en la misma línea:\n";
    bool hayLineas = false;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (enMismaLinea(puntos[i][0], puntos[i][1], puntos[j][0], puntos[j][1], puntos[k][0], puntos[k][1])) {
                    hayLineas = true;
                    cout << "Puntos (" << puntos[i][0] << ", " << puntos[i][1] << "), ("
                         << puntos[j][0] << ", " << puntos[j][1] << "), ("
                         << puntos[k][0] << ", " << puntos[k][1] << ") están en la misma línea.\n";
                    ecuacionRecta(puntos[i][0], puntos[i][1], puntos[j][0], puntos[j][1]);
                }
            }
        }
    }

    if (!hayLineas) {
        cout << "No hay puntos alineados en el conjunto ingresado.\n";
    }

    return 0;
}
