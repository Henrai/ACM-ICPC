#include <iostream>
using namespace std;
struct Node {
	int up, down;
	Node(int u, int d) {
		up = u;
		down =d;
	}
};
bool isless(Node a, Node b) {
	return a.up*b.down < b.up*a.down;
}
bool equal(Node a, Node b) {
	return (a.up == b.up) && (a.down == b.down);
}
int main() {
	int m,n;
	while(cin>>m>>n) {
		string ans = "";
		if(m * n == 1) {
			break;
		}
		Node dest(m,n);
		Node mid(1,1);
		Node left(0,1);
		Node right(1,0);
		while(!equal(dest, mid)){
			if(isless(dest, mid)) {
				ans += "L";
				right = mid;
				mid.up += left.up;
				mid.down += left.down;
			}
			else {
				ans += "R";
				left = mid;
				mid.up += right.up;
				mid.down += right.down;
			}
		}
		cout<<ans <<endl;
	}
}