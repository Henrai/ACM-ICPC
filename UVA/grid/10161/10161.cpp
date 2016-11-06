#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
	int number;
	while(cin >> number) {
		if(number == 0)
			break;
		int n = sqrt(number);
		int k = number - n*n;
		if(k == 0) {
			if(n & 1 ) {
				cout<<"1 "<<n<<endl;
				continue;
			}
			else {
				cout<< n <<" 1\n";
				continue;
			}
		}
		else {
			if(n & 1) {
				if(k <= n + 1) {
					cout<<k<<" "<<n+1<<endl;
				}
				else {
					cout<<n+1<<" "<<2*n+2-k<<endl;
				}
			}
			else {
				if(k <= n + 1) {
					cout<<n+1<<" "<<k<<endl;
				}
				else {
					cout<<2*n+2-k<<" "<<n+1<<endl;
				}
			}
		}
	}
}