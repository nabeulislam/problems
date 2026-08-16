#include <bits/stdc++.h>
using namespace std;

long long a, b;

long long f(long long n) {
    if (n == 1) return a;
    if (n == 2) return b;
    return f(n - 1) ^ f(n - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n >> a >> b;

    cout << f(n) << "\n";
    return 0;
}