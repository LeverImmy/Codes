#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a;
    while(1)//����ѭ��
    {
		scanf("%d",&a);
        if(a==42)//һ������Ϊ42
			break;//��ͣ
		printf("%d\n",a);//����ʲô���ʲô
    }
	system("pause");
	return 0;
}
