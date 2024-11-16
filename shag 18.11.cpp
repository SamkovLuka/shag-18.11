#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

   
    int gcd(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return (a < 0) ? -a : a;
    }


    void simplify() {
        int gcd_value = gcd(numerator, denominator);
        numerator /= gcd_value;
        denominator /= gcd_value;

        
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num = 0, int denom = 1) {
        if (denom == 0) {
            cout << "�������: ��������� �� ���� ���� �����. ��� ����������� �� 0/1." << endl;
            numerator = 0;
            denominator = 1;
        }
        else {
            numerator = num;
            denominator = denom;
            simplify();
        }
    }




    
    void setFraction(int num, int denom) {
        if (denom == 0) {
            cout << "�������: ��������� �� ���� ���� �����. ���� �� �����������." << endl;
        }
        else {
            numerator = num;
            denominator = denom;
            simplify();
        }
    }



   
    Fraction add(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction subtract(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction multiply(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction divide(const Fraction& other) const {
        if (other.numerator == 0) {
            cout << "�������: ������ �� ��� �� ����������� 0, ����������� 0/1" << endl;
            return Fraction(0, 1);
        }
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }

    
    friend ostream& operator<<(ostream& os, const Fraction& frac) {
        os << frac.numerator;
        if (frac.denominator != 1) {
            os << "/" << frac.denominator;
        }
        return os;
    }
};



int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    Fraction frac1(3, 4);
    Fraction frac2(5, 6);
    cout << "������ ���: " << frac1 << endl;
    cout << "������ ���: " << frac2 << endl;
    Fraction sum = frac1.add(frac2);
    cout << "����: " << sum << endl;
    Fraction difference = frac1.subtract(frac2);
    cout << "г�����: " << difference << endl;
    Fraction product = frac1.multiply(frac2);
    cout << "�������: " << product << endl;
    Fraction quotient = frac1.divide(frac2);
    cout << "������: " << quotient << endl;

    


    Fraction invalid(1, 0);
    cout << "��������� ���: " << invalid << endl;

    
}
