#include<cstdio>
#define oo (1LL<<60)
#define ll long long
using namespace std;
ll ans,tmp;
int i,a,b,x,fin,j;
ll f(int x)
{
	int s,v;
	s=b/(x+1); v=b%(x+1);
	ll f1;
	f1=1LL*v*(s+1)*(s+1);
	f1+=1LL*(x+1-v)*s*s;
	ll f2;
	if (x)
		f2=1LL*(a-x+1)*(a-x+1)+x-1;
	else f2=1LL*(a-x)*(a-x)+x;
	return f2-f1;
}
int main()
{
	freopen("cards.in","r",stdin);
	freopen("cards.out","w",stdout);
	scanf("%d %d",&a,&b);
	ans=-oo; 
	for(x=0;x<=a;x++)
		{
			tmp=f(x);
			if (tmp>ans)
				fin=x,ans=tmp;
		}
	printf("%I64d\n",ans);
	int s,v; x=fin;
	s=b/(x+1); v=b%(x+1);
	if (!x)
		{
			for(i=1;i<=b;i++)
				printf("x");
			for(i=1;i<=a;i++)
				printf("o");
			return 0;
		}
	for(i=1;i<=v;i++)
		{
			for(j=1;j<=s+1;j++)
				printf("x");
			printf("o");
		}
	for(i=1;i<=x-v;i++)
		{
			for(j=1;j<=s;j++)
				printf("x");
			printf("o");
		}
	for(i=1;i<=a-x;i++)
		printf("o");
	for(i=1;i<=s;i++)
		printf("x");
	return 0;
}
