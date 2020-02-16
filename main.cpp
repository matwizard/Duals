#include <iostream>
using namespace std;

// Create a DualNum class with some attributes

class Dual {
public:
    double a, b;
    Dual(double r = 0, double i =0)  {a = r;   b = i;}
    void print() { cout << a << " + " << b << "*epsilon" << endl;}

    friend Dual operator + (Dual const &, Dual const &);
    friend Dual operator - (Dual const &, Dual const &);
    friend Dual operator * (Dual const &, Dual const &);
    friend Dual operator / (Dual const &, Dual const &);
};

Dual operator + (Dual const &d1, Dual const &d2)
{
    return Dual(d1.a + d2.a, d1.b + d2.b);
}
Dual operator - (Dual const &d1, Dual const &d2)
{
    return Dual(d1.a - d2.a, d1.b - d2.b);
}
Dual operator * (Dual const &d1, Dual const &d2)
{
    return Dual(d1.a * d2.a, d1.b*d2.a + d1.a*d2.b);
}
Dual operator / (Dual const &d1, Dual const &d2)
{
    return Dual(d1.a / d2.a, (d1.b*d2.a - d1.a*d2.b)/(d2.a*d2.a));
}

int main() {
    Dual c1(50, -15), c2(5, -4);
    Dual c3 = c1 / c2; // An example call to "operator+"
    c3.print();
}
