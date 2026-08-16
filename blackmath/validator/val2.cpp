#include "testlib.h"
using namespace std;


int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
	inf.readLong(1, 10LL, "n");
	inf.readSpace();
	inf.readLong(1, 1LL, "a");
	inf.readSpace();
	inf.readLong(1, 1LL, "b");
	inf.readEoln();
	inf.readEof();
	return 0;
}
