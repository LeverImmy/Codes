#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int prime(int n)//�ж������ĺ���
{
	int i;
    if(n<2)//С��2�������Բ�������
		return 0;
    else
    {
		for(i=2;i<=sqrt(n);i++)//��2ѭ����$\sqrt{n}$
			if(n%i==0)//����ܹ�����
				return 0;//�ǾͲ�������
        return 1;
    }
}
int main()
{
	int n;
    int i,j,t1,t2;
    scanf("%d",&n);//һ��n������
    for(i=1;i<=n;i++)
		{
			scanf("%d %d",&t1,&t2);//t1Ϊ����ޣ�t2Ϊ�ҽ���
			for(j=t1;j<=t2;j++)//�������ѭ�����ҽ���
				{
					if(prime(j)==1)//���������
						printf("%d\n",j);//���������
                }
            printf("\n");//ÿ�鶼����
        }
	system("pause");
	return 0;
}
