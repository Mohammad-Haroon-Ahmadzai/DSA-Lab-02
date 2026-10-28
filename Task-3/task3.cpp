#include <iostream>
using namespace std;

int main()
{
    int list[5] = {3, 6, 9, 12, 15};
    int *pArr = list;           // pArr holds the address of list[0]

    cout << "Values of array list (printed via pointer only): " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << *pArr << " ";   // dereference to get the value
        pArr++;                 // move to the next int
    }
    cout << endl;
    return 0;
}
