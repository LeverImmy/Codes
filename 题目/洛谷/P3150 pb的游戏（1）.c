#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i;
	int t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
		scanf("%d",&t);//����Ҫ�жϵ���
        if(t%2==0)
			printf("pb wins\n");//�����ż��������pbӮ
        if(t%2==1)
			printf("zs wins\n");//���������������zsӮ
    }
	system("pause");
	return 0;
}
