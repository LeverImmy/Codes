#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define rgi register int
#define il inline
#define ll long long
#define maxn 210<<1
#define maxm 210<<1
#define inf 0x3f3f3f3f

using namespace std;

int n, m, s, t, cnt;
int first[maxn], dep[maxn], curEdge[maxn];

struct edge
{
	int to, _next, wt;
} e[maxm];

il void Add_Edge(int u, int v, int w)
{
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}//�ӱ�

il int bfs()
{
	memset(dep, -1, sizeof(dep));
	dep[t] = 0;//�ӻ�㿪ʼ�����û������Ϊ0
	queue <int> q;
	q.push(t);//���
	while(!q.empty())
	{
		int x = q.front();//ȡ������ 
		q.pop();
		for(rgi i = first[x]; i != -1; i = e[i]._next)
		{
			int y = e[i].to;
			if(dep[y] == -1 && e[i ^ 1].wt > 0)//���yδ��Ⱦɫ�����ҷ���߻������� 
			{
				dep[y] = dep[x] + 1;//Ⱦɫ 
				q.push(y);//��� 
			}
		}
	}
	return dep[s] != -1;//���Ƿ���Ⱦ��Դ��
}//�ֲ�

il int dfs(int u, int v, int flow)
{
	if(u == t)
		return flow;
	int delta = flow;
	for(rgi &i = curEdge[u]; i != -1; i = e[i]._next)//��ǰ���Ż�(ؽ������)
	{
		int cur = e[i].to;
		if(dep[u] == dep[cur] + 1 && e[i].wt)
		{
			int dfn = dfs(cur, v, min(delta, e[i].wt));
			e[i].wt -= dfn;
			e[i ^ 1].wt += dfn;
			delta -= dfn;
			if(!delta)
				break;
		}
	}
	return flow - delta;
}

il int dinic()
{
	int res = 0;
	while(bfs())
	{
		for(rgi i = 0; i < n; ++i)
			curEdge[i] = first[i];//���Ƶ�ǰ�� 
		res += dfs(s, t, inf);//��������� 
	}
	return res;
}

int main()
{
	scanf("%d %d", &m, &n);
	s = 1, t = n;
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= m; ++i)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		Add_Edge(u, v, w);
		Add_Edge(v, u, 0);//����� 
	}
	printf("%d", dinic());
	return 0;
}

