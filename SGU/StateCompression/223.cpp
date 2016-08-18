#include <iostream>
using namespace std;

int state[1<<10], count[1<<10];
int num,n,k;
long long dp[11][1<<10][111];

void dfs(int depth, int stat, int cnt) {
	if(depth == n) {
		state[num] = stat;
		count[num] = cnt;
		num++;
		return;
	}
	dfs(depth+1, stat<<1, cnt);
	if(stat&1) return;
	dfs(depth+1, (stat<<1)|1, cnt+1);
}

inline bool check(int i, int j) {
	return ( (state[i] & state[j]) == 0) && ( ((state[i] << 1) & state[j]) == 0) && (((state[i] >> 1) & state[j]) == 0);
}

int main() {
	cin>>n>>k;
	dfs(0, 0, 0);
	for(int i = 0; i < num; i++)
		dp[0][state[i]][count[i]] = 1;
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < num; j++) {// state of i
			for(int v = count[j]; v <= k; v++) { // # of kings in first i line
				for(int w = 0; w < num; w++) // state of i-1 
					if(check(j, w)) {
						dp[i][state[j]][v] += dp[i-1][state[w]][v - count[j]];
					}
			}
		}
	}
	long long ans = 0;
	for(int i = 0; i < num; i++)
		ans += dp[n-1][state[i]][k];
	cout<<ans<<endl;
}