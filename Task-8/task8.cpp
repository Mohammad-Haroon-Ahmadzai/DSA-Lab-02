#include <iostream>
using namespace std;

/*
Original buggy code:
    int n = 3;
    int* values = new int[n];
    for (int i = 0; i <= n; i++) cin >> values[i];
    delete values;
    cout << values[0];

Errors found:
1) Out-of-bounds write: i <= n writes to values[3] but valid indices are 0..2.
2) Wrong delete: memory from new[] must be freed with delete[], not delete.
3) Dangling pointer: values[0] is read after the memory was freed.
*/

int main()
{
    int n = 3;
    int *values = new int[n];

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++)           // fixed: i < n
        cin >> values[i];

    cout << "You entered: ";
    for (int i = 0; i < n; i++)
        cout << values[i] << " ";
    cout << endl;

    delete[] values;                      // fixed: delete[]
    values = nullptr;                     // no dangling pointer

    return 0;
}
