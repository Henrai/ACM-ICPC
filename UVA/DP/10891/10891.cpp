#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int a[120];
int sum[120];
int dp[120][120];
int n;

int main() {
	while(cin>>n){
		if(n == 0)
			break;

		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= n; j++)
				dp[i][j] = -2000000000;
		for(int i=1; i <= n; i++) {
			cin>>a[i];
			sum[i] = sum[i-1] + a[i];
			dp[i][i] = a[i];
		}
		
		for(int len = 2; len <= n; len++)
			for(int j = 1; j + len -1 <= n; j++) {
				for(int k = j; k < j + len -1; k++) {
					int w = j + len - 1;
					dp[j][w] = max(dp[j][w], sum[w] - sum[j-1] - min(dp[j][k], dp[k+1][w]));
				}
				dp[j][j+len-1] = max(dp[j][j+len-1], sum[j+len-1] - sum[j-1]);
			}


		cout<<2*dp[1][n] - sum[n]<<endl;
	}
}