#include <iostream>
#include <cstring>
using namespace std;

#define MOD 1000000

int C[300][300];

int main() {
	memset(C, 0, sizeof(C));
	for(int i = 0; i <= 200; i++)
		C[i][0] = 1;
	for(int i = 0; i <= 200; i++)
		for(int j = 1; j <= i; j++) {
			//cout<<i<<" "<<j<<C[i-1][j-1] << " "<< C[i][j-1]<<endl;
			C[i][j] = (C[i-1][j-1]+C[i-1][j]) % MOD;
		}
	int a,b;
	while(cin>>a>>b) {
		if(a == 0 && b == 0)
			break;
		else cout<<C[a+b-1][b-1]<<endl;
	}
}