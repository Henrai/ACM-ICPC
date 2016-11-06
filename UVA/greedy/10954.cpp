// Anze Wang

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

//int num[10000];

int main() {
	int n;
	while(cin>>n) {
		priority_queue<long long,std::vector<long>, std::greater<> > q;
		long long ans = 0;
		if(n == 0) break;
		long long num;

		for(int i = 0; i < n; i++) {
			cin>>num;
			q.push(num);
		}
		
		while(true) {
			long long a = q.top();
			q.pop();
			long long b = q.top();
			q.pop();
			ans += a+b;
			cout <<a<<" "<<b<<" "<<ans<<endl;
			if(q.empty()) break;
			q.push(a+b);
		}

		cout<<ans<<endl;
	}
	return 0;
}
