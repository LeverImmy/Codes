#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int n,len,i;
    char a[100];
    int b[100];
    scanf("%d",&n);
    scanf("%s",a);
    if(n>=26)
		n=n-26;
    len=strlen(a);
    for(i=0;i<len;i++)
		{
			if(a[i]+n>122)//char[]������>127�ᱬ
				a[i]=a[i]-26;
            a[i]=a[i]+n;
            /*
            ����˵����
            a[i]=a[i]+n;//����һ���Ѿ�����
            if(a[i]>122)
				a[i]=a[i]-26;
            */
        }
    puts(a);
	system("pause");
	return 0;
}
