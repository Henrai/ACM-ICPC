#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main() {
	freopen("test.txt", "w",stdout);
	srand(time(0));
	int n = rand()%20 + 1;
	cout<<n<<endl;
	for(int i = 1; i <= n; i++) {
		int k = rand()%500 + 1;
		int m = rand()%500 + 1;
		cout<<k << " "<<m<<endl;
		for(int j = 0; j < k; j++)
			cout<< rand()%10000000 + 1<<" ";
		cout<<endl;
	}
}