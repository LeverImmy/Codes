#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#define ll long long
#define rgi register int
#define il inline

using namespace std;

const int N = 100 + 10;
const int M = 100000 + 10;

char A[N], B[M << 1], S[N];
int lena, lenb, tot, ans;
int _next[N], cnt[N], f[N][M << 1];
/*
*	cnt[] -> ÿ��С�εĳ���
*	_next[] -> next����
*	f[i][j] -> ��ʾ��i��С������˫��B���е�һ����jλ��֮���һ�γ��ֵ�λ��
*/
bool flag1, flag2, bz[N][M << 1];
/*
*	flag1 -> B����ͷ�Ƿ���'*'
*	flag2 -> B��ĩβ�Ƿ���'*'
*	bz[i][j] -> ��ʾ��i��С���Ƿ�����B�ĵ�j��λ��������Ӧ����ƥ��
*/

il int read()
{
	rgi f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void KMP(int start)//����һλ��ʼKMP
{
	int j = 0;
	for(rgi i = 2; i <= lena; ++i)
	{
		while(j && S[i] != S[j + 1])
			j = _next[j];
		if(S[i] == S[j + 1])
		{
			j++;
			_next[i] = j;
		}
		else
			_next[i] = j = 0;
	}
	j = 0;
	for(rgi i = 2; i <= lenb << 1; ++i)
	{
		while(j && B[i] != S[j + 1])
			j = _next[j];
		if(B[i] == S[j + 1])
			j++;
		if(j == cnt[start])
			bz[start][i - j + 1] = 1;//��ƥ������һ������Ϊj�Ĵ��� 
	}
	f[start][lenb << 1 | 1] = lenb << 1 | 1;
	for(rgi j = lenb << 1; j >= 1; --j)
		if(bz[start][j])
			f[start][j] = j;
		else
			f[start][j] = f[start][j + 1];
}

int Match(int x)//�ܷ�������
{
	int y = x + lenb - 1, l = 1, r = tot;
	/*
	*	l -> С������Ҫƥ��ĵ�һ�� 
	*	r -> С������Ҫƥ������һ�� 
	*	y -> Ҫƥ���ĩβλ�� 
	*/
	if(!flag1)
	{
		if(!bz[l][x])//����ƥ�䲻�� 
			return 0;
		x += cnt[l++];//�����һ������'*'�Ļ�����Ҫ���� 
	}
	if(!flag2)
	{
		if(!bz[r][y - cnt[r] + 1])//����ƥ�䲻�� 
			return 0;
		y -= cnt[r--];//������һ������'*'�Ļ�����Ҫ����ƨ�� 
	}
	for(; l <= r; l++)
	{
		x = f[l][x];
		if(x > y)//���ȱ��ˣ�ƥ�䲻�� 
			return 0;
		x += cnt[l] - 1;
	}
	return x > y ? 0 : 1;//���ȱ��ˣ�ƥ�䲻�� 
}

int main()
{
	scanf("%s %s", A + 1, B + 1);
	lena = strlen(A + 1), lenb = strlen(B + 1);
	for(rgi i = 1; i <= lenb; ++i)
		B[i + lenb] = B[i];
	flag1 = A[1] == '*';
	flag2 = A[lena] == '*';
	//ǰ���Ƿ�Ϊ'*'
	for(rgi i = 1; i <= lena; ++i)
	{
		int len = 0;
		for(; i <= lena && A[i] != '*'; ++i)
			S[++len] = A[i];//ÿ��С���������
		if(!len)//������'*'
			continue;
		cnt[++tot] = len;//�ֳ�С����
		KMP(tot);//��ÿ��С��������KMP
	}
	for(rgi i = 1; i <= lenb; ++i)
		if(Match(i))//����ÿһλ��ʼ�ܷ����㡰�ܷ�����С������������һλ��ʼ�������ĳ���Ϊ����B���ĳ��ȵĴ�����
			ans++;
	printf("%d", ans);
	return 0;
}

