#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
int main() {
	int n;
	int num;
	int a[55];
	int dp[55][55];
	while(cin >> n) {
		if(n == 0)
			break;
		cin >> num;
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= num; i++)
			cin>>a[i];
		a[0] = 0;
		a[num+1] = n;
		for(int l = 2; l <= num+1; l++) {
			for(int i = 0; i+l <= num+1; i++) {
				
				int j = i+l;
				dp[i][j] = 0x70000000;
				for(int k = i+1; k < j; k++) {
					int cost = dp[i][k] + dp[k][j] + a[j] - a[i];
					if(cost < dp[i][j])
						dp[i][j] = cost;
				}
			}
		}
		cout<<"The minimum cutting is ";
        cout<<dp[0][num+1]<<"."<<endl;
	}
}