#include <stdio.h>
#include <stdlib.h>
int min(int m,int n)
{
	if(m<=n)
		return m;
    else
		return n;
}//�����Զ���һ��min()����
int main()
{
	int a,b,c,maxn=-100,i,minn;//maxn��ֵҪ���Сһ��
    scanf("%d\n%d\n%d",&a,&b,&c);
    minn=min(min(a,b),c);//������������С�����ҳ���������ѭ���Ĵ���
    for(i=1;i<=minn;i++)
		if((a%i==0)&&(b%i==0)&&(c%i==0))//��������������Ĺ�Լ��
			if(i>maxn)//�������ֵ
				maxn=i;
    printf("%d",maxn);//���
	system("pause");
	return 0;
}
