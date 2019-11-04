#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 1500 + 10;

int n, cnt;
ll x[N], y[N];

struct node
{
	ll x, y;
	int quad;
} tmp[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct node a, struct node b)
{
	return a.x * b.y > a.y * b.x;
}

void Rotate(int p)
{
	swap(tmp[p].x, tmp[p].y);
	tmp[p].y = -tmp[p].y;
	tmp[p].quad = (tmp[p].quad + 1) % 4;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		x[i] = read();
		y[i] = read();
	}
	for(rgi i = 1; i <= n; ++i)//ö��ֱ�Ƕ���
	{
		for(rgi j = 1; j <= n; ++j)//�ƶ�ƽ��ֱ������ϵ
		{
			tmp[j].x = x[j] - x[i];
			tmp[j].y = y[j] - y[i];
			tmp[j].quad = 0;
			if(i == j)//ǿ�и�ԭ�㶨һ������
			{
				tmp[j].x = tmp[1].x;
				tmp[j].y = tmp[1].y;
				tmp[j].quad = tmp[1].quad;
			}
			else
				while(tmp[j].x <= 0 || tmp[j].y < 0)//��ת����һ����
					Rotate(j);
		}
		sort(tmp + 2, tmp + n + 1, cmp);//���սǶ�����
		int j = 2;
		while(j <= n)//ͳ�ƴ�
		{
			int ans[4] = {0};
			int k = j;
			while(k <= n && tmp[j].x * tmp[k].y == tmp[j].y * tmp[k].x)//��ͬһֱ���� 
				ans[tmp[k].quad]++, k++;
			for(rgi l = 0; l <= 3; ++l)//�������޲��ܹ���ֱ�� 
				cnt += ans[l] * ans[(l + 1) % 4];
			j = k;
		}
	}
	printf("%d", cnt);
	return 0;
}

