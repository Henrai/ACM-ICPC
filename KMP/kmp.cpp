#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;

vector<int> getNext(string s) {
    vector<int> next;
    int len = s.length();
    next.push_back(0);
    int j = 0;
    for(int i = 1; i < len; i++) {
    	while((j > 0) && (s[j] != s[i])) j = next[j];
    	if(s[j] == s[i]) j++;
    	next.push_back(j);
    }
    return next;
}


bool kmp(string a, string b, const vector<int>& next) {
	int j = 0;
	int len = a.length();
	for(int i = 0; i < len; i++) {
		while((j > 0) &&(a[i] != b[j])) j = next[j];
		if(a[i] == b[j]) j++;
		if(j == b.length()) {
			return true;
		}
	}
	return false;
} 

int main() {
	clock_t start, finish;
	ifstream fin("test.txt");
	ofstream fout("ans.txt");
	vector<string> strs;
	string s;
	while(fin>>s) {
		strs.push_back(s);
	}
	string key;
	cin>>key;
	start = clock();
	vector<int> next = getNext(key);
	for(auto i : strs) {
		if(kmp(i, key, next))
			fout<<i<<endl;
	}
	finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout<<duration<<" seconds\n";
}