#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LL long long
LL f[10000001];
int E,Es,Ef;
inline double min(double a, double b) {
	return a < b ? a : b;
}
int main() {
	while(scanf("%d%d%d", &E, &Es, &Ef) != EOF) {
		//memset(f, 0, sizeof(f));
		for(int i = 1; i <= E; i++) {
			f[i] = 1;
			if(i > Es)
				f[i] += f[i - Es];
			if(i > Ef)
				f[i] += f[i - Ef];
			if(f[i] >= 400000000l)
				f[i] = 400000000l;
		}
		printf("%.6lf\n", min(200.0/f[E], 225.0/(f[E]+1)));
	}
}