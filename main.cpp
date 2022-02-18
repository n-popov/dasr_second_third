#include <iostream>

using std::cout, std::endl;

class Rational {
public:
    // Конструктор дроби, здесь num - числитель, den - знаменатель
    Rational(int a, int b) : num(a), den(b) {}

    Rational operator+(Rational other) const {
        return {num * other.den + den * other.num, den * other.den};
    }

    Rational operator-(Rational other) const {
        return {num * other.den - den * other.num, den * other.den};
    }

    Rational operator*(Rational other) const {
        return {num * other.num, den * other.den};
    }

    Rational operator/(Rational other) const {
        return {num * other.den, den * other.num};
    }

    Rational operator*(int number) {
        return {num * number, den};
    }

    friend Rational operator*(int, Rational);

    friend std::ostream& operator<<(std::ostream&, Rational);
    // Реализуйте операторы:
    // - сложения двух дробей
    // - вычитания двух дробей
    // - умножения двух дробей
    // - деления двух дробей
    // - умножения дроби на целое число (должно работать при любом порядке операндов)
private:
    int num, den;
};

Rational operator*(int number, Rational rational) {
    return {rational.num * number, rational.den};
}

std::ostream& operator<<(std::ostream& out, Rational rational) {
    return out << rational.num << '/' << rational.den;
}

int main()
{
    Rational a(1, 2);
    Rational b(2, 3);

    cout << a << endl;
    cout << b << endl;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << 3 * a << endl;
    cout << b * 4 << endl;

    return 0;
}
