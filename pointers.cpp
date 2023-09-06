#include <iostream>
using namespace std;

int main()
{
    int x, y, z;
    cout << "Enter your three Integers..\n";
    cin >> x;
    cin >> y;
    cin >> z;

    int *pX = &x, *pY = &y, *pZ = &z;

    // graetest
    if (*pX > *pY)
    {
        if (*pX > *pZ)
        {
            cout << "Greatest is : " << *pX;
        }
        else
        {
            cout << "Greatest is : " << *pZ;
        }
    }
    else if (*pY > *pZ)
    {
        cout << "Greatest is : " << *pY;
    }
    else
    {
        cout << "Greatest is : " << *pZ;
    }

    cout << "\n";
    // smallest
    if (*pX < *pY)
    {
        if (*pX < *pZ)
        {
            cout << "Smallest is : " << *pX;
        }
        else
        {
            cout << "Smallest is : " << *pZ;
        }
    }
    else if (*pY < *pZ)
    {
        cout << "Smallest is : " << *pY;
    }
    else
    {
        cout << "Smallest is : " << *pZ;
    }

    return 0;
}
