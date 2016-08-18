#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int n,num;
int a[300];
int period[300];
void initial() {
	int cnt;
	for(int i = 1; i <= n; i++ ) {
		int p = a[i];
		for(cnt = 1; p != i;cnt++, p = a[p]);
			period[i] = cnt;
	}

}

int main() {
	char str[222];
	while((cin >> n) && (n != 0)) {
		for(int i = 1; i <= n; i++) 
			cin>>a[i];
		initial();
		while(cin>>num && num !=0) {
			getchar();
			memset(str, ' ', sizeof(char)*(n+1));
			fgets(str+1,205, stdin);
			char temp[n+2];
			int len = strlen(str);
			str[len] = ' '; 
			str[--len] = ' ';

			for(int i = 1; i <= n; i++) {
				int cnt = num%period[i];
				int p;
				for(p = i; cnt; cnt--, p = a[p]);
				temp[p] = str[i];
			}
			temp[n+1] = '\0';


			strcpy(str, temp+1);
			cout<<str<<endl;
		}
		cout<<endl;
	}
	return 0;
}
