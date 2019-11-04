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
#define maxn 100010
#define inf 0x7fffffff

using namespace std;

int n, tot, root;

struct Treap
{
	int lc, rc;
	int val, dat;
	int siz, cnt;
} t[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int New(int val)
{
	tot++;
	t[tot].val = val;
	t[tot].dat = rand();
	t[tot].siz = 1;
	t[tot].cnt = 1;
	return tot;
}

void Pushup(int p)
{
	t[p].siz = t[t[p].lc].siz + t[t[p].rc].siz + t[p].cnt;
}

void Build()
{
	root = New(-inf);
	t[root].rc = New(inf);
	Pushup(root);
}

int GetRankByVal(int p, int val)
{
	if(p == 0)
		return 0;
	if(val == t[p].val)
		return t[t[p].lc].siz + 1;
	if(val < t[p].val)//������ֵ��С
		return GetRankByVal(t[p].lc, val);
	//����ݹ����������Ҫ�����������Ĵ�С���Լ����ظ�����
	return GetRankByVal(t[p].rc, val) + t[t[p].lc].siz + t[p].cnt;
}

int GetValByRank(int p, int rank)
{
	if(p == 0)
		return inf;
	if(t[t[p].lc].siz >= rank)//���������������Ĵ�С����ôһ��������������
		return GetValByRank(t[p].lc, rank);
	else if(t[t[p].lc].siz + t[p].cnt >= rank)//��ʱ����һ��С���������Ĵ�С���������Լ����ظ�������������������ôһ�������Լ���
		return t[p].val;
	//��ʱһ������������
	return GetValByRank(t[p].rc, rank - t[t[p].lc].siz - t[p].cnt);
}

void zig(int &p)
{
	int q = t[p].lc;
	t[p].lc = t[q].rc;
	t[q].rc = p;
	p = q;
	Pushup(t[p].rc);
	Pushup(p);
}

void zag(int &p)
{
	int q = t[p].rc;
	t[p].rc = t[q].lc;
	t[q].lc = p;
	p = q;
	Pushup(t[p].lc);
	Pushup(p);
}

void Insert(int &p, int val)
{
	if(p == 0)
	{
		p = New(val);
		return;
	}
	if(val == t[p].val)
	{
		t[p].cnt++;
		Pushup(p);
		return;
	}
	if(val < t[p].val)
	{
		Insert(t[p].lc, val);
		if(t[p].dat < t[t[p].lc].dat)
			zig(p);
	}
	else
	{
		Insert(t[p].rc, val);
		if(t[p].dat < t[t[p].rc].dat)
			zag(p);
	}
	Pushup(p);
}

int GetPre(int val)
{
	int ans = 1;
	int p = root;
	while(p)
	{
		if(val == t[p].val)
		{
			if(t[p].lc > 0)
			{
				p = t[p].lc;
				while(t[p].rc > 0)
					p = t[p].rc;
				ans = p;
			}
			break;
		}
		if(val > t[p].val && t[p].val > t[ans].val)
			ans = p;
		p = val < t[p].val ? t[p].lc : t[p].rc;
	}
	return t[ans].val;
}

int GetNext(int val)
{
	int ans = 2;
	int p = root;
	while(p)
	{
		if(val == t[p].val)//���ҵ���ֵΪval�ĵ�
		{
			if(t[p].rc > 0)//���������ݹ�
			{
				p = t[p].rc;
				while(t[p].lc > 0)//����������
					p = t[p].lc;
				ans = p;//ֱ���ҵ�����
			}
			break;
		}
		if(val < t[p].val && t[p].val < t[ans].val)//�ܸ���ans
			ans = p;
		p = val < t[p].val ? t[p].lc : t[p].rc;//���������ֱ�ݹ�
	}
	return t[ans].val;
}

void Remove(int &p, int val)
{
	if(p == 0)
		return;
	if(val == t[p].val)
	{
		if(t[p].cnt > 1)//����ظ���������һ����ֻ��һ���ظ�����
		{
			t[p].cnt--;
			Pushup(p);
			return;
		}
		if(t[p].lc || t[p].rc)//���������ǿ�
		{
			if(t[p].rc == 0 || t[t[p].lc].dat > t[t[p].rc].dat)
			{
				zig(p);
				Remove(t[p].rc, val);
			}
			else
			{
				zag(p);
				Remove(t[p].lc, val);
			}
			Pushup(p);
		}
		else
			p = 0;//��ʱpһ����Ҷ�ӽڵ㣬ɾ��
		return;
	}
	val < t[p].val ? Remove(t[p].lc, val) : Remove(t[p].rc, val);//���������ֱ�ݹ�
	Pushup(p);
}

int main()
{
	Build();
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		int opt = read(), x = read();
		if(opt == 1)
			Insert(root, x);
		else if(opt == 2)
			Remove(root, x);
		else if(opt == 3)
			printf("%d\n", GetRankByVal(root, x) - 1);
		else if(opt == 4)
			printf("%d\n", GetValByRank(root, x + 1));
		else if(opt == 5)
			printf("%d\n", GetPre(x));
		else if(opt == 6)
			printf("%d\n", GetNext(x));
	}
	return 0;
}

