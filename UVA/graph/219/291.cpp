#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int edge[8] = {0};
int head[10], cnt = 0;
vector<string> ans;
struct Edge {
    int to;
    int next;
    int index;
}g[20];



void addEdge(int from, int to, int ind) {
    g[cnt].index = ind;
    g[cnt].next = head[from];
    head[from] = cnt;
    g[cnt].to = to;
    cnt++;
}

void dfs(string s, int vis, int curr) {
    if(vis == 8) {
        ans.push_back(s);
        return ;
    }
    else {
        for(int k = head[curr]; k != -1 ; k = g[k].next) {
            if(!edge[g[k].index]) {
                edge[g[k].index] = 1;
                char c =g[k].to+'0'; 
                dfs(s + c, vis+1, g[k].to);
                edge[g[k].index] = 0;
            }
        }
    }
}

int main()
{
    for(int i = 1; i <= 8; i++)
        head[i] = -1;

    addEdge(1, 2, 1); addEdge(2, 1, 1);
    addEdge(2, 3, 2); addEdge(3, 2, 2);
    addEdge(3, 4, 3); addEdge(4, 3, 3);
    addEdge(4, 5, 4); addEdge(5, 4, 4);
    addEdge(5, 1, 5); addEdge(1, 5, 5);
    addEdge(5, 3, 6); addEdge(3, 5, 6);
    addEdge(3, 1, 7); addEdge(1, 3, 7);
    addEdge(5, 2, 8); addEdge(2, 5, 8);
   dfs("1", 0, 1);
   sort(ans.begin(), ans.end());
   for(int i = 0; i < ans.size(); i++)
        cout<<ans[i]<<endl;
}
