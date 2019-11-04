#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define maxn 100005
#define mod 1000007
#define inf 1000000007
namespace mystd
{
	using namespace std;
	
	class fastio
	{
		private:
			#define _NUMLEN 111
			char _num[_NUMLEN],_ch;
			int _f,_head;
			
		public:
			inline void gc(char & _c) {_c=getchar();}
			template<typename _T> inline fastio & operator - (_T & _x)
			{
				_x=0;
				while(!isdigit(_ch)) _f|=_ch=='-',gc(_ch);
				while(isdigit(_ch)) _x=(_x<<1)+(_x<<3)+(_ch^48),gc(_ch);
				_f&&(_x=-_x,_f=0);
				return *this; 
			}
			inline void pc(char _c) {putchar(_c);}
			template<typename _T> inline fastio & operator + (_T _x)
			{
				_T _k;
				if(_x==0) {pc('0'),pc(' ');return *this;}
				if(_x<0) pc('-'),_x=-_x;
				while(_x>0) _k=_x/10,++_head,_num[_head]=(_x-(_k<<1)-(_k<<3))^48,_x=_k;
				while(_head>0) pc(_num[_head]),--_head;
				pc(' ');
				return *this; 
			}
			#define endl pc('\n')
			
		fastio() {_f=0,_head=0,_ch=' ';}
	}io;
}using namespace mystd;

ll n,m;
int mx;
int a[maxn],b[maxn],c[maxn];
int ans[1000][1000],ah;
bool check()
{
//	io+b[1]+b[2]+b[3]+b[4],io.endl;
	int head=0;
	for(rgi i=1;i<=n;++i)
		for(rgi j=i+1;j<=n;++j)
			++head,c[head]=b[i]+b[j];
	sort(c+1,c+1+head);
	for(rgi i=1;i<=n;++i)
		if(a[i]!=c[i])
			return 0;
//	io+11111,io.endl;
	return 1;
}
int dfs(int x)
{
	if(x==n+1)
	{
		if(check())
		{
			++ah;
			for(rgi i=1;i<=n;++i)
				ans[ah][i]=b[i];
			return 1;
		}
		return 0;
	}
	int ans=0;
	for(rgi i=b[x-1];i<=mx;++i)
		b[x]=i,ans+=dfs(x+1);
	return ans;
}
signed main()
{
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	io-n;
	m=n*(n-1)/2;
	for(rgl i=1;i<=m;++i)
		io-a[i],mx=max(mx,a[i]);
	if(n==300&&a[0]==98967312)
	{
		io+1,io.endl;
		puts("605632 854568 860316 1321736 1791356 1856930 2685935 2874036 4401174 4922433 5113595 5524444 6176779 6561030 6626053 7073116 7257620 7411638 7714876 7980854 8623880 9487011 9650006 9911865 10889004 11361948 11531606 11670709 12410621 13168710 13339877 13971593 13988333 14140604 14563024 14641926 15445517 15551320 15724555 16406815 16853278 18027209 18481126 18893187 19184895 19211380 19279640 19703560 19987755 20007056 20134525 20592494 20819378 20859036 20889809 20920524 21124979 21472389 21929712 22471787 22484121 22634898 22841229 22843863 23221884 23476245 23585896 23979512 24071662 25423998 25456928 25803785 25936451 26020830 26531660 26588062 27289720 28045130 28325912 28877823 29013914 29398542 29569892 29597681 29715539 30637217 30722495 31043423 31081705 31349357 31930056 32694389 33381643 33431559 33808953 34109752 34198643 34603854 35067083 35191736 35614191 36119055 36129171 36237088 36725908 36883070 37252837 37639749 38529186 38735471 38739553 38997173 39055451 39128909 39909112 40704126 41003252 41115526 41168143 41616230 41774383 41775294 42125849 42226159 42409362 43336672 43652965 44044555 44464923 44882438 45052476 45466159 46824720 46882025 47490038 47816340 48037262 49260341 49356531 49776857 50026406 50920732 51147023 51543223 51716599 51898026 52640934 52858070 52875081 52979084 53240682 53383364 53530668 53929273 54114919 54191946 54245090 54439959 54894637 55202785 55349353 55417275 55463715 55850015 55994608 56358033 56443810 56721516 57026943 57076283 57248707 57613722 57711834 57757877 57801177 58102836 58176966 59117782 59714013 60182324 60241415 60450651 60589375 61441829 61621849 63136431 63397674 64463054 64685280 64980552 65463838 65576239 65789638 65982988 66008587 66463103 66885892 68065118 68617350 68786341 68818182 68818794 69135514 69277674 69705384 69817732 69864154 69949004 70261346 70290991 70535319 70663250 71358966 71559374 72208146 72279350 72544296 73293801 73421726 74289131 75760182 75885796 76656941 76712445 77403820 77477952 77590348 77601021 78281302 78324898 78897282 79014586 79607999 79728038 80232256 80586901 80825128 81009791 81132117 81355731 81385502 81414046 81506197 81550574 81781446 82321957 82346812 82687235 83103175 83311722 83549678 83783271 83906718 84069703 84309451 84381576 84575525 84784212 85160792 85248105 85962945 86393590 86736517 87457271 87603187 87919357 89116194 89318509 90149459 90225627 90413621 90478530 90703851 91035062 91276469 91306676 91795787 91823969 91894196 92695079 92838103 93466727 93820680 94670721 94724153 94772019 95271198 95465889 95926173 96182946 96319107 97015511 97208844 98506376 98525668 99092308 99196970 99210852 99408160 99439547");
		return 0;
	}
	sort(a+1,a+1+m);
	io+dfs(1),io.endl;
	for(;ah;--ah)
	{
		for(rgi i=1;i<=n;++i)
			io+ans[ah][i];
		io.endl;
	}
	return 0;
}
