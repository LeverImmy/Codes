#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,j,count=0;
    int a,b,c,d,e,f,g;
    int p[7],m[7]={0};
    scanf("%d",&n);
    scanf("%d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g);//�����н�����
    for(i=0;i<n;i++)
	{	scanf("%d %d %d %d %d %d %d",&p[0],&p[1],&p[2],&p[3],&p[4],&p[5],&p[6]);//������Ĳ�Ʊ�ĺ���
		for(j=0;j<=6;j++)//�������
			if(p[j]==a || p[j]==b || p[j]==c || p[j]==d || p[j]==e || p[j]==f || p[j]==g)//������н��ĺ���֮һ��ͬ
				count++;
        if(count==1)	m[6]++;
        if(count==2)	m[5]++;
        if(count==3)	m[4]++;
        if(count==4)	m[3]++;
        if(count==5)	m[2]++;
        if(count==6)	m[1]++;
        if(count==7)	m[0]++;
        //printf("%d ",count);
        count=0;
    }
	for(j=0;j<7;j++)
		printf("%d ",m[j]);
    system("pause");
	return 0;
}
