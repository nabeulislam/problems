#include "testlib.h"
using namespace std;


int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
	int n = inf.readInt(1, 500000, "n");
	inf.readSpace();
	int q = inf.readInt(1, 500000, "q");
	inf.readEoln();
	int msg = 0;
	for(int i=0; i<q; i++)
	{
		int t = inf.readInt(1, 3, "t");
		if(t == 1)
		{
			inf.readEoln();
			msg++;
		}
		else if(t == 2)
		{
			inf.readSpace();
			inf.readInt(1, n, "f");
			inf.readEoln();
		}
		else
		{
			inf.readSpace();
			inf.readInt(1, 500000, "id");
			inf.readEoln();
		}
	}
	
	inf.readEof();
	return 0;
}
