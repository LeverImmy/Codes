#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct pre//һ���ṹ��
{
	int num;//���
    char vote[110];//��Ϊ��Ŀ����ȷ��ʾ�ˣ�����Ʊ����100λ֮�ࣨ������Ӧ��ȷʵ����ô�ࡰ�ˡ����������������ַ������洢
}a[30],t;
int main()
{
	int n,i,j,len1,len2;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
		a[i].num=i+1;//ÿ���˵������i+1����Ϊi�Ǵ�0��ʼ���
        scanf("%s",a[i].vote);//�洢Ʊ��
    }
    for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		{
			len1=strlen(a[j].vote);
            len2=strlen(a[j+1].vote);
        	if(len1<len2)
            {
				t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
			else if((len1==len2)&&(strcmp(a[j].vote,a[j+1].vote)<0))
			{
				t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }//ð������
    printf("%d\n%s",a[0].num,a[0].vote);
	system("pause");
	return 0;
}
