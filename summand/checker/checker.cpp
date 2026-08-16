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
int main(int argc, char* argv[]) {
	registerTestlibCmd(argc, argv);
	// compareRemainingLines();
	int t = inf.readInt();
	double full = 1.0;
	for(int i =0; i < t; i++)
	{
		ll n = inf.readLong();
		int  x= inf.readInt();
		ll mans = ans.readLong();
		for (int k = 0; k < mans; k++)
		{
			ans.readLong();
		}

		int m = ouf.readLong(1LL,INT_MAX,"m");
		if(m!=mans)
		{
			quitf(_wa,"invalid m vy. aro valo answer ase");
		}
		ll first = ouf.readLong();
		if(first==-1)
		{
			full = 0.5;
			continue;
		}


		// arr check
		bool ok = true;
		ll sum = binpow(first,x);
		ll prev = first;
		for(int  j =0; j < mans-1; j++)
		{
			ll val = ouf.readLong();
			if(val<prev)
			{
				ok = false;
			}
			sum+=binpow(val,x);
			prev=val;
		}

		if(sum!=n)
		{
			ok = false;
		}

		if(!ok)
		{
			quitf(_wa,"array vul vy. point paiben na vy.");
		}

	}


	if(full==1.0)
	{
		quitf(_ok,"yay shob thikthak 67.");
	}
	else
	{
		quitp(full,"aro valo kore try koren, tahole baki point o paben.");
	}

	return 0;

}
