#include <iostream>
using namespace std;

class Complex
{
    double real;
    double imag;

public:
    Complex(double real, double imag)
    {
        this->real = real;
        this->imag = imag;
    }
    void print()
    {
        cout << this->real << " + " << this->imag << "i" << endl;
    }
    Complex operator+(Complex c)
    {
        return Complex(this->real + c.real, this->imag + c.imag);
    }
    Complex operator-(Complex c)
    {
        return Complex(this->real - c.real, this->imag - c.imag);
    }
    Complex operator*(Complex c)
    {
        real = this->real * c.real - this->imag * c.imag;
        imag = this->real * c.imag + this->imag * c.real;
        return Complex(real, imag);
    }
    Complex operator/(Complex c)
    {
        double denom = c.real * c.real + c.imag * c.imag;
        double realPart = (this->real * c.real + this->imag * c.imag) / denom;
        double imagPart = (this->imag * c.real - this->real * c.imag) / denom;
        return Complex(realPart, imagPart);
    }
};

int main()
{
    Complex c1(1.0, 2.0);
    Complex c2(3.0, 4.0);
    Complex c3 = c1 + c2;
    Complex c4 = c1 * c2;
    Complex c5 = c1 - c2;
    Complex c6 = c1 / c2;
    cout << "c1 + c2 = ";
    c3.print();
    cout << "c1 * c2 = ";
    c4.print();
    cout << "c1 - c2 = ";
    c5.print();
    cout << "c1 / c2 = ";
    c6.print();
    return 0;
}