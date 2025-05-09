
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <stdexcept>

using namespace std;

class Rational {
public:
    Rational() {
        value1 = 0;
        value2 = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator == 0){
            throw invalid_argument("Invalid argument");
        }
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
        return value1;
    }

    int Denominator() const {
        return value2;
    }

private:
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
            throw invalid_argument("Invalid argument");
        }
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
    if (rhs.Numerator() == 0){
        throw domain_error("Division by zero");
    }
    int num = lhs.Numerator() * rhs.Denominator();
    int denom = lhs.Denominator() * rhs.Numerator();

    return Rational(num, denom);
}

bool operator<(const Rational& lhs, const Rational& rhs){
   if ((lhs.Numerator() * rhs.Denominator()) < (rhs.Numerator() * lhs.Denominator())){
    return true;
   }
   else return false;
}

bool operator==(const Rational& lhs, const Rational& rhs){
    if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()){
        return true;
    }
    else return false;
}

bool operator!=(const Rational& lhs, const Rational& rhs){
    if (lhs.Numerator() != rhs.Numerator() && lhs.Denominator() != rhs.Denominator()){
        return true;
    }
    else return false;
}

ostream& operator<<(ostream& stream, const Rational& r){
    stream << r.Numerator();
    stream << "/";
    stream << r.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& r){
    int a = r.Numerator();
    int b = r.Denominator();
    stream >> a;
    stream.ignore(1);
    stream >> b;
    r = Rational(a, b);
    return stream;
}

int main() {
    Rational r1, r2, r3;
    string operation;
    try
    {
        cin >> r1;
        cin >> operation;
        cin >> r2;

        // cout << r1.Numerator() << "/" << r1.Denominator() <<
        // operation << r2.Numerator() << "/" << r2.Denominator() << endl;
    
        if (operation == "+"){
            r3 = r1 + r2;
        }
        else if (operation == "-"){
            r3 = r1 - r2;
        }
        else if (operation == "*"){
            r3 = r1 * r2;
        }
        else if (operation == "/"){
            r3 = r1 / r2;
        }
    
        cout << r3 << endl;
    }
    catch(const exception& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}