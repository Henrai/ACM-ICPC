// Anze Wang

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>

int maze[300][300];
int mark[300][300];

int right[3][3] = {1,0,0,0,1,0,0,0,1};
int left[3][3] = {0,0,1,0,1,0,1,0,0};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
char c;
int n,m;
int ans, maxlen;

void fill(bool slash, int row, int col) {
	if(slash) {
		for(int i = 0; i < 3; i++ )
			for(int j = 0; j < 3; j++)
				maze[row+i][col+j] = right[i][j];
	}
	else {
		for(int i = 0; i < 3; i++ )
			for(int j = 0; j < 3; j++)
				maze[row+i][col+j] = left[i][j];	
	}
}

bool check(int i, int j) {
	if(0<= i && i <= 3*m + 1 && 0 <= j && j <= 3*n + 1) {
		if(maze[i][j] == 1 || mark [i][j] != 0)
			return false;
		else
			return true;
	}
	else 
		return false;
}

void flood(int x, int y, int color, int& count) {
	mark[x][y] = color;
	count++;
	for(int k = 0; k < 4; k++) {
		if(check(x+dx[k], y+dy[k])){
			flood(x+dx[k], y+dy[k], color, count);
		}
	}
}

int main() {
	int nums = 0;
	while(std::cin>>n>>m) {
		ans = 0;
		maxlen = 0;
		if(!n) break;
		printf("Maze #%d:\n",++nums);
		memset(maze, -1, sizeof(maze));
		memset(mark, 0, sizeof(mark));

		for(int i = 1; i <= m; i++)
			for(int j = 1; j <= n; j++) {
				std::cin>>c;
				if(c == '/') {
					fill(false, (i-1)*3+1, (j-1)*3+1); 
				}
				else {
					fill(true, (i-1)*3+1, (j-1)*3+1);
				}
			}
		int temp;
		flood(0,0,-1,temp);
		for(int i = 1; i <= m*3; i++) {
			for(int j = 1; j <= n*3; j++) {
				if(maze[i][j] != 1 && mark[i][j] == 0) {
					int count = 0;
					flood(i,j,++ans, count);
					if(count/3 > maxlen)
					maxlen = count/3;
				}

			}
		}

		
    	if(ans == 0)
    		printf("There are no cycles.\n\n");
    	else {
    		printf("%d Cycles; the longest has length %d.\n\n", ans, maxlen);
    	}
	}
    
	return 0;
}
