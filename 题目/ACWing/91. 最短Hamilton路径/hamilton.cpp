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

using namespace std;

int n;
int e[20][20], f[1 << 20][20]; //f[i][j]��ʾ���ڵĶ�������Ϊi����ǰ��Ϊj�����·��

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read();
	for(rgi i = 0; i < n; ++i)
		for(rgi j = 0; j < n; ++j)
			e[i][j] = read();
	memset(f, 0x3f, sizeof(f));
	f[1][0] = 0;
	for(rgi i = 1; i < (1 << n); ++i)
		for(rgi j = 0; j < n; ++j)
			if(i >> j & 1)//i�ĵ�jλΪ1
				for(rgi k = 0; k < n; ++k)
					if((i ^ 1 << j) >> k & 1)//i�ĵ�jλȡ����ĵ�kλΪ1
						f[i][j] = min(f[i][j], f[i ^ 1 << j][k] + e[k][j]);
	printf("%d", f[(1 << n) - 1][n - 1]);//�Ѿ����������еĵ㣬�ҵ������յ�(n - 1)
	return 0;
}

