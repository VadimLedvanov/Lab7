#include <iostream>
#include <tuple>
#include <string>
using namespace std;
using Tuple = tuple<double, double, string>;

Tuple solveQE(double a, double b, double c)
{
    Tuple roots;
    if (a == 0)
    {
        cout << "Уравнение не квадратное\n";
        get<2>(roots) = "нет";
        return roots;
    }
    else
    {
        double D = b * b - 4 * a * c;
        if (D < 0)
        {
            cout << "Уравнение не имеет корней\n";
            get<2>(roots) = "нет";
            return roots;
            
        }
        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b - sqrt(D)) / (2 * a);
        get<0>(roots) = x1;
        get<1>(roots) = x2;
        get<2>(roots) = "да";
    }

    return roots;
}

void showRoots(Tuple t)
{
    cout << "(" <<
        get<0>(t) << ", " <<
        get<1>(t) << ", " <<
        get<2>(t) << ")" << endl;
}

int main()
{
    system("chcp 1251");
    double a, b, c;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    Tuple r = solveQE(a, b, c);
    showRoots(r);
}