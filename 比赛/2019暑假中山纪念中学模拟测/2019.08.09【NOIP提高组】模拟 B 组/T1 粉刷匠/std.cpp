#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 50 + 10;
const int M = 50 + 10;
const int MAXT = 2500 + 10;

int n, m, T;
int c[M], f[M][M][2], g[MAXT];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read(), m = read(), T = read();
	/*
	f[i][j][k] -> ����ÿһ����˵����i����һ��ˢ��j�Σ���ɫΪk���������

	1.������һ������ˢ��ȥ
		f[i][j][c[i]] = f[i][j][c[i]] + 1
		f[i][j][!c[i]] = f[i][j][!c[i]]
	2.�ؿ�һ��ˢ��ȥ��
		2.1ˢͬɫ
			f[i][j][c[i]] = max(f[i][j][c[i]], max(f[i - 1][j - 1][0], f[i - 1][j - 1][1]) + 1)
		2.2ˢ��ɫ
			f[i][j][!c[i]] = max(f[i][j][!c[i]], max(f[i - 1][j - 1][0], f[i - 1][j - 1][1]))

	g[i] -> ����ÿһ����˵��ˢ��i���ܴﵽ���������

	g[i] = max(g[i], g[i - j] + max(f[n][i][0], f[n][i][1]))
	*/
	for(rgi l = 1; l <= n; ++l)
	{
		for(rgi i = 1; i <= m; ++i)
			scanf("%1d", &c[i]);
		memset(f, 0, sizeof(f));
		for(rgi i = 1; i <= m; ++i)
		{
			for(rgi j = 1; j <= i; ++j)
			{
				f[i][j][c[i]] = f[i - 1][j][c[i]] + 1;
				f[i][j][!c[i]] = f[i - 1][j][!c[i]];
				f[i][j][c[i]] = max(f[i][j][c[i]], max(f[i - 1][j - 1][0], f[i - 1][j - 1][1]) + 1);
				f[i][j][!c[i]] = max(f[i][j][!c[i]], max(f[i - 1][j - 1][0], f[i - 1][j - 1][1]));
			}
		}
		for(rgi i = T; i >= 0; --i)
			for(rgi j = 1; j <= min(i, m); ++j)
				g[i] = max(g[i], g[i - j] + max(f[m][j][0], f[m][j][1]));
	}
	printf("%d", g[T]);
	return 0;
}

