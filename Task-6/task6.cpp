#include <iostream>
using namespace std;

int main()
{
    int rows, cols;

    // ---- validated input ----
    do
    {
        cout << "Enter number of students: ";
        cin >> rows;
        if (rows <= 0)
            cout << "Invalid! Number of students must be positive.\n";
    } while (rows <= 0);

    do
    {
        cout << "Enter number of subjects: ";
        cin >> cols;
        if (cols <= 0)
            cout << "Invalid! Number of subjects must be positive.\n";
    } while (cols <= 0);

    // ---- allocate array of row pointers, then each row ----
    int **marks = new int *[rows];
    for (int r = 0; r < rows; r++)
        marks[r] = new int[cols];

    // ---- read marks (0-100 assumed valid) ----
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            cout << "Student " << r + 1 << ", Subject " << c + 1 << " marks: ";
            cin >> *(*(marks + r) + c);   // same as marks[r][c]
        }
    }

    // ---- display the matrix ----
    cout << "\nMarks Matrix:\n";
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
            cout << *(*(marks + r) + c) << "\t";
        cout << endl;
    }

    // ---- totals and topper ----
    int bestTotal = 0;
    for (int c = 0; c < cols; c++)
        bestTotal += marks[0][c];
    int bestStudent = 1;                  // student numbers start at 1

    for (int r = 1; r < rows; r++)
    {
        int total = 0;
        for (int c = 0; c < cols; c++)
            total += marks[r][c];

        if (total > bestTotal)            // strictly greater: first student wins ties
        {
            bestTotal = total;
            bestStudent = r + 1;
        }
    }
    cout << "\nHighest total = " << bestTotal
         << " (Student " << bestStudent << ")" << endl;

    // ---- cleanup: rows first, then the row-pointer array ----
    for (int r = 0; r < rows; r++)
        delete[] marks[r];
    delete[] marks;
    marks = nullptr;

    return 0;
}

/*
If only delete[] marks; was executed, the row-pointer array would be freed
but every separately allocated row would stay allocated with no pointer left
to reach it, which is a memory leak.
*/
