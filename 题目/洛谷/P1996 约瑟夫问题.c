#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[1000]={0};
    int n,m;
    int count=1,num=0;
    int i,j;
    scanf("%d %d",&n,&m);
    j=n;//j�൱��ָ�룬ָ��n
    for(i=1;i<n;i++)
		a[i]=i+1;
    a[n]=1;
    while(num<n)//num�ǳ�Ȧ������
		{
			while(count<m)//count��ÿ��������
                {
					j=a[j];
                    count++;
                }
            printf("%d ",a[j]);
            num++;
            a[j]=a[a[j]];//ɾ��a[j]
            count=1;
        }
	//system("pause");
	return 0;
}
