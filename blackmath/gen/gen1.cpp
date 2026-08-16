#include "testlib.h"
#define ll long long
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    ll subtask = atoi(argv[1]);
    ll min_n = 1LL;
    ll max_n = 1000000000000000000LL;
    ll min_a = 0LL;
    ll min_b = 0LL;
    
    ll  max_a = 1000000000000000000LL;
    ll max_b =  1000000000000000000LL;

    if (subtask == 1) {
        max_n = 3;
    } else if (subtask == 2) {
        max_n = 10LL;
        min_a = 1LL;    
        max_a = 1LL;
		min_b = 1LL;
        max_b = 1LL;

    } else if (subtask == 3) {
        max_n = 20LL;
    } else if (subtask == 4) {
        max_n = 1000LL;
    } else if (subtask == 5) {
        max_n = 100000LL;
    } else if (subtask == 6) {
        min_n = 1000000000000000000LL;
        max_n = 1000000000000000000LL;
        min_a = 999999999999999990LL;
        min_b = 999999999999999900LL;
    }

    ll n = rnd.next(min_n, max_n);
    ll a = rnd.next(min_a, max_a);
    ll b = rnd.next(min_b, max_b);

    cout << n << " " << a << " " << b << "\n";
         
    return 0;
}