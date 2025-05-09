
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

Rational operator+(const Rational& lhs, const Rational& rhs){
    /*
    2/3 + 1/2 = 4/6 + 3/6 = 7/6
    2/3 + 1/3 = 6/9 + 3/9 = 9/9 = 1
    */
    int num = (lhs.Numerator() * rhs.Denominator()) + (rhs.Numerator() * lhs.Denominator());
    int denom = lhs.Denominator() * rhs.Denominator();

    return Rational(num, denom);
}

Rational operator-(const Rational& lhs, const Rational& rhs){
    int num = (lhs.Numerator() * rhs.Denominator()) - (rhs.Numerator() * lhs.Denominator());
    int denom = lhs.Denominator() * rhs.Denominator();

    return Rational(num, denom);
}

Rational operator*(const Rational& lhs, const Rational& rhs){
    int num = lhs.Numerator() * rhs.Numerator();
    int denom = lhs.Denominator() * rhs.Denominator();

    return Rational(num, denom);
}

Rational operator/(const Rational& lhs, const Rational& rhs){
    int num = lhs.Numerator() * rhs.Denominator();
    int denom = lhs.Denominator() * rhs.Numerator();

    return Rational(num, denom);
}

bool operator==(const Rational& lhs, const Rational& rhs){
    if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()){
        return true;
    }
    else return false;
}



int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}