#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n;

int is_prime(int num)
{
	if(num < 2)
		return 0;
	for(int i = 2; i * i <= num; i++)
		if(num % i == 0)
			return 0;
	return 1;
}

int main()
{
	scanf("%d", &n);
	if(is_prime(n))
		cout << 1; //����������ͷ�Ϊ1��
	else if(n % 2 == 0)
		cout << 2; //���n��ż�����ɸ�°ͺղ����֪��n���Է�Ϊ���������ĺ�
	else if(n % 2 == 1)
	{
		if(is_prime(n - 2))
			cout << 2;//���n-2��������n�Ϳ��Է�Ϊn-2��2���ֳ�2��
		else
			cout << 3;//���n��������n-2������������ֻ�ܷ�Ϊ3��n-3
					  //ע������3��������n-3��ż��������Ҫ��Ϊ3��
	}
	return 0;
}

