#include <iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	while(n) {
		int d,i;
		cin>>d>>i;
		int ans =1;
		d--;
		while(d) {
			ans = (ans<<1)|(!(i%2));
			i= (i+1)>>1;
			d--;
		}
		cout<<ans<<endl;
		n--;
	}
}