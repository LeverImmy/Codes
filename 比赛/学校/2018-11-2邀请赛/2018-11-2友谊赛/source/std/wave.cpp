#include <bits/stdc++.h>
using namespace std;

long long gao(vector<int> vec) {
    int sz = vec.size();
    set<int>st;
    long long ans = 0;
    for (int i = sz-1; i >= 0; i--) {//���ŷ���
        set<int>::iterator it = st.lower_bound(vec[i]);
        if (it == st.begin()) {//�����ǰ����������е�С��˵����һ���϶������Ǵ����Լ�ȫ����ͼ��
            ans += vec[i];
        } else {
            it--;
            ans += vec[i] - *it;//ͼһ
        }
        st.insert(vec[i]);
    }
    return ans;
}
int main() {
	freopen("wave.in","r",stdin);
	freopen("wave.out","w",stdout);
    int n;
    while(scanf("%d", &n) == 1) {
        vector<int>vec1, vec2;
        int x,y;
        while(n--) {
            scanf("%d%d", &x, &y);
            vec1.push_back(x);
            vec2.push_back(y);
        }
        cout<<gao(vec1) + gao(vec2)<<endl;
    }
}
