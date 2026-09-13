#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int re = a * c - b * d;
    int im = a * d + b * c;
    cout << re << showpos << im << "i" << endl;
    return 0;
}