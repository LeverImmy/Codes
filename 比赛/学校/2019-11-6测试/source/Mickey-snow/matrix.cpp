#include<bits/stdc++.h>

constexpr auto MAXN = 401;
constexpr auto MAXM = 401;
constexpr auto MAXS = 401;

int val[MAXN][MAXM], weight[MAXN][MAXM];
int D[MAXN][MAXM][MAXS];

signed main(void)
{
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    
    int totLine,totList,totPack;

    scanf("%d%d%d", &totLine,&totList,&totPack);
    for(int i=0;i<totLine;i++)
        for(int j=0;j<totList;j++) scanf("%d", weight[i]+j);
    for(int i=0;i<totLine;i++)
        for(int j=0;j<totList;j++) scanf("%d", val[i]+j);

    for(int k=totPack;k>=**weight;k--) D[0][0][k] = D[0][0][k-**weight]+**val;
    for(int i=0;i<totLine;i++)
        for(int j=0;j<totList;j++)
            for(int k=totPack;k>=0;k--){
                if(i>0) D[i][j][k] = D[i-1][j][k];
                if(j>0) D[i][j][k] = std::max(D[i][j][k], D[i][j-1][k]);
                if(k>=weight[i][j]){
                    if(i>0) D[i][j][k] = std::max(D[i][j][k], D[i-1][j][k-weight[i][j]]+val[i][j]);
                    if(j>0) D[i][j][k] = std::max(D[i][j][k], D[i][j-1][k-weight[i][j]]+val[i][j]);
                }
            }

    int ans = 0;
    for(int i=0;i<=totPack;i++) ans = std::max(ans, D[totLine-1][totList-1][i]);
    printf("%d\n", ans);
    
    return 0;
}
