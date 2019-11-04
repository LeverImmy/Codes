#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 200010

using namespace std;

int n, m, lg2[maxn] = { -1, 0}, a[maxn];
int f[maxn][50];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x)
{
	if(x < 0)    putchar('-'), x = -x;
	if(x > 9)    write(x / 10);
	putchar(x % 10 + 48);
}

int query(int l, int r)
{
	int len = lg2[r - l + 1];
	return max(f[l][len], f[r - (1 << len) + 1][len]);
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		a[i] = read();
		lg2[i] = lg2[i >> 1] + 1;
		f[i][0] = a[i];
	}
	for(rgi j = 1; j <= lg2[n]; ++j)
		for(rgi i = 1; i + (1 << j) - 1 <= n; ++i)
			f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
	m = read();
	for(rgi i = 1; i <= m; ++i)
	{
		int l = read(), r = read();
		printf("%d\n", query(l, r));
	}
	return 0;
}

