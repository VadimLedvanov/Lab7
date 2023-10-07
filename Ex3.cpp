#include <iostream>
#include <windows.h>
using namespace std;

struct Distance {
    int feet = 0;
    double inches = 0;
};


Distance AddDist(Distance distance[], int n)
{
    Distance x;
    for (int i = 0; i < n; i++)
    {
        x.feet += distance[i].feet;
        x.inches += distance[i].inches;
    }

    x.feet += (int)x.inches / 12;
    int inches = (int)x.inches / 12;
    for (int i = 1; i <= inches; i++)
    {
        x.inches -= 12.0;
    }

    return x;
}

void ShowDist(Distance d)
{
    cout << d.feet << "\'-" << d.inches << "\"\n";
}


Distance InputDist()
{
    Distance d;
    cout << "\nВведите число футов: ";
    cin >> d.feet;
    cout << "Введите число дюймов: ";
    cin >> d.inches;
    return d;
}


int main()
{
    system("chcp 1251");
    int n;
    cout << "Введите размер массива расстояний ";
    cin >> n;

    Distance* masDist = new Distance[n];
    for (int i = 0; i < n; i++)
    {
        masDist[i] = InputDist();
    }

    cout << "==========" << endl;
    
    
    for (int i = 0; i < n; i++)
    {
        ShowDist(masDist[i]);
    }

    cout << "==========" << endl;

    Distance x = AddDist(masDist, n);
    ShowDist(x);

    delete[] masDist;
    return 0;
}
