#include <stdio.h>
#include <stdlib.h>
int z(int n)//��������һ��ͳ���ж��ٸ�������5�ĺ���
{
	int i,j,count=0;
	while(n)
    {
		while(n)
        {
			count=count+n/5;
            n=n/5;
        }//����ѭ���ۼ�
    }
    return count;

}
int main()
{
	int n,i;
    int t;
    scanf("%d",&n);
    for(i=0;i<n;i++)//һ��n������
	{
		scanf("%d",&t);
		printf("%d\n",z(t));//��z()����
    }
	system("pause");
	return 0;
}
