#include <cstdio>
#include <cctype>
#include <cstring>
#include <queue>
#include <algorithm>
#define rgi register int
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1200 + 10;
const int M = 120000 + 10;

int n, m, s, t, cnt, siz;
int first[N], h[N], V[N], vis[N], cnth[N];

struct edge
{
	int to, _next, wt;
} e[M << 1];

struct node
{
	int id, val;
} heap[N];

il int read()
{
	rgi ch, x = 0, f = 0;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void Add_Edge(int u, int v, int w)
{
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt;
	cnt++;
}

il void push(int id, int val)
{
	siz++;
	heap[siz].id = id;
	heap[siz].val = val;
	int cur = siz;
	while(cur > 1)
	{
		if(heap[cur].val > heap[cur >> 1].val)
			swap(heap[cur], heap[cur >> 1]);
		else
			break;
		cur >>= 1;
	}
}

il void pop()
{
	swap(heap[1], heap[siz--]);
	int cur = 1;
	while((cur << 1) <= siz)
	{
		int lc = cur << 1, rc = lc + 1, nxt;
		if(rc <= siz)
		{
			if(heap[lc].val >= heap[rc].val)
				nxt = lc;
			else
				nxt = rc;
		}
		else
			nxt = lc;
		if(heap[nxt].val > heap[cur].val)
			swap(heap[nxt], heap[cur]);
		else
			break;
		cur = nxt;
	}
}

struct node top()
{
	return heap[1];
}

il void bfs(int s, int t)
{
	for(rgi i = 1; i <= n; ++i)
		h[i] = oo;
	h[t] = 0;
	queue <int> q;
	q.push(t);
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		vis[x] = 0;
		for(rgi i = first[x]; ~i; i = e[i]._next)
		{
			int y = e[i].to;
			if(e[i ^ 1].wt && h[y] > h[x] + 1)
			{
				h[y] = h[x] + 1;
				if(!vis[y])
				{
					vis[y] = 1;
					q.push(y);
				}
			}
		}
	}
}

il void Push_Flow(int x)
{
	for(rgi i = first[x]; ~i; i = e[i]._next)
	{
		int y = e[i].to;
		if(e[i].wt && h[y] == h[x] - 1)
		{
			int cur_flow = min(V[x], e[i].wt);
			V[x] -= cur_flow;
			e[i].wt -= cur_flow;
			V[y] += cur_flow;
			e[i ^ 1].wt += cur_flow;
			if(!vis[y] && y != s && y != t)
			{
				vis[y] = 1;
				push(y, h[y]);
			}
			if(!V[x])
				break;
		}
	}
}

il void Relabel(int x)
{
	//���´���x�ĸ߶�
	int minn = oo;
	for(rgi i = first[x]; ~i; i = e[i]._next)
	{
		int y = e[i].to;
		if(e[i].wt)
			minn = min(minn, h[y]);
	}//�ҵ��߶���͵ĵ�
	h[x] = minn + 1;//
}

il int HLPP(int s, int t)
{
	bfs(s, t);//�ӻ�㿪ʼ�ֲ㣬�����ÿ����ĸ߶�
	if(h[s] == oo)
		return 0;//���ͼ���������ͨ��
	h[s] = n;
	for(rgi i = 1; i <= n; ++i)
		if(h[i] != oo)
			cnth[h[i]]++;//��¼ÿ����ĸ߶�
	for(rgi i = first[s]; ~i; i = e[i]._next)
	{
		int y = e[i].to;
		int cur_flow = e[i].wt;
		if(cur_flow)
		{
			V[s] -= cur_flow;
			V[y] += cur_flow;
			e[i].wt -= cur_flow;
			e[i ^ 1].wt += cur_flow;
			if(!vis[y] && y != s && y != t)//������Դ�㣡Ҳ�����ǻ�㣡
			{
				vis[y] = 1;
				push(y, h[y]);
			}
		}
	}
	while(siz)//�����ȶ����������Ͷ�push_up����һ����Ҫ�Ӵ���С������
	{
		int cur = top().id;
		pop();
		vis[cur] = 0;
		Push_Flow(cur);//�ƽ���
		if(V[cur])//��������Ʋ������
		{
			cnth[h[cur]]--;
			if(!cnth[h[cur]])//�����һ��û�е���
			{
				for(rgi i = 1; i <= n; ++i)
					if(h[i] > h[cur] && h[i] <= n && i != s && i != t)
						h[i] = n + 1;
				//GAP�Ż����ѱ����ߵĵ�����Ϊ���ɵ��
				//ʹ���ĸ߶�Ϊn + 1�������ͻ�ֱ����s������
			}
			Relabel(cur);//���±��
			cnth[h[cur]]++;
			vis[cur] = 1;
			push(cur, h[cur]);
		}
	}
	return V[t];
}

int main()
{
	n = read(), m = read(), s = read(), t = read();
	for(rgi i = 1; i <= n; ++i)
		first[i] = -1;
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read(), w = read();
		Add_Edge(u, v, w);
		Add_Edge(v, u, 0);
	}
	printf("%d", HLPP(s, t));
	return 0;
}
