#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,count=0,flag=0;
    char a[100];
    scanf("%d",&n);
    scanf("%s",a);
    for(i=0;i<n-1;i++)//��0ѭ����n-2��Ҫ��Ȼ��Խ��
    {
		if(a[i]=='V' && a[i+1]=='K')
        {
			count++;
            a[i]='XZE';
            a[i+1]='PZY';//����ٰ�������λ�û�����������������ظ�����
        }
    }
    for(i=0;i<n-1;i++)
		if(a[i]==a[i+1])
			flag=1;//����������ڵ���ͬһ����ĸ����flag��Ϊ1
    if(flag==0)
		printf("%d",count);
    else
		printf("%d",++count);//�������������һ�θı䣬�Ǿͼ�1
	system("pause");
	return 0;
}
