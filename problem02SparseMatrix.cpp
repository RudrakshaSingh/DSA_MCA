//sparse matrix
#include <bits/stdc++.h>

using namespace std;

int main() {
    ///////////////////////////Array////////////////////////////////////
    int rows, columns;
    cout << "Enter Rows(max:10) and Columns(max:10) :" << endl;
    cin >> rows >> columns;

    if (rows == 0 && columns == 0) {
        cout << "both rows and columns cannot be zero" << endl;
        return 0;
    } else if (rows > 10 || columns > 10) {
        cout << "rows and columns cannot be greater than 10" << endl;
        return 0;
    }

    int arr[rows][columns];

    cout << "Enter elements of matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Input Matrix: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    ///////////////////////////Sparse Matrix////////////////////////////////////
    int cnt = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (arr[i][j] == 0)
                cnt++;
        }
    }

    // total elements in array
    int totalElements = rows * columns;

    if (totalElements - cnt > (totalElements / 4)) {
        cout << "not sparse matrix" << endl;
        cout << "exiting program." << endl;
        return 0;
    }

    cout << "Sparse Matrix" << endl;

    int nonZeroElement = totalElements - cnt;

    int sparseMatrix[nonZeroElement + 1][3];

    int row = 0;
    sparseMatrix[row][0] = rows;
    sparseMatrix[row][1] = columns;
    sparseMatrix[row][2] = nonZeroElement;
    row++;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (arr[i][j] != 0) {
                sparseMatrix[row][0] = i;
                sparseMatrix[row][1] = j;
                sparseMatrix[row][2] = arr[i][j];
                row++;
            }
        }
    }

    for (int i = 0; i < nonZeroElement + 1; i++) {
        for (int j = 0; j < 3; j++) {
            cout << sparseMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "used zero based indexing" << endl;

    return 0;
}