/*��ǰ��ȡ�ʹ�ǰһ��ȡ��ȡ��ѡ���š�
��ǰȡ����ǰһ�����Բ�ȡ��Ҳ����ȡ��ǰһ��ȡ�ַ����֣�һ��i��i-1����һ�𣬶���i�Գ�һ�������С�
*/
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[1000006][4][2],n,a[1000006];
int main(){
//    freopen("jx.in","r",stdin);
//    freopen("jx.out","w".,stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(f,128,sizeof(f)); f[0][0][0]=0;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=3;j++){
            f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1]);//��ǰ��ȡ�ʹ�ǰһ��ȡ��ȡ��ѡ����
            if (j-1>=0) f[i][j][1]=max(f[i-1][j-1][0]+a[i],f[i-1][j-1][1]+a[i]);
            //��ǰȡ����ǰһ�����Բ�ȡ��Ҳ����ȡ��
            f[i][j][1]=max(f[i][j][1],f[i-1][j][1]+a[i]);
           //ǰһ��ȡ�����֣�һ��i�Գ�һ�������У�����i��i-1����һ��
        }
    printf("%d",max(f[n][3][0],f[n][3][1]));
    fclose(stdin); fclose(stdout);
    return 0;
}
