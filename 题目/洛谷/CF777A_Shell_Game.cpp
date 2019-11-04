#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n, x, a[3] = {0, 1, 2};

/*
��n=0ʱ��0,1,2
��n=1ʱ��1,0,2
��n=2ʱ��1,2,0
��n=3ʱ��2,1,0
��n=4ʱ��2,0,1
��n=5ʱ��0,2,1
��n=6ʱ��0,1,2
������ǿ����ҵ�һ��ѭ����Ϊ6��ѭ��
*/

int main()
{
	scanf("%d %d", &n, &x);
	n %= 6;
	for(int i = 1; i <= n; i++)
	{
		if(i & 1)
			swap(a[0], a[1]);
		else
			swap(a[1], a[2]);
	}
	printf("%d", a[x]);
	return 0;
}

