#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <cstdlib>
using namespace std;

int h, w;
bool isPossible;
int count;
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, -1, 1, 1, -1};

struct Point {
	int x,y;
	Point(int xx, int yy):x(xx), y(yy) {}
};

struct Node
{
	int x,y,depth;
	Node(int xx, int yy, int dd): x(xx), y(yy), depth(dd){}
 };

vector<Point> a;

char graph[55][55];
char grapha[55][55];
int dis[15][15];
int index[55][55];
vector<int> state[12][12];

inline int getNumber(int i, int j) {
	return i * w + j;
}

inline bool check(int x, int y) {
	return 0 <= x && x < h && 0 <= y && y < w;
}

inline int lowbit(int x) {
	return x &(-x);
}

void bfs(int x, int y) {
	bool visit[50][50] = {false};
	visit[x][y] = true;
	queue<Node> q;
	q.push(Node(x,y,0));
	while(!q.empty()) {
		Node top = q.front();
		q.pop();
		visit[top.x][top.y] = true;
		for(int i = 0; i < 4; i++) {
			int m = top.x + dx[i], n = top.y + dy[i];
			if(check(m, n) && visit[m][n] == false && grapha[m][n] != '#') {
				
				if(grapha[m][n] == '!') {
					dis[index[m][n]][index[x][y]] = top.depth + 1;
					dis[index[x][y]][index[m][n]] = top.depth + 1;
				}
				q.push(Node(m, n, top.depth+1));
				visit[m][n] = true;
			}
		}

	}
}

void dfs(int bits, int depth, int sta) {
	if(depth > 11) return;
	else state[depth][bits].push_back(sta);
	dfs(bits, depth+1, sta);
	dfs(bits + 1, depth + 1, (1<<depth)|sta);
}

int countIndex(int x) {
	int n = 1;
	while(!(x & 1)) {
		n++;
		x = x>>1;
	}
	return n;
}

int main() {
	dfs(1,1,1);

	while(cin>>h>>w) {
		getchar();
		if( h+w == 0) break;
		isPossible = true;
		count = 1;
		a.clear();
		for( int i = 0; i < h; i++) {
			cin.getline(graph[i], 55);
		}
		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++) {
				grapha[i][j] = graph[i][j];
			}
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) {
				switch(graph[i][j]) {
					case '@': a.push_back(Point(i,j)); break;
					case '~': grapha[i][j] = '#';
					case '#': break;
					case '*': 
						grapha[i][j] = '#';
						for(int k = 0; k < 8; k++) {
							int x = i + dx[k], y = j + dy[k];
							if(check(x, y)) {
								if(graph[x][y] == '!' || graph[x][y] == '@')
									isPossible = false;
								grapha[x][y] = '#';
							}
						}
					break;
				}
			}
		}
		if(!isPossible) {
			cout<<"-1"<<endl;
			continue;
		}
		for( int i = 0; i < h; i++)
			for( int j = 0; j < w; j++) {
				if(grapha[i][j] == '@') {
					grapha[i][j] = '!';
					index[i][j] = 1;
				}
				else if(grapha[i][j] == '!') {
					count++;
					index[i][j] = count;
					a.push_back(Point(i, j));	
				}
			}
		if(count == 1) {
			cout<<0<<endl;
			continue;
		}
		for(int i = 1; i <= count; i++)
			for(int j = 1; j <= count; j++) {
				i==j? dis[i][j]= 0 : dis[i][j] = -1;
			}
		for(int i = 0; i < count; i++)
			bfs(a[i].x, a[i].y);
		int dp[12][1<<count];
		for(int i = 1; i <= count; i++)
			for(int j = 1; j <= (1<<count); j++)
				dp[i][j] = 0xfffffff;
		for(int i = 1; i <= count; i++) {
			if(!isPossible) break;
			for(int j = i+1; j <= count; j++)
				if(dis[i][j] == -1) {
					isPossible = false;
					break;
				}
		}
		if(!isPossible) {
			cout<<-1<<endl;
			continue;
		}
		
		dp[1][1] = 0;
		for(int i = 2; i <= count; i++) {
			for(int s = 0; s < state[count][i].size(); s++) {
				int j = state[count][i][s];
				for(int t1 = j, k = lowbit(t1); t1; t1 = t1 - k, k = lowbit(t1)) {
					if(k == 1) continue;
					for(int t2 = j - k, w = lowbit(t2); t2;  t2 -= w, w = lowbit(t2)) {
						int x = countIndex(k), y = countIndex(w);
						dp[x][j] = min(dp[x][j], dp[y][j-k] + dis[x][y]);

					}
				}
			}
		}
		

		int ans = 0xfffffff;
		for(int j = 2; j <= count; j++) {
			ans = min(ans, dp[j][(1<<count)-1] +dis[j][1]);
		}
		if(ans >= 0xfffffff) cout<<-1<<endl;
		else cout<<ans<<endl;
	}

}

