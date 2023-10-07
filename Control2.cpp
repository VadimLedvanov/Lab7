#include <iostream>
using namespace std;

struct Roots {
    double x1;
    double x2;
};

Roots solveQE(double a, double b, double c)
{
    Roots roots;
    if (a == 0)
    {
        cout << "Уравнение не квадратное\n";
        exit(0);
    }
    else
    {
        double D = b * b - 4 * a * c;
        if (D < 0)
        {
            cout << "Уравнение не имеет корней\n";
            exit(0);
        }
        roots.x1 = (-b + sqrt(D)) / (2 * a);
        roots.x2 = (-b - sqrt(D)) / (2 * a);
    }

    return roots;
}

void showRoots(Roots r)
{  
    cout.precision(2);
    cout << "x1= " << fixed << r.x1 << endl;
    cout << "x2= " << fixed << r.x2 << endl;
}

int main()
{
    system("chcp 1251");
    double a, b, c;
    cout << "a="; cin >> a;
    cout << "b="; cin >> b;
    cout << "c="; cin >> c;

    Roots r = solveQE(a, b, c);
    showRoots(r);
}