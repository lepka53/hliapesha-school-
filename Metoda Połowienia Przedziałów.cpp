#include <iostream>
using namespace std;

double f(double x);
double polowienie(double a, double b, double eps);

int main()
{
    cout << "Wpisz lewy kraniec przedzialu: ";
    double a;
    cin >> a;

    cout << "Wpisz prawy kraniec przedzialu: ";
    double b;
    cin >> b;

    cout << "Wpisz dokladnosc wyznaczania miejsca zerowego: ";
    double eps;
    cin >> eps;

    cout << "Znalezione miejsce zerowe wynosi: " << polowienie(a, b, eps);
    return 0;
}

double f(double x)
{
    return x * (x * (x - 3) + 2) - 6;
}

double polowienie(double a, double b, double eps)
{
    if (f(a) == 0.0)
    {
        return a;
    }

    if (f(b) == 0.0)
    {
        return b;
    }

    while (b - a > eps)
    {
        double srodek = (a + b) / 2;
        if (f(srodek) == 0)
        {
            return srodek;
        }
        if (f(a) * f(srodek) < 0)
        {
            b = srodek;
        }
        else
        {
            a = srodek;
        }
    }

    return (a + b) / 2;
}