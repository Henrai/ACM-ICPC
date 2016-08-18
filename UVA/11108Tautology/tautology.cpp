#include <iostream>
#include <stack>
using namespace std;

int main()
{
	string wwf;
	//int a[5]; // p,q,r,s,t
	stack<int> sck;
	while (cin >> wwf){
		if(wwf == "0")
			break;
		int flag = 0;
		for(int i = 0; i < 32; i++)
		{
			while(!sck.empty())
				sck.pop();
			
			for(int j = wwf.length()-1; j >= 0 ; j--){
				int a = 0, b = 0;
				switch(wwf[j])
				{
					case 'p': sck.push((i >> 0) & 1); break;
					case 'q': sck.push((i >> 1) & 1); break;
					case 'r': sck.push((i >> 2) & 1); break;
					case 's': sck.push((i >> 3) & 1); break;
					case 't': sck.push((i >> 4) & 1); break;
					case 'A': a = sck.top(); sck.pop(); b = sck.top(); sck.pop(); sck.push(a | b);  break;
					case 'K': a = sck.top(); sck.pop(); b = sck.top(); sck.pop(); sck.push(a & b); break;
					case 'N': a = sck.top(); sck.pop(); sck.push(!a); break;
					case 'C': a = sck.top(); sck.pop(); b = sck.top(); sck.pop(); sck.push(b >= a); break;
					case 'E': a = sck.top(); sck.pop(); b = sck.top(); sck.pop(); sck.push(a == b); break;
				}
				//cout<<sck.top()<<endl;
			}
			if(sck.top() == 0)
			{
				//cout<<wwf<<endl;
				flag = 1;
				break;
			}
			//cout<<"-------------------\n";
		}
		if(flag)
			cout<<"not\n";
		else 
			cout<<"tautology\n";
	}
	return 0;
}