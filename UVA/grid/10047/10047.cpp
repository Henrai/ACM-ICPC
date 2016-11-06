#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

struct Node {
	int x,y;
	int dir;
	int color;	
	int time;
	Node(int xx, int yy, int d, \
		 int c, int t):x(xx), y(yy), dir(d),color(c),time(t) {}
};

int vis[30][30][10][10];
bool map[30][30];
int dy[5] = {0, -1, 0, 1};
int dx[5] = {-1, 0, 1, 0};
int m, n;
int sx, sy, tx, ty;


inline bool check(int x, int y) {
	return 0 <= x && x < m && 0 <= y && y < n;
}

int bfs() {
	memset(vis, 0, sizeof(vis));
	int ans = -1;
	queue<Node> q;
	q.push(Node(sx,sy,0,0,0));
	while(!q.empty()) {
		Node top = q.front();
		q.pop();
		vis[top.x][top.y][top.color][top.dir] = true;
		if(top.x == tx && top.y == ty && top.color == 0) {
			ans = top.time;
			break;
		}
		if(vis[top.x][top.y][top.color][(top.dir+1)%4] == false)
			q.push(Node(top.x, top.y, (top.dir+1)%4, top.color, top.time +1));
		if(vis[top.x][top.y][top.color][(top.dir+3)%4] == false)
			q.push(Node(top.x, top.y, (top.dir+3)%4, top.color, top.time +1));
		int newx = top.x + dx[top.dir], newy = top.y + dy[top.dir];
		//cout<<newx<<" "<<newy<<endl;
		if(  check(newx, newy) && map[newx][newy] && vis[newx][newy][(top.color + 1)%5][top.dir] == false ) {
			q.push(Node(newx, newy, top.dir, (top.color + 1)%5, top.time +1));
		}
	}
	return ans;
}

int main() {
	char c;
	int count = 1;

	while (cin>>m>>n) {
		if(m + n == 0) break;
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++) {
				cin>>c;
				if(c == '.')
					map[i][j] = 1;
				else if(c == '#')
					map[i][j] = 0;
				else if(c == 'S') {
					sx = i, sy = j;
					map[i][j] = 1;
				}
				else if(c == 'T') {
					tx = i, ty = j;
					map[i][j] = 1;
				}
			}
		if(count != 1) cout<<endl;
		cout<<"Case #"<<count<<endl;
		int ans = bfs();
		if(ans == -1)
			cout<<"destination not reachable\n";
		else 
			cout<<"minimum time = " << ans << " sec\n";
		count++;
	}
}