#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 5e4 + 10;

int n, m1, m2;
int point1 = 1, point2 = 1;
int h[N], f1[N], f2[N], tmp[N], up[N], down[N];
int len1, len2, start1, start2, ans;
	
//lower_bound <
//upper_bound <=

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
//	freopen("robot.in", "r", stdin);
//	freopen("robot.out", "w", stdout);
	n = read(), m1 = read(), m2 = read();
	for(rgi i = 1; i <= n; ++i)	h[i] = read();

	f1[1] = h[1], len1 = 1, start1 = 1;
	for(rgi i = 2; i <= n; ++i) {//up
		if(h[i] >= f1[len1])
			f1[++len1] = h[i];
		else {
			int pos = upper_bound(f1 + 1, f1 + len1 + 1, h[i]) - (f1 + 1);
			if(pos == 0)	start1 = i;
			f1[pos + 1] = h[i];
		}
	}
//	printf("%d\n", len1);
	
	for(rgi i = 1; i <= n; ++i) tmp[i] = h[n - i + 1];
	f2[1] = tmp[1], len2 = 1, start2 = 1;
	for(rgi i = 2; i <= n; ++i) {//down
		if(tmp[i] >= f2[len2])
			f2[++len2] = tmp[i];
		else {
			int pos = upper_bound(f2 + 1, f2 + len2 + 1, tmp[i]) - (f2 + 1);
			if(pos == 0)	start2 = i;
			f2[pos + 1] = tmp[i];
		}
	}
//	printf("%d\n", len2);
	
	for(rgi i = 1; i <= len2; ++i) tmp[i] = f2[i];
	for(rgi i = 1; i <= len2; ++i) f2[i] = tmp[len2 - i + 1];
	
	
	
	if(len1 >= len2) {//up
		for(rgi i = 1; i <= n; ++i) {
			if(h[i] < up[start1])
				ans += m1;
			else if(h[i] > up[start1])
				ans += m2;
			else
				start1++;
		}
	}
	else {//down
		for(rgi i = 1; i <= n; ++i) {
			if(h[i] < down[start2])
				ans += m1;
			else if(h[i] > down[start2])
				ans += m2;
			else
				start2++;
		}
	}
	
	printf("%d", ans);
	return 0;
}
/*
10 1 1
2 1 1 1 2 2 2 2 2 2

15 5 7
10 10 10 10 10 9 2 8 7 6 1000 5 3 4 1

15 5 7
1 4 3 5 1000 6 7 8 2 9 10 10 10 10 10

5 2 3
1 2 3 5 4

5 1 1
100 1 2 3 4

*/
