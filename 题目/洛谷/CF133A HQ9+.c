#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char a[10000];//�洢�ַ���
    int len,i,flag=0;
    /*
		len���ַ����ĳ��ȣ�
        i��ѭ���õģ�
        flag�ǿ�����û��Ҫ�����ĸ
    */
    scanf("%s",a);//�����ַ���
    len=strlen(a);//�󳤶�
    for(i=0;i<len;i++)//����
		if(a[i]=='H' || a[i]=='Q' || a[i]=='9')//�����
			flag=1;
    if(flag==1)
		printf("YES");
    else
		printf("NO");
	system("pause");
	return 0;//��������
}
