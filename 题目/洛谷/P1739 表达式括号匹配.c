#include <stdio.h>
#include <stdlib.h>
int main()
{
	char a[300];
    int i=0,len,left=0,right=0;
    scanf("%s",a);
    len=strlen(a);
    for(i=0;i<len-1;i++)//len-1����ΪҪ��ȥ'@'
		{
			if(a[i]=='(')
				left++;
            if(a[i]==')')
				right++;//�����������ŵ�����
        }
    if(left!=right)//����������ŵ����������ȣ��϶�����
		{
			printf("NO");
            system("pause");
			return 0;
        }
	else
    {
		left=0;
        right=0;
        for(i=0;i<len-1;i++)
		{
			if(a[i]=='(')
				left++;
            if(a[i]==')')
				left--;//����һ������
            if(left<0)//ÿ�ζ�Ҫ�ж�һ�Σ��������ŵ������Ƿ�0
				{
					printf("NO");
                    system("pause");
					return 0;
                }
        }
    
		printf("YES");
		system("pause");
		return 0;
    }
		
}

