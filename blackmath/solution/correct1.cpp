#include<iostream>
using namespace std;
#define ll long long
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	ll n,a,b;
	cin >> n >> a >> b;
	ll x = n%3;
	if(x==1)
	{
		cout << a << "\n";
	}
	else if(x==2)
	{
		cout << b << "\n";
	}
	else
	{
		cout << (a^b) << "\n";
	}
	return 0;
}
