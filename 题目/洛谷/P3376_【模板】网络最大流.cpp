#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define rgi register int
#define il inline
#define ll long long
#define maxn 10010
#define maxm 100010<<1
//�ǵ�˫���Ҫ������ 
#define inf 0x3f3f3f3f

using namespace std;

int n, m, s, t, cnt;
int vis[maxn], first[maxn];

struct edge
{
	int to, _next, wt;
} e[maxm];

struct node
{
	int to, id;
} pre[maxn];//��¼ǰ��

il void Add_Edge(int u, int v, int w)
{
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}//�ӱ�

il int bfs(int s, int t)
{
	memset(vis, 0, sizeof(vis));
	memset(pre, -1, sizeof(pre));//�ǵ�Ҫ��ʼ��
	queue <int> q;
	pre[s].to = s;
	vis[s] = 1;
	q.push(s);//���
	while(!q.empty())
	{
		int x = q.front();//ȡ����Ԫ��
		q.pop();
		for(rgi i = first[x]; i != -1; i = e[i]._next)
		{
			int y = e[i].to;
			if(!vis[y] && e[i].wt > 0)//��yδ�����ʹ�������·�ϻ���ʣ������
			{
				pre[y].to = x;
				pre[y].id = i;//��¼ǰ��
				vis[y] = 1;//��ʾ�Ѿ����ʹ���
				if(y == t)
					return 1;//���˻��
				q.push(y);//���
			}
		}
	}
	return 0;//���������㣬�򷵻�0
}

il int EK(int s, int t)
{
	int res = 0;
	while(bfs(s, t))
	{
		int cur_min_flow = inf;//��ʼ����С��������Ϊinf
		for(rgi i = t; i != s; i = pre[i].to)
			cur_min_flow = min(cur_min_flow, e[pre[i].id].wt);//����ǰ�����ݲ�������С��������
		for(rgi i = t; i != s; i = pre[i].to)
		{
			e[pre[i].id].wt -= cur_min_flow;//����������·�ϵ�������������ȥ��С��������
			e[pre[i].id ^ 1].wt += cur_min_flow;//����߾�Ҫ������С��������
		}
		res += cur_min_flow;//�������������������õ�����
	}
	return res;
}

int main()
{
	memset(first, -1, sizeof(first));
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for(rgi i = 1; i <= m; ++i)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		Add_Edge(u, v, w);
		Add_Edge(v, u, 0);//����� 
	}
	printf("%d", EK(s, t));
	return 0;
}

