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
#define maxn 10

using namespace std;

int n, ans = -10000, cnt;
int e[maxn][maxn *maxn];
int vis[maxn][maxn], yes[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void debug(int current_ans)
{
	for(rgi i = 1; i <= cnt; ++i)
		printf("%d ", yes[i]);
	printf("::%d\n", current_ans);
}

void dfs(int step, int cur_ans)
{
	int flag = 1;
	if(step == n + 1)
	{
		ans = max(ans, cur_ans);
//		debug(cur_ans);
		return;
	}
	dfs(step + 1, cur_ans);//��ѡ��step��·��
	for(rgi i = 1; i <= e[step][0] - 1; ++i)
		if(vis[e[step][i]][e[step][i + 1]] || vis[e[step][i + 1]][e[step][i]])
		{
			flag = 0;
			break;
		}//������·���Ƿ��ԭ�����г�ͻ
	if(flag)
	{
		for(rgi i = 1; i <= e[step][0] - 1; ++i)
			vis[e[step][i]][e[step][i + 1]] = vis[e[step][i + 1]][e[step][i]] = 1; //������·���ϵı߶����Ϊ���ѷ��ʹ���
		yes[++cnt] = step;
		dfs(step + 1, cur_ans + e[step][0] - 1);//����·������e[step][0] - 1����
		for(rgi i = 1; i <= e[step][0] - 1; ++i)
			vis[e[step][i]][e[step][i + 1]] = vis[e[step][i + 1]][e[step][i]] = 0; //�ٸ�Ϊ��δ���ʹ���
		cnt--;
	}
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		e[i][0] = read();
		for(rgi j = 1; j <= e[i][0]; ++j)
			e[i][j] = read();
	}
	dfs(1, 0);
	printf("%d", ans);
	return 0;
}

