#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
namespace Sonoda
{
	template<typename T> void swap(T &a,T &b)
	{
		T t;
		t=a;
		a=b;
		b=t;
	}
	template<typename T> T GCD(T a,T b)
	{
		if(b==0)
		{
			return a;
		}
		return GCD(b,a%b);
	}
	template<typename T>T Qpow(T a,T b,T p)
	{
		T res=1;
		while(b)
		{
			if(b&1)
			{
				res*=a;
				res%=p;
				b--;
			}
			else
			{
				a*=a;
				a%=p;
				b>>=1;
			}
		}
		return res;
	}
	template <typename T> void Ex_GCD(T a,T b,T &x,T &y)
	{
		if(b==0)
		{
			x=1;
			y=0;
			return;
		}
		Ex_GCD(b,a%b,x,y);
		T t=x;
		x=y;
		y=t-a/b*y;
	}
	template<typename T> inline T read()
	{
		T num = 0, w = 1;
		char c = 0;
		while (c != '-' && !isdigit(c)) c = getchar();
		if (c == '-') w = -1, c = getchar();
		while (isdigit(c)) num = num * 10 + c - '0', c = getchar();
		return num * w;
	}
	template<typename T> inline void write(T x)
	{
		if (x < 0) putchar('-'), x = -x;
		if (x / 10) write(x / 10);
		putchar(x % 10 + '0');
	}
}
const int MAXN=2000005;
int top;
char a;
char fuck[MAXN];
int now,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int N=Sonoda::read<int>();
	for(int i=0;i<N;i++)
	{
		scanf("%c",&a);
		fuck[i]=a;
		if(a=='(')
		{
			top++;
			now++;
		}
		if(a==')')
		{
			top--;
			now++;
			if(top==0)
			{
				ans=max(ans,now);
			}
			if(top<0)
			{
				now=0;
				top=0;
			}
		}
	}
	top=0;
	now=0;
	int cnt=0;
	for(int i=0;i<N;i++)
	{
		a=fuck[i];
		if(a=='(')
		{
			top++;
			now++;
		}
		if(a==')')
		{
			top--;
			now++;
			if(top==0)
			{
				if(now==ans)
				{
					cnt++;
				}
			}
			if(top<0)
			{
				now=0;
				top=0;
			}
		}
	}
	printf("%d %d",ans,cnt);
	return 0;
}

