//Indeed Hardship comes with ease [94:6]
//Man will not get anything unless he works hard  [53:39]
//ᴇᴀᴄʜ ᴘᴇʀꜱᴏɴ ᴡɪʟʟ ᴏɴʟʏ ʜᴀᴠᴇ ᴡʜᴀᴛ ᴛʜᴇʏ ᴇɴᴅᴇᴀᴠᴏᴜʀᴇᴅ ᴛᴏᴡᴀʀᴅꜱ [53:39]
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1){
            res = res * a;
			if (res > 100000) return 100001;
		}
		if(b>1)
		{
			 a = a * a;
			 if(a>100000) return 100001;
		}
        b >>= 1;
    }
    return res;
}
void solve()
{
    ll n, x;
    cin >> n >> x;
    if (x == 1){
        cout << 1 << " " << -1 << "\n";
        return;
    }
    vector<ll> dp(n + 1, LLONG_MAX);
    vector<ll> base(n+1, -1);
    dp[0] = 0;
    for(ll i = 1; i <= n; i++){
        ll  j = 1;
        while(true){
            ll val = binpow(j, x);
            if(val > i) break;
            if(dp[i - val] != LLONG_MAX && dp[i - val] + 1 < dp[i]){
                dp[i] = dp[i - val] + 1;
                base[i] = j;
            }
            j++;
        }
    }

    cout << dp[n] <<" " << "-1" << "\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}