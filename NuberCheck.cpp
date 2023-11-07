#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int n) {
    if(n < 2) {
        return false;
    }
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

bool isMersenne(int n) {
    int m = log2(n + 1);
    return isPrime(m) && (n == pow(2, m) - 1);
}

int main() {
    int n;
    cout << "\nNhap n = ";
    cin >> n;
    if(isMersenne(n)) {
        cout << n << " la so Mersenne\n";
    } else {
        cout << n << " khong phai la so Mersenne\n";
    }
    return 0;
}
