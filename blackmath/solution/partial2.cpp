#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, a, b;
    cin >> n >> a >> b;

    if (n == 1) { cout << a << "\n"; return 0; }
    if (n == 2) { cout << b << "\n"; return 0; }

    long long prev2 = a, prev1 = b, cur;
    for (long long i = 3; i <= n; i++) {
        cur = prev1 ^ prev2;
        prev2 = prev1;
        prev1 = cur;
    }

    cout << cur << "\n";
    return 0;
}