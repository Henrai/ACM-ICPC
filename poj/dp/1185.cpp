//State Compression DP

#include <iostream>
using namespace std;
char map[105][15];
int valid[105];
int state[66], count[66];
int n, m;
int num;
int dp[105][66][66];
void dfs(int depth, int stat, int cnt) {
	if(depth == m) {
		state[num] = stat;
		count[num] = cnt;
		num++;
		return;
	}
	dfs(depth+1, stat<<1, cnt);
	if(stat & 3) return;
	dfs(depth+1, (stat<<1)+1, cnt+1);
}

int main() {
	cin>>n >>m;
	for(int i = 0; i < n; i++) {
		cin>>map[i];
		for(int j = 0; j < m; j++)
			if(map[i][j] == 'H')
				valid[i] += 1<<j;
	}
	dfs(0,0,0);
	for(int i = 0; i < num; i++){
		if((state[i]&valid[0])==0)
			dp[0][i][0] = count[i];
	}
	for(int i = 0; i < n-1; i++) // line #
		for(int j = 0; j < num; j++)
			for(int k = 0; k < num; k++)
				for(int w = 0; w < num; w++)
					if((state[w] & valid[i+1]) == 0)
						if(((state[w] & state[j]) == 0) && ((state[w] & state[k]) == 0))
							dp[i+1][w][j] = max(dp[i+1][w][j], dp[i][j][k] + count[w]);
	int ans = 0;
	for(int i = 0; i < num; i++)
		for(int j = 0; j < num; j++)
			ans = max(ans, dp[n-1][i][j]);
	cout<<ans<<endl;
}