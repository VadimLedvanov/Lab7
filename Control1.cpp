#include <iostream>
using namespace std;

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

Time InputTime()
{
    Time t;
    
    
    while (true) {
        cout << "\nВведите количество часов от 0 до 23 включительно: ";
        cin >> t.hours;
        if (t.hours < 0 || t.hours > 23)
        {
            cout << "Неверное количество часов!\n";
            
        }
        else break;
    }

    while (true) {
        cout << "\nВведите количество минут от 0 до 59 включительно: ";
        cin >> t.minutes;
        if (t.minutes < 0 || t.minutes > 59)
        {
            cout << "Неверное количество минут!\n";
            
        }
        else break;
    }
    
    while (true) {
        cout << "\nВведите количество секунд от 0 до 59 включительно: ";
        cin >> t.seconds;
        if (t.seconds < 0 || t.seconds > 59)
        {
            cout << "Неверное количество секунд\n";
        }
        else break;
        
    }
   
    return t;
    
}

Time summation(Time t1, Time t2)
{
    Time result;
    int sec = (t1.hours + t2.hours) * 3600 + (t1.minutes + t2.minutes) * 60 +
        t1.seconds + t2.seconds;

    result.hours = sec / 3600;
    sec -= (result.hours * 3600);

    result.minutes = sec / 60;
    sec -= ((result.minutes * 60));

    result.seconds = sec;

    return result;
}

Time subtraction(Time t1, Time t2)
{
    Time result;
    int sec = (t1.hours - t2.hours) * 3600 + (t1.minutes - t2.minutes) * 60 +
        t1.seconds - t2.seconds;

    if (sec < 0)
    {
        sec = (t2.hours - t1.hours) * 3600 + (t2.minutes - t1.minutes) * 60 +
            t2.seconds - t1.seconds;
    }

    result.hours = sec / 3600;
    sec -= (result.hours * 3600);

    result.minutes = sec / 60;
    sec -= ((result.minutes * 60));

    result.seconds = sec;

    return result;
}

void ShowTime(Time t)
{
    int timeSec = t.hours * 3600 + t.minutes * 60 + t.seconds;
    cout << "Количество секунд в " << t.hours << ":" << t.minutes << ":"
        << t.seconds << " = " << timeSec << endl;
}

int main()
{
    system("chcp 1251");
    Time t1 = InputTime();
    Time t2 = { 10, 15, 30 };
    Time sumTime = summation(t1, t2);
    Time subtrTime = subtraction(t1, t2);
    ShowTime(t1);
    ShowTime(t2);
    ShowTime(sumTime);
    ShowTime(subtrTime);
}