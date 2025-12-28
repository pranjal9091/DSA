#include <iostream>
#include <string>
using namespace std;

int main() {
    string num;
    cin >> num;

    for(int i = num.length() - 1; i >= 0; i--) {
        if(num[i] % 2 != 0) {
            cout << num.substr(0, i + 1) << endl;
            return 0;
        }
    }

    cout << "" << endl;
    return 0;
}