#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b;
    printf("��Ǯ��ټ�������5Ԫ1ֻ��ĸ��3Ԫ1ֻ��С��1Ԫ3ֻ��ÿ�ּ�����Ҫ�����������\n");
    for(a=1;a<=20;a++)
		for(b=1;b<=33;b++)
            if((a+b+(100-a-b)==100)&&(5*a+3*b+(100-a-b)/3.0==100))
            printf("%d,%d,%d\n",a,b,(100-a-b));
	system("pause");
	return 0;
}
