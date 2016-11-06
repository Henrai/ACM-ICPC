#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main() {
	freopen("test.txt", "w",stdout);
	srand(time(0));
	for(int i = 1; i <= 500000; i++) {
		int len = (rand()%100);
		string s = "";
		if(len% 9 == 0) s = "abc";
		for(int j = 0; j < len; j++) {

			s += (char) ((rand()%26) +'a');
		}
		cout<<s<<endl;
	}
}
