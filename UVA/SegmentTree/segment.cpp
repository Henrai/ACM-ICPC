#include <iostream>
using namespace std;

#define N 1024000
#define lson(x) ((x)<<1)
#define rson(x) (((x)<<1)|1) 

class Node {
public:
	int l,r,lazy,value;
}tree[(N<<2)+1];
int pirates[N+1];
int build(int l, int r, int x = 1) {
	tree[x].l = l; tree[x].r = r;
	tree[x].lazy = 0;
	if(l == r) {
		tree[x].value = pirates[l];
		return tree[x].value;
	}
	int mid = l + ((r-l)>>1);
	tree[x].value = build(l, mid, lson(x)) + build(mid+1, r, rson(x));
	return tree[x].value;
}

void init(){
	int num, t;
	string s;
	cin>>num;
	int plen = 0;
	for(int i = 0; i < num; i++) {
		cin>>t>>s;
		int len = s.length();
		while(t--) {
			for(int j = 0; j < len; j++) 
				pirates[plen++] = s[j] - '0';
		}
	}
	build(0, plen - 1);
}

int getOp(int a, int b) {
	if(a == 3 && b == 3) return 0;
	if(a == 3 && b == 2) return 1;
	if(a == 3 && b == 1) return 2;
	if(a == 3 && b == 0) return 3;
	if(a == 2) return 2;
	if(a == 1) return 1;
	return 0;
}

void pushdown(int x) {
	if(tree[x].lazy) {
		tree[lson(x)].lazy = getOp(tree[x].lazy, tree[lson(x)].lazy);
		int len = tree[lson(x)].r - tree[lson(x)].l + 1;
		if(tree[x].lazy == 1) tree[lson(x)].value = len;
		if(tree[x].lazy == 2) tree[lson(x)].value = 0;
		if(tree[x].lazy == 3) tree[lson(x)].value = len - tree[lson(x)].value;
		tree[rson(x)].lazy = getOp(tree[x].lazy, tree[rson(x)].lazy);
		len = tree[rson(x)].r - tree[rson(x)].l + 1;
		if(tree[x].lazy == 1) tree[rson(x)].value = len;
		if(tree[x].lazy == 2) tree[rson(x)].value = 0;
		if(tree[x].lazy == 3) tree[rson(x)].value = len - tree[rson(x)].value;
		tree[x].lazy = 0;
	}
}

void update(int l, int r, int op, int x = 1) {
	if(r < tree[x].l || tree[x].r < l) return;
	if(l <= tree[x].l && tree[x].r <= r ) {
		tree[x].lazy = getOp(op, tree[x].lazy);
		int len = tree[x].r - tree[x].l + 1;
		if(op == 1) 
			tree[x].value = len;
		else if(op == 2)
			tree[x].value = 0;
		else
			tree[x].value = len - tree[x].value;
		return ;  
	}
	pushdown(x);
	int mid = tree[x].l + ((tree[x].r - tree[x].l)>>1);
	if(l <= mid) update(l, r, op, lson(x));
	if(mid < r) update(l, r, op, rson(x));
	tree[x].value = tree[lson(x)].value + tree[rson(x)].value;
}
int query(int l, int r, int x = 1) {
	if(r < tree[x].l || tree[x].r < l) return 0;
	if(l <= tree[x].l && tree[x].r <= r) {
		return tree[x].value;
	}
	int mid =  tree[x].l + ((tree[x].r - tree[x].l)>>1);
	int ans = 0;
	pushdown(x);
	if(l <= mid) ans += query(l, r, lson(x));
	if(mid < r) ans += query(l, r, rson(x));
	return ans;
}

int main() {
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++) {
		cout<<"Case "<<i<<":\n";
		init();
		int num;
		int qnum = 0;
		string q;
		int a,b;
		cin>>num;
		while(num--) {
			cin>>q>>a>>b;
			if (q == "F") {
				update(a, b, 1);
			}
			if (q == "E") update(a, b, 2);
			if (q == "I") update(a, b, 3);
			if (q == "S") cout<<"Q"<<++qnum<<": "<<query(a, b)<<endl;
		}
	}
}
