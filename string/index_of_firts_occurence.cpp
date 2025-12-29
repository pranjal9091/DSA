#include <iostream>
#include <string>
using namespace std;

int main() {
    string haystack, needle;
    cin >> haystack >> needle;

    int n = haystack.length();
    int m = needle.length();

    if (m > n) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
            j++;
        }
        
        if (j == m) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}