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
	registerValidation(argc,argv);
	int t= inf.readInt(1,1000,"t");
	inf.readEoln();
	for(int i = 0; i<t; i++)
	{
		ll n = inf.readLong(1LL,100000,"n");
		inf.readSpace();
		int x = inf.readInt(1,10,"x");
		inf.readEoln();

        ll val = binpow(2,x);

        ensuref(val>n,"vul korsen vy generator check maren");

	}
	// inf.readEoln();
	inf.readEof();
}
