#include <cstdio>
#include <cstring>

using namespace std;

int t, s, x, delta;

int main()
{
	scanf("%d %d %d", &t, &s, &x);
	delta = x - t;//delta���м�����ʱ�� 
	if(delta >= 0 && delta != 1 && (delta % s == 1 || delta % s == 0))
		printf("YES");//���delta�����ģ���Ŀ˵�˲�����t+1��ʱ���
					  //���delta%s��ֵ��1������0���ͻ�� 
	else
		printf("NO");
	return 0;
}

