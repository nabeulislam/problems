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
		inf.readLong(1LL,100,"n");
		inf.readSpace();
		inf.readInt(2,2,"x");
		inf.readEoln();

	}
	// inf.readEoln();
	inf.readEof();
}
