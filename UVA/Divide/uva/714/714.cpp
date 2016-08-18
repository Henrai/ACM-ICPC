#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
LL nums[550];
LL k,m, sum, minv;
bool ans[550];
void init() {
	sum = 0;
	minv = 0x7fffffff;
	cin >> k >> m;
	for(int i = 0; i < k; i++){
		cin>>nums[i];
		sum += nums[i];
		if(minv > nums[i])
			minv = nums[i];
	}
}
int check(LL mid) {
	memset(ans, 0, sizeof(ans));
	LL temps = 0, cnt = 0;
	int i = k-1;
	while (i >= 0) {
		if (nums[i] > mid)
			return 1;
		temps = 0;
		while(i >= 0 && temps + nums[i] <= mid) {
			temps += nums[i];
			i--;
		}

		if(i >= 0) {
			ans[i] = true; 
		}
		cnt++;
	}
	return cnt - m;
}
LL work() {
	LL lo = minv;
	LL hi = sum;
	while(lo < hi) {
		LL mid = lo + ((hi - lo) >> 1);
		int result = check(mid);
		if(result <=  0) hi = mid;
		else lo = mid+1; 
	}
	return lo;
}
int output(LL a) {
	int cnt = check(a);
	for(int i = 0; i < k && cnt < 0; i++) {
		if(!ans[i]) {
			cnt++;
			ans[i] = true;
		}
	}
	for(int i = 0; i < k; i++) {
		if(i == k -1) {
			cout<<nums[i];
			break;
		}
		cout<<nums[i]<<" ";
		if(ans[i]) {
			cout<<"/ ";
		}
	}
	cout<<endl;
}
int main() {
	int n;
	cin>>n;
	while(n) {
		init();
		int a = work();
		output(a);
		n--;
	}
}
