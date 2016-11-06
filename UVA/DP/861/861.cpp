// Anze Wang

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int dp1[100][100];
int dp2[100][100];
int grid1[100];
int grid2[100];
int n, k;

void work(int n, int dp[100][100], int* grid) {
	for(int i = 0; i <= n; i++)
		dp[i][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= k && j <= grid[i] ; j++) 
			dp[i][j] += dp[i-1][j] + dp[i-1][j-1]*(grid[i] - j + 1);
}

int main() {
	
	while(cin>>n>>k) {
		if(n+k == 0) break;
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		memset(grid1, 0, sizeof(grid1));
		memset(grid2, 0, sizeof(grid2));
		for(int i =1, j = 1; i <= n/2; i++) {
			grid1[i] = j; grid1[n-i+1] = j;
			if(i < n/2)
				j +=2;
			else
				j -= 2; 
			
		}
		for(int i =1, j = 2; i <= (n-1)/2; i++) {
			grid2[i] = j; grid2[n-i] = j;
			if(i < (n-1)/2 )
				j+=2;
			else
				j-= 2; 
			
		}
		if(n&1) 
			grid1[n/2+1] = n;
		else
			grid2[(n-1)/2+1] = n;

		sort(grid1+1, grid1+n+1);	
		sort(grid2+1, grid2+n);
		
		long long ans = 0;
		work(n, dp1, grid1);
		work(n-1, dp2, grid2);
		for(int i = 0; i <= k; i++)
			ans += dp1[n][i]*dp2[n-1][k-i];
		cout<<ans<<endl;
	}
	return 0;
}