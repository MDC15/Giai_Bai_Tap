#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int p) {
    if(p < 2) {
        return false;
    }
    for(int i = 2; i <= sqrt(p); i++) {
        if(p % i == 0) {
            return false;
        }
    }
    return true;
}

bool isMersenne(int p) {
    int m = log2(p + 1);
    return isPrime(m) && (p == pow(2, m) - 1);
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
