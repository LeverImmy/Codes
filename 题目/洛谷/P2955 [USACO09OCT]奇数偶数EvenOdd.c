/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int n;
    int len,i;
    char a[1000];//a�����������ַ���
    int t;//t���������һλ
    scanf("%d",&n);
    for(i=0;i<n;i++)//һ����n������
		{
			scanf("%s",a);//�ȶ���
            len=strlen(a);
            t=a[len-1]-'0';//t��������һλ
            if(t%2==0)
				printf("even\n");
            else
				printf("odd\n");
        }
	system("pause");
	return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int n;
    int len,i;
    char a;
    int t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
		{
			while(scanf("%c",&a)!="\n")
				t=a-'0';
            if(t%2==0)
				printf("even\n");
            else
				printf("odd\n");
        }
	system("pause");
	return 0;
}
