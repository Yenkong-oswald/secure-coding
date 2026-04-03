#include <iostream>
using namespace std;

int main() {
    char buffer[5];

    cout << "Enter text: ";
    cin >> buffer; // No bounds check

    cout << "You entered: " << buffer << endl;
    return 0;
}
