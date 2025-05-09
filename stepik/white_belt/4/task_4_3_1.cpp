
#include <iostream>
#include <cstdlib>

using namespace std;

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        value1 = 0;
        value2 = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор      

        if (denominator < 0){
            value1 *= -1;
            value2 *= -1;
        }
        if (numerator == 0){
            value1 = numerator;
            value2 = 1;
        }
        else{
            value1 = numerator;
            value2 = denominator;
            SimplifyFraction(value1, value2);
        }

    }

    int Numerator() const {
        // Реализуйте этот метод
        return value1;
    }

    int Denominator() const {
        // Реализуйте этот метод
        return value2;
    }

private:
    // Добавьте поля
    int value1;
    int value2;

    int GCD(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void SimplifyFraction(int& numerator, int& denominator) {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }
        // Определяем знак дроби
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }

        int common_divisor = GCD(numerator, denominator);
        numerator /= common_divisor;
        denominator /= common_divisor;
    }
    
};

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            cout << r.Numerator() << "/" << r.Denominator() << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}