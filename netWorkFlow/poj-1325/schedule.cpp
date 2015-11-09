#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <queue>

#define MAX 100000
#define INF 0x7f7f7f7f

using namespace std;
int head[MAX],dis[MAX],cnt;
int n,m,k;
queue<int> q;
struct Edge {
	int to;
	int next;
	int f;
}g[MAX];

void addEdge(int from, int to, int f) {
	g[cnt].f = f;
	g[cnt].next=head[from];
	head[from] = cnt;
	g[cnt].to = to;
	cnt++;
}

int BFS() {
	memset(dis,0,sizeof(dis));
	q.push(0);
	dis[0] = 1;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for(int i = head[temp]; i; i = g[i].next) {
			if(dis[g[i].to] == 0 && g[i].f > 0) {
				q.push(g[i].to);
				dis[g[i].to] = dis[temp] +1;
			}
		}
	}
}

int DFS(int u, int change) {
	int ans = 0;
	if(u == n+m+1) return change;
	for(int i = head[u]; i; i = g[i].next) {
		if(g[i].f != 0 && dis[g[i].to] == dis[u] +1) {
			int delta = DFS(g[i].to, min(g[i].f, change));
			change -= delta;
			g[i].f -= delta;
			g[i^1].f += delta;
			ans += delta;
		}
	}
	return ans;
}

int Dinic() {
	int t = 0;
	while(true) {
		BFS();
		if(dis[n+m+1] != 0)
			t += DFS(0,INF);
		else return t;
	}
}
int main(){
	cin>>n;
	while(n != 0){
		cin>>m>>k;
		cnt = 0;
		memset(head,0,sizeof(head));
		for(int i = 1; i <= n; i++) {
			addEdge(0, i, 1);
			addEdge(i, 0, 0);
		}	
		for (int i = n+1; i <= n+m; i++) {
			addEdge(i, m+n+1, 1);
			addEdge(m+n+1, i, 0);
		}
		for (int i = 0; i < k ; i++) {
			int k1,k2,k3;
			cin>>k1>>k2>>k3;
			if(k2*k3 == 0)continue;
			k1++;
			k2++;
			addEdge(k2, k3+n, 1);
			addEdge(k3+n, k2, 0);
		}
		cout<<Dinic()<<endl;
		cin>>n;
	}
}