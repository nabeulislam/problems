#include "testlib.h"
using namespace std;
#define ll long long
const int MAXN = 1000;

int main(int argc, char* argv[]) {
	registerValidation(argc,argv);
	int t= inf.readInt(1,1000,"t");
	inf.readEoln();
	for(int i = 0; i<t; i++)
	{
		inf.readLong(1LL,100000,"n");
		inf.readSpace();
		inf.readInt(1,10,"x");
		inf.readEoln();
	}
	// inf.readEoln();
	inf.readEof();
}
