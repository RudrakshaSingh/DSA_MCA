#include <iostream>
using namespace std;

int main() {
    int a = 5;
    if (a > 3) {
        cout << "Greater than 3" << endl;
    } else {
        cout << "Less than or equal to 3" << endl;
    }

    for (int i = 0; i < 5; i++) {
        cout << "Loop iteration " << i << endl;
    }

    return 0;
}