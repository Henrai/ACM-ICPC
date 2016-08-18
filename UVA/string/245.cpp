#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

vector<string> a;
int top = 0;
inline bool isLetter(char c) {
	return ((c >= 'A') && (c <= 'Z' )) || ((c >= 'a' && c <= 'z'));
}
inline bool isDigit(char c) {
	return (c >= '0') && (c <= '9');
}

int main() {
	char c;

	int number = 0;
	c = getchar();
	while(true) {
		if(isDigit(c)) {
			if(c == '0') break;
			while (isDigit(c)) {
				number = 10*number + c -'0';
				c = getchar();
			}
			int k = top - number;
			string temp = a[k];
			
			cout<<a[k];
			a.erase(a.begin() + k);
			a.push_back(temp);
			number = 0;
		}
		else if(isLetter(c)) {
			string word = "";
			while(isLetter(c)) {
				word += c;
				c = getchar();
			}
			a.push_back(word);
			top++;
			cout<<word;		
		}
		else {
			cout<<c;
			c = getchar();
		}
	}

}