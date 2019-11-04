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
#define maxn 10010
#define maxm 10010

using namespace std;

const int oo = 0x3f3f3f3f;

int n, m, cnt;
int lg2[maxn] = { -1}, first[maxn], dep[maxn], dis[maxn];
int f[maxn][50];

struct edge
{
	int to, _next, wt;
} e[maxm << 1];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v, int w)
{
	e[++cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt;
}

void init()
{
	for(rgi i = 1; i <= n; ++i)
		lg2[i] = lg2[i >> 1] + 1;
}

void dfs(int x, int p, int weight)
{
	dep[x] = dep[p] + 1;
	dis[x] = dis[p] + weight;
	f[x][0] = p;
	for(rgi i = 1; i <= lg2[dep[x]]; ++i)
		f[x][i] = f[f[x][i - 1]][i - 1];
	for(rgi i = first[x]; i; i = e[i]._next)
		if(e[i].to != p)
			dfs(e[i].to, x, e[i].wt);
}

int lca(int u, int v)
{
	if(dep[u] > dep[v])
		swap(u, v);
	int temp = dep[v] - dep[u];
	for(rgi i = 0; i <= lg2[dep[v]]; ++i)
		if(temp & (1 << i))
			v = f[v][i];
	if(u == v)
		return u;
	for(rgi i = lg2[dep[v]]; i >= 0; --i)
		if(f[u][i] != f[v][i])
		{
			u = f[u][i];
			v = f[v][i];
		}
	return f[u][0];
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= n - 1; ++i)
	{
		int u = read(), v = read(), w = read();
		Add_Edge(u, v, w);
		Add_Edge(v, u, w);
	}
	init();
	dfs(1, 0, oo);
	for(rgi i = 1; i <= m; ++i)
	{
		int s = read(), t = read();
		printf("%d\n", dis[s] + dis[t] - 2 * dis[lca(s, t)]);
	}
	return 0;
}

