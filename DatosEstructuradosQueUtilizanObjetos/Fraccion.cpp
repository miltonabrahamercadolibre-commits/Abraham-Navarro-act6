#include "Fraccion.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

Fraccion::Fraccion() : num(1), den(2) {}

Fraccion::Fraccion(int n, int d) : num(n), den(d) {
    if (den == 0) den = 1;
    simplificar();
}

int Fraccion::getNum() const { return num; }
int Fraccion::getDen() const { return den; }

void Fraccion::setNum(int n) {
    num = n;
    simplificar();
}

void Fraccion::setDen(int d) {
    if (d == 0) d = 1;
    den = d;
    simplificar();
}

double Fraccion::calc_valor_real() const {
    return static_cast<double>(num) / den;
}

void Fraccion::sumar(const Fraccion& f) {
    num = num * f.den + den * f.num;
    den = den * f.den;
    simplificar();
}

int Fraccion::mcd(int a, int b) {
    return (b == 0) ? a : mcd(b, a % b);
}

void Fraccion::simplificar() {
    if (num == 0) {
        den = 1;
        return;
    }
    int gcd = mcd(std::abs(num), std::abs(den));
    num /= gcd;
    den /= gcd;
    if (den < 0) {
        num = -num;
        den = -den;
    }
}

std::string Fraccion::to_string() const {
    std::ostringstream oss;
    oss << num << "/" << den << " (" << std::fixed << std::setprecision(3) << calc_valor_real() << ")";
    return oss.str();
}