#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <conio.h>
#include <algorithm>
#include <time.h>

#include "Sorting.h"
#include "Structure.h"

#include "Basic.cpp"
#include "Sorting.cpp"
//#include "Heap.cpp"

using namespace std;
using namespace Sorting;

int main(int argc, char** argv) {

	int *test = new int[1000000];
	int *ans = new int[1000000];
	srand(100);
	
	for(int i = 1; i < 1000000; (i<1000?i++:i+=100000))
	{
		for(int j = 0; j < i; j++)
		{
			test[j] = ans[j] = rand()*65536+rand();
		}
			
		sort(ans, ans + i);
		time_t t1 = clock();
		Quicksort(test, test + i);
		time_t t2 = clock();
		
		
		//for(int k = 0; k < i; k++)
		//	cout << test[k] << ' ' << ans[k] << endl;
		cout << "Time: " << t2 - t1 << endl;

		if(memcmp(test, ans, sizeof(int)*i) != 0)
		{
			cout << "Wrong! Test "<< i << endl;
			getch();
		}
		else
		{
			cout << "Good! Test " << i << endl;
		}
	}

	return 0;
}
