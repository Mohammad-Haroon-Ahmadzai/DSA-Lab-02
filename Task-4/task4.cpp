#include <iostream>
using namespace std;

int main()
{
    // ---- Part (a) ----
    int x[4] = {0, 4, 6, 9};
    int *p, a = 3;
    p = x;
    (*p)++;
    cout << *p << endl;         // 1
    cout << *(p + 1) << endl;   // 4
    p++;
    *p = *p + a;
    cout << *p << endl;         // 7
    p = p + 2;                  // p now points to x[3]
    cout << *p << endl;         // 9

    // ---- Part (b) ----
    int b, *p2, *q;
    int arr[4] = {0};
    p2 = arr;
    q = p2;
    *p2 = 4;
    for (int i = 0; i < 3; i++)
    {
        b = *p2;
        p2++;
        *p2 = (b + i);
    }
    for (int j = 0; j < 4; j++)
    {
        cout << *q << " ";      // 4 4 5 7
        q++;
    }
    cout << endl;
    return 0;
}
