#include <iostream>
#include <math.h>
using namespace std;

bool isMersenne(int p) {
    int m = log2(p + 1);
    return (m) && (p == pow(2, m) - 1);
}

int main() {
    int p;
    cout << "\nNhap so p = ";
    cin >> p;
    
    if(isMersenne(p)) {
        cout << p << " la so Mersenne.\n";
    } else {
        cout << p << " khong phai la so Mersenne.\n";
    }
    return 0;
}
