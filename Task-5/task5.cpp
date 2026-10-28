#include <iostream>
using namespace std;

// Swaps the values pointed to by x and y
void swapByPointer(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Swaps the values using pointer-to-pointer parameters
void swapByDoublePointer(int **px, int **py)
{
    int temp = **px;
    **px = **py;
    **py = temp;
}

int main()
{
    int a = 5, b = 10;
    int *pa = &a, *pb = &b;
    int **ppa = &pa, **ppb = &pb;

    cout << "Before swap: a = " << a << ", b = " << b << endl;

    swapByPointer(&a, &b);
    cout << "After swapByPointer: a = " << a << ", b = " << b << endl;

    swapByDoublePointer(ppa, ppb);
    cout << "After swapByDoublePointer: a = " << a << ", b = " << b << endl;

    return 0;
}
