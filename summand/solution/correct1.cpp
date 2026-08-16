//Indeed Hardship comes with ease [94:6]
//Man will not get anything unless he works hard  [53:39]
//ᴇᴀᴄʜ ᴘᴇʀꜱᴏɴ ᴡɪʟʟ ᴏɴʟʏ ʜᴀᴠᴇ ᴡʜᴀᴛ ᴛʜᴇʏ ᴇɴᴅᴇᴀᴠᴏᴜʀᴇᴅ ᴛᴏᴡᴀʀᴅꜱ [53:39]
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend() 
const int MAXN = 100000;
ll dp[MAXN + 5][11];
ll base[MAXN + 5][11];
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
void precompute()
{
     for (int x = 0; x <= 10; x++) {
        for (int i = 0; i <= MAXN; i++) dp[i][x] = LLONG_MAX;
    }
    for (int x = 2; x <= 10; x++) dp[0][x] = 0;
   
    for(ll x = 2; x <= 10; x++)
    {
        ll j = 1;
        vector<ll> powers;
        while(j<=MAXN)
        {
            ll val = binpow(j, x);
            if(val>MAXN) break;
            powers.push_back(val);
            j++;
        }

        for(int i = 1; i <= MAXN; i++)
        {
            dp[i][x] = LLONG_MAX;
            for(int k = 0; k < j-1; k++)
            {
                if(powers[k] > i) break;
                if(dp[i-powers[k]][x] !=LLONG_MAX && dp[i - powers[k]][x] + 1 < dp[i][x])
                {
                    dp[i][x] = dp[i - powers[k]][x] + 1;
                    base[i][x] = k + 1;
                }
            }
      }
   }

}
void solve()
{
    ll n, x;
    cin >> n >> x;
    if (x == 1){
        // cout << 1 << " " << -1 << "\n";
        cout << 1 << " " << n << endl;
    
        return;
    }
    

    // cout << dp[n][x] << " " << "-1" << "\n";
    cout << dp[n][x] << "\n";
    vector<ll> ans;
    ll curr= n;
    while(curr > 0){
        ans.push_back(base[curr][x]);
        curr -= binpow(base[curr][x], x);
    }
    sort(all(ans));
    for(ll i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }

    return 0;
}