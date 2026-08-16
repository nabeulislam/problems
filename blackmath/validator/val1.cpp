#include "testlib.h"
using namespace std;


int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
	inf.readLong(1, 3LL, "n");
	inf.readSpace();
	inf.readLong(0LL, 1000000000000000000LL, "a");
	inf.readSpace();
	inf.readLong(0LL, 1000000000000000000LL, "b");
	inf.readEoln();
	inf.readEof();
	return 0;
}
