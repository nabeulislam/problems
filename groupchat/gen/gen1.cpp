#include <iostream>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int subtask = atoi(argv[1]);
	int min_n = 1, max_n = 500000;
	int min_q = 1, max_q = 500000;
	if (subtask == 1) {
		max_n = 1;
	}
	else if(subtask==2)
	{
		max_n = 5000;
		max_q = 5000;
	}
	int n = rnd.next(min_n, max_n);
	int q = rnd.next(min_q, max_q);
	println(n, q);
	int msg = 0;
	if(subtask==3)
	{
		int reserve3 = q/10;
		int left = q-reserve3;
		for(int i=0; i<left; i++)
		{
			if(msg ==0)
			{
				println(1);
				msg++;
			}
			else
			{
				int t = rnd.next(1, 2);
				if(t==1)
				{
					println(1);
					msg++;
				}
				else
				{
					int f = rnd.next(1, n);
					println(2, f);
				}
			}

		}

		for(int i=0; i<reserve3; i++)
		{
			int id = rnd.next(1, msg);
			println(3,id);
		}
	}
	else
	{
		for(int i=0; i<q; i++)
		{
			if(msg ==0)
			{
				println(1);
				msg++;
			}
			else
			{
				int t = rnd.next(1, 3);
				if(t==1)
				{
					println(1);
					msg++;
				}
				else if(t==2)
				{
					int f = rnd.next(1, n);
					println(2, f);
				}
				else
				{
					int id = rnd.next(1, msg);
					println(3, id);
				}
			}
		}
	}
	return 0;
}
