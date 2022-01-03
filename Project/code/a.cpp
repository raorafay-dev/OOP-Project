#include <iostream>
using namespace std;

float atm(int wi, int am)
{
    if (wi % 5 == 0 && wi < am)
    {
        return ((am - wi)) - 0.50;
    }

    else
    {
        return am;
    }
}

int main()
{
    int wi;
    float am;

    cin >> wi >> am;
    cout << atm(wi, am);

    return 0;
}
