#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> arr;
    int index, value;
    cin >> index >> value;
    if (index >= 0 && index < arr.size()) {
        arr[index] = value;
        cout << "Updated safely\n";
    } else {
        cout << "Invalid index\n";
    }
    return 0;
}
