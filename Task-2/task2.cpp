#include <iostream>
using namespace std;

int main()
{
    int a, *pa;                 // Statement 1
    pa = &a;                    // Statement 2
    cout << "pa = &a --> pa = " << pa << endl << endl;

    pa = pa + 1;                // Statement 3
    cout << "pa = pa + 1 --> pa = " << pa << endl << endl;

    pa = pa + 3;                // Statement 4
    cout << "pa = pa + 3 --> pa = " << pa << endl << endl;

    pa = pa - 1;                // Statement 5
    cout << "pa = pa - 1 --> pa = " << pa << endl << endl;

    return 0;
}

/*
Q1. Why does the address in pa vary by 4?
Pointer arithmetic is scaled by sizeof(the pointed-to type). pa is an int*
and sizeof(int) is 4 bytes here, so pa + 1 adds 1 * 4 = 4 bytes.

Q2. Will it still vary by 4 if int is changed to long?
Not necessarily. On Windows (MSVC) sizeof(long) is 4, so yes. On 64-bit
Linux/macOS sizeof(long) is 8, so the address would jump by 8.

Q3. What if we multiply the address in pa?
It does not compile. C++ only defines pointer + int, pointer - int and
pointer - pointer. Multiplying addresses has no meaning anyway.
*/
