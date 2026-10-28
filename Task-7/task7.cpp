#include <iostream>
using namespace std;

int main()
{
    int n;
    do
    {
        cout << "Enter number of students already entered (1-10): ";
        cin >> n;
    } while (n < 1 || n > 10);

    int *marksArr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter mark " << i + 1 << ": ";
        cin >> *(marksArr + i);
    }

    int newMark;
    cout << "Enter the new student's mark: ";
    cin >> newMark;

    // 1) allocate a bigger block and copy the old values across
    int *temp = new int[n + 1];
    for (int i = 0; i < n; i++)
        *(temp + i) = *(marksArr + i);
    *(temp + n) = newMark;                // add the new mark at the end

    // 2) free the old block, repoint, update size
    delete[] marksArr;
    marksArr = temp;
    temp = nullptr;
    n = n + 1;

    cout << "Updated marks: ";
    for (int i = 0; i < n; i++)
        cout << *(marksArr + i) << " ";
    cout << endl;

    // 3) free the final block
    delete[] marksArr;
    marksArr = nullptr;

    return 0;
}
