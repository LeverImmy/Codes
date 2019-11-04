#include <stdio.h>
#include <stdlib.h>
int max(int a,int b)
{
	return a>b?a:b;
}//����max����
int min(int a,int b)
{
	return a<b?a:b;
}//����min����
struct spot
{
	int dis1;
    int dis2;
}r[1000000],t;//�ýṹ�����洢ÿ���㵽���׵�������ϵͳ�ľ��룬��һ�㣬������
void quicksort(int left,int right)
{
	int i,j,mid;
    i=left;j=right;
    mid=r[(left+right)/2].dis1;//ע�������Ǹ��ݵ���һ������ϵͳ�ľ�������С�����ŵ���
    do
    {
		while(r[i].dis1<mid)//����Ҳ��
			i++;
        while(r[j].dis1>mid)//����Ҳ��
			j--;
        if(i<=j)
        {
			t=r[i];
            r[i]=r[j];
            r[j]=t;
            i++;
            j--;
        }
    }while(i<=j);
    if(left<j)
		quicksort(left,j);
    if(right>i)
		quicksort(i,right);
}//��������
int main()
{
	int a,b,c,d,x,y,n,i,r2=0,sum=100000;
    //r2�ǵڶ�������ϵͳ�İ뾶����ֵΪ0��Ҳ���ǰѵڶ�������ϵͳ�رգ�ֻ�е�һ������ϵͳ
    //sum���һ��
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&n);
    for(i=1;i<=n;i++)
	{
    	scanf("%d %d",&x,&y);
        r[i].dis1=(x-a)*(x-a)+(y-b)*(y-b);//�����ľ��빫ʽ������Ϊ�˱���С�����ͰѸ���ȥ���ˣ��Ƚ����ǵ�ƽ��
        r[i].dis2=(x-c)*(x-c)+(y-d)*(y-d);
    }
    quicksort(1,n);
    sum=r[n].dis1;//���趼�ɵ�һ����
    for(i=n;i>1;i--)
    {
		r2=max(r2,r[i].dis2);//�������r2��ֵ��Ҳ���ǰѵڶ�������ϵͳ�İ뾶����
        sum=min(sum,r[i-1].dis1+r2);//���sum����ǰ��ҪС���͸���
    }
    printf("%d",sum);//���
	system("pause");
	return 0;
}
