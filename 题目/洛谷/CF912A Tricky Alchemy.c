#include <stdio.h>
#include <stdlib.h>
long long int yellow,blue,sum,huang,lan;
long long int x,y,z;
/*
	yellow���������еĻ�ˮ��������
    blue���������е���ˮ��������
    sum�����ǻ����ˮ��������
    huang�����ǻ���Ļ�ˮ����������
    lan�����ǻ������ˮ����������
    x������Ҫ���Ļ�ˮ����ĸ�����
    y������Ҫ������ˮ����ĸ�����
    z������Ҫ������ˮ����ĸ�����
    
    ��һ���������0~10^9
	��������Ӧ�ÿ���һ�㣬��long long
*/

int main()
{

    scanf("%lld %lld",&yellow,&blue);
    scanf("%lld %lld %lld",&x,&y,&z);//��Ȼ����long long������%lld
	huang=2*x+y;//�������ǻ���Ҫ���ٻ�ˮ��
    lan=3*z+y;//�������ǻ���Ҫ������ˮ��
    if(huang>yellow)//�����Ҫ�Ĵ����������е�
		sum=sum+huang-yellow;//�Ѳ�ļӽ�sum����
    if(lan>blue)
		sum=sum+lan-blue;//ͬ��
    printf("%lld",sum);//���
	system("pause");
	return 0;
}
