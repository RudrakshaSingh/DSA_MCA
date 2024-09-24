#include <iostream>
using namespace std;

int main()
{
    int rows1, cols1, rows2, cols2;

    // array1
    cout << "Enter the number of rows and columns for the first array: ";
    cin >> rows1 >> cols1;

    // array2
    cout << "Enter the number of rows and columns for the second array: ";
    cin >> rows2 >> cols2;

    // array declared
    int arr1[rows1][cols1], arr2[rows2][cols2], result[rows1][cols1];

    if (rows1 != rows2 || cols1 != cols2)
    {
        cout << "The arrays are not equal in size.\n";
        return 0;
    }

    // Input arr1
    cout << "Enter elements for the first array:\n";
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            cin >> arr1[i][j];
        }
    }

    // Input arr2
    cout << "Enter elements for the second array:\n";
    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            cin >> arr2[i][j];
        }
    }

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    cout << "The arrays are equal in size. The resulting array after addition is:\n";

    // Output the result array
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}