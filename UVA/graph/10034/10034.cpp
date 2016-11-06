#include <iostream>
#include <cmath>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

double pointx[111];
double pointy[111];
int root[111];

struct Edge
{
	int from, to;
	double weight;
	Edge(int f, int t, double w) : from(f), to(t), weight(w) {}
	bool operator<(const Edge& e ) const {
		return weight < e.weight;
	}
	Edge(){}
}edge[10101];

int getRoot(int x) {
	if(root[x] != x){
		root[x] = getRoot(root[x]);
	}
	return root[x];
}

int main() {
	int num;
	int t = 0;
	cin>>num;
	while(num != t) {
		int n;
		if(t)
			printf("\n");
		cin>>n;
		for(int i = 1; i <= n; i++) {
			root[i] = i;
			cin>>pointx[i]>>pointy[i];
		}
		int index = 0;
		for(int i = 1; i <= n; i++) 
			for(int j = 1; j <= n; j++) {
				if(i != j) {
					double len = sqrt( (pointx[i] - pointx[j]) * (pointx[i] - pointx[j]) + (pointy[i] - pointy[j]) * (pointy[i] - pointy[j]));
					edge[index] = Edge(i, j, len);
					index++;z
				}
		}
		sort(edge+1, edge+index);
		int count = 0;
		double ans = 0.0;
		int i = 1;
		while(count < n-1 && i < index) {
			Edge e = edge[i];
			i++;
			int a = getRoot(e.from);
			int b = getRoot(e.to);

			if(a != b) {
				count++;
				ans += e.weight;
				root[b] = a;
			}

		}
		//cout<<"kruskul"<<endl;
		printf("%.2f\n",ans);
		t++;
	}
}