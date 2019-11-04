#include <cstdio>
#include <cstring>
#define maxn 1000010
#define rgi register int
#define il inline
#define swap(a,b) a^=b^=a^=b

using namespace std;

int n, siz;
int h[maxn];//��

il void push(int val)
{
	h[++siz] = val;//����β���Ԫ��
	int cur = siz;//cur��ʾ��ǰҪ���ϵ����Ľڵ��ţ���ʼ��Ϊ��β���
	while(cur >= 1)//��cur���ǶѶ���ʱ��ѭ��
	{
		if(h[cur]<h[cur >> 1])//����Լ��ĸ��ױ��Լ���
			swap(h[cur], h[cur >> 1]);//����
		else
			break;//����޷�������������Ѿ��������
		cur >>= 1;//��ʼ�����Լ��ĸ��׽ڵ�
	}
}

il void pop()
{
	swap(h[1], h[siz]);//�����������βԪ��
	h[siz--] = 0;//ɾ��
	int cur = 1;//cur��ʾ��ǰҪ���µ����Ľڵ��ţ���ʼ��Ϊ���ױ��
	while((cur << 1) <= siz)
	{
		int lc = cur << 1, rc = lc + 1, _next;
		//lc������ӱ�ţ�rc���Ҷ��ӱ�ţ�_next����һ��Ҫ����Ľڵ��ţ�Ҫô������ӣ�Ҫô���Ҷ��ӣ�
		if(rc <= siz)//���rcû�г�siz���ͱȽ�lc��rc�Ĵ�С������С����һ��
		{
			if(h[lc] <= h[rc])
				_next = lc;
			else
				_next = rc;
		}
		else//���rc����siz����ôֻ�ܿ����������
			_next = lc;
		if(h[_next] < h[cur])//�����һ��Ҫ����Ľڵ�ȵ�ǰ�ڵ�С
		{
			swap(h[_next], h[cur]);//����
			cur = _next;//��ʼ������һ���ڵ�
		}
		else
			break;//����޷�������������Ѿ��������
	}
}

il int top()
{
	return h[1];//�Ѷ���Ȼ��h[1]
}

int main()
{
	scanf("%d", &n);
	for(rgi i = 1; i <= n; i++)
	{
		int op;
		scanf("%d", &op);
		if(op == 1)
		{
			int v;
			scanf("%d", &v);
			push(v);
		}
		else if(op == 2)
			printf("%d\n", top());
		else if(op == 3)
			pop();
	}
	return 0;
}
