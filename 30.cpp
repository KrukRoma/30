#include <iostream>
using namespace std;

class Fraction 
{
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) const 
    {
        while (b != 0) 
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void simplify() 
    {
        int gcdValue = gcd(numerator, denominator);
        numerator /= gcdValue;
        denominator /= gcdValue;
        if (denominator < 0) 
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num, int denom) : numerator(num), denominator(denom) 
    {
        if (denom == 0) 
        {
            throw invalid_argument("Denominator cannot be zero");
        }
        simplify();
    }

    Fraction operator+(const Fraction& other) const 
    {
        int commonDenom = denominator * other.denominator;
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        return Fraction(newNumerator, commonDenom);
    }

    Fraction operator-(const Fraction& other) const 
    {
        int commonDenom = denominator * other.denominator;
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        return Fraction(newNumerator, commonDenom);
    }

    Fraction operator*(const Fraction& other) const 
    {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator/(const Fraction& other) const 
    {
        if (other.numerator == 0) 
        {
            throw invalid_argument("Cannot divide by zero");
        }
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        return Fraction(newNumerator, newDenominator);
    }

    bool operator==(const Fraction& other) const 
    {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction& other) const 
    {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const 
    {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator<=(const Fraction& other) const 
    {
        return *this < other || *this == other;
    }

    bool operator>(const Fraction& other) const 
    {
        return !(*this <= other);
    }

    bool operator>=(const Fraction& other) const 
    {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& os, const Fraction& frac) 
    {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }

    int getNumerator() const 
    {
        return numerator;
    }

    int getDenominator() const 
    {
        return denominator;
    }
};

int main() 
{
    try 
    {
        Fraction f1(3, 4);
        Fraction f2(5, 6);

        Fraction sum = f1 + f2;
        Fraction diff = f1 - f2;
        Fraction product = f1 * f2;
        Fraction quotient = f1 / f2;

        cout << "f1: " << f1 << endl;
        cout << "f2: " << f2 << endl;
        cout << "Sum: " << sum << endl;
        cout << "Difference: " << diff << endl;
        cout << "Product: " << product << endl;
        cout << "Quotient: " << quotient << endl;

        cout << "f1 == f2: " << (f1 == f2) << endl;
        cout << "f1 != f2: " << (f1 != f2) << endl;
        cout << "f1 < f2: " << (f1 < f2) << endl;
        cout << "f1 <= f2: " << (f1 <= f2) << endl;
        cout << "f1 > f2: " << (f1 > f2) << endl;
        cout << "f1 >= f2: " << (f1 >= f2) << endl;
    }
    catch (const exception& e) 
    {
        cerr << "Error: " << e.what() << endl;
    }
}
