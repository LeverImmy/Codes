#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
using namespace std;
//void add(int a,int b,int c) {e[a]=c;next[a]=head[b];head[b]=a;}
const int MOD=1000000007;
long long b[15],c[15],a[15],dp[105],bit[15],A[15][15][105],ans,G[15],B,C,D,T;
int i,j,k;
int quick(int a,int b)
{
    int ans=1;
    while (b) {if (b&1) ans=1ll*ans*a%MOD; a=1ll*a*a%MOD; b>>=1;}
    return ans;
}
int cmp(long long i,long long j) {return i<j;}
void dfs(int x,int y)
{
    if (y>j || y+i-x+1<j) return;
    if (x==i+1)
    {
        for (int k=1; k<=i; k++) b[k]=0; int sum=0;
        for (int k=1; k<=i; k++)
        {
            for (int l=1; l<=i-k+1; l++) b[l]=b[l]*10+a[k+l-1];
            for (int l=1; l<=i-k+1; l++) c[l]=b[l];
            sort(c+1,c+i-k+1+1,cmp); sum++;
            for (int l=2; l<=i-k+1; l++) if (c[l]!=c[l-1]) sum++;
        }
        dp[sum]++;
        return;
    }
    for (int k=1; k<=y+1; k++)
    {
        a[x]=k;
        if (k<=y) dfs(x+1,y); else dfs(x+1,y+1);
    }
}
long long CC(int x,int y)
{
    long long sum=1;
    for (int i=x; i>x-y; i--) sum=sum*i%MOD;
    for (int i=2; i<=y; i++) sum=sum*G[i]%MOD;
    return sum;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    for (i=1; i<=10; i++) G[i]=quick(i,MOD-2);
  //  cout<<G[1]<<' '<<G[2]*2%MOD<<' '<<CC(1,1)<<endl;
    for (i=1; i<=10; i++)
      for (j=1; j<=i; j++)
      {
          for (k=1; k<=100; k++) dp[k]=0;
          dfs(1,0);
          for (k=1; k<=100; k++) A[i][j][k]=dp[k];
      }
    //scanf("%d",&T); T=1;
    T=1;
    bit[0]=1; for (i=1; i<=10; i++) bit[i]=bit[i-1]*i%MOD;
    for (i=1; i<=10; i++) for (j=1; j<=i; j++) for (k=1; k<=100; k++) A[i][j][k]=A[i][j][k]*bit[j]%MOD;
    while (T--)
    {
        scanf("%d%d%d",&B,&C,&D); ans=0;
        for (i=1; i<=min(B,D); i++) ans=(ans+CC(D,i)*A[B][i][C])%MOD;
        printf("%d\n",ans);
    }
    return 0;
}
