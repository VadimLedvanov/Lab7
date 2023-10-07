#include <iostream>
#include <windows.h>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
using Tuple = tuple<string, int, double>;
using NewTuple = tuple<string, int>;

Tuple funtup(string s, int a, double d)
{
    s.append("!");
    return make_tuple(s, a, d * 10);
}

void printTupleOfThree(Tuple t)
{
    cout << "("
        << get<0>(t) << ", "
        << get<1>(t) << ", "
        << get<2>(t) << ")" << endl;
}

void printTupleOfTwo(NewTuple t)
{
    cout << "("
        << get<0>(t) << ", "
        << get<1>(t) << ")" << endl;
}

Tuple changeValues(Tuple t)
{
    get<0>(t) = "new string";
    get<1>(t) = 26;
    get<2>(t) = 71.0;

    return t;
}

NewTuple newTup(Tuple t)
{
    return make_tuple("строка в новом кортеже", 17);
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    

    vector<string> v1{ "one", "two", "three", "four", "five", "six" };
    vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
    vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

    auto t0 = make_tuple(v1[0], v2[0], v3[0]);
    printTupleOfThree(t0);

    auto t1 = funtup(v1[1], v2[1], v3[1]);
    printTupleOfThree(t1);

    auto t2 = changeValues(t1);
    printTupleOfThree(t2);
    printTupleOfThree(t1);


    auto t3 = newTup(t0);
    printTupleOfTwo(t3);

    return 0;

}