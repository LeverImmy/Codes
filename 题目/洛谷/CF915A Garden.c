#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,k,i,min=10000,ans=0,t;
/*
	n,k����Ŀ���������
    i������ѭ��������
    min���洢��Сֵ������Ԥ��ֵҪ�����Ĵ󣩣�
    ans�������ֵ��
    t�������������ݵ���ʱ������
*/
    scanf("%d %d",&n,&k);//������n��k
    for(i=0;i<n;i++)
    {
		scanf("%d",&t);//���뵽һ������t����
        if(k%t==0)//�ȿ��ܲ�������
		{
			ans=k/t;
			if(ans<min)//������и�С��
				min=ans;//���´�
        }
    }
    printf("%d",min);//����С�����
	system("pause");
	return 0;
}
