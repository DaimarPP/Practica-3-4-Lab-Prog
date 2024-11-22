#include <iostream>
#include <cmath>
using namespace std;

int contador = 0;

int determinante(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

int verificarLineas(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int d1 = determinante(x1, y1, x2, y2, x3, y3);
    int d2 = determinante(x1, y1, x2, y2, x4, y4);
    int d3 = determinante(x3, y3, x4, y4, x1, y1);
    int d4 = determinante(x3, y3, x4, y4, x2, y2);

    if (d1 * d2 > 0 && d3 * d4 > 0) {
        return 0;
    }
    else if (d1 * d2 < 0 && d3 * d4 < 0) {
        return 1;
    }
    return -1;
}

int verificarLineasPerpendiculares(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    double m1 = (double)(y2 - y1) / (x2 - x1);
    double m2 = (double)(y4 - y3) / (x4 - x3);

    if (m1 * m2 == -1) {
        return 1;
    }

    if (m1 == m2) {
        return 0;
    }

    return -1;
}

double calcularAngulo(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, bool enGrados = false) {
    double m1 = (double)(y2 - y1) / (x2 - x1);
    double m2 = (double)(y4 - y3) / (x4 - x3);

    double angulo = atan(abs((m2 - m1) / (1 + m1 * m2)));

    if (enGrados) {
        return angulo * (180.0 / M_PI);
    }

    return angulo;
}

void realizarProceso() {
    cout << "Proceso realizado\n";
    contador++;
}

int obtenerNumeroDeLlamadas() {
    return contador;
}

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;

    cout << "Ingrese las coordenadas del primer punto de la primera linea (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Ingrese las coordenadas del segundo punto de la primera linea (x2 y2): ";
    cin >> x2 >> y2;

    cout << "Ingrese las coordenadas del primer punto de la segunda linea (x3 y3): ";
    cin >> x3 >> y3;
    cout << "Ingrese las coordenadas del segundo punto de la segunda linea (x4 y4): ";
    cin >> x4 >> y4;

    int resultado = verificarLineas(x1, y1, x2, y2, x3, y3, x4, y4);
    cout << "Resultado de verificacion (cruzan, paralelas, no cruzan): " << resultado << endl;

    int resultadoPerpendicular = verificarLineasPerpendiculares(x1, y1, x2, y2, x3, y3, x4, y4);
    cout << "Resultado de verificacion (perpendiculares, paralelas, se cruzan): " << resultadoPerpendicular << endl;

    double anguloRad = calcularAngulo(x1, y1, x2, y2, x3, y3, x4, y4);
    double anguloGrados = calcularAngulo(x1, y1, x2, y2, x3, y3, x4, y4, true);

    cout << "Angulo entre las lineas (en radianes): " << anguloRad << endl;
    cout << "Angulo entre las lineas (en grados): " << anguloGrados << endl;

    realizarProceso();
    realizarProceso();
    realizarProceso();

    cout << "La funcion 'realizarProceso' fue llamada " << obtenerNumeroDeLlamadas() << " veces.\n";

    return 0;
}