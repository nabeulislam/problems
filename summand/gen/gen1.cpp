#include <iostream>
#include "testlib.h"
using namespace std;
#define ll long long
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
ll nth(ll num, ll n)
{
	ll lo = 1;
	ll ans = 1;
	ll hi = num;
	while (lo<=hi)
	{
		ll mid = lo+(hi-lo+1)/2;
		ll val =  binpow(mid,n);
		if(val<=num)
		{
			ans=mid;
			lo=mid+1;
		}
		else
		{
			hi=mid-1;
		}
	}
	return ans;
	
}
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int t = atoi(argv[1]);
	int subtask = atoi(argv[2]);
	println(t);
	for (int i = 0; i < t; i++)
	{
		int x =1;
		ll n = 1LL;
		if (subtask==1)
		{
			x=1;
			n=rnd.next(1LL,100000LL);	
		}
		else if(subtask==2)
		{
			x=rnd.next(2,10);
			ll maxn = binpow(2LL,x)-1LL;
			maxn = min(maxn, 100000LL);
			n=rnd.next(2LL,maxn);
		}
		else if(subtask==3)
		{
			x=rnd.next(2,10);
			ll maxn = 1LL;
			while(binpow(maxn+1LL,x)<=100000LL)
			{
				maxn++;
			}

			ll a,b;
			while(true)
			{
				a = rnd.next(1LL,maxn);
				b = rnd.next(1LL,maxn);
				n= binpow(a,x)+binpow(b,x);
				if(n>100000LL)
				{
					continue;
				}
				ll root =  nth(n,x);
				if(binpow(root,x)==n) continue;
				break;

			}
		}
		else if (subtask==4)
		{
			x=2;
			n=rnd.next(1LL,100LL);
		}
		else if(subtask==5)
		{
			x=rnd.next(1,10);
			n=rnd.next(1LL,1000LL);

		}
		else if(subtask==6)
		{
			x=rnd.next(2,3);
			n=rnd.next(1LL,100000LL);
		}
		else if(subtask==7)
		{
			x=rnd.next(2,10);
			n=rnd.next(99999LL,100000LL);
		}

		cout << n << " " << x << endl;
		
		
	}
	
	

	return 0;
}
